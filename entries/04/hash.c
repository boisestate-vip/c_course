
#include <stdlib.h>
#include <string.h>
#include "hash.h"

uint32_t fnv1_a(void * data, uint32_t len) {

   uint32_t hash = 0x811c9dc5;

   for (int i = 0; i < len; ++i) {
      hash ^= ((char *)data)[i];
      hash *= 0x01000193;
   }

   return hash;
}

void init_hash(int size, struct hash * h) {

   h->size = size;
   h->count = 0;

   int arr_len = sizeof(struct hash_entry) * size; 

   h->entries = malloc(arr_len);

   memset(h->entries, 0, arr_len);
}

void destroy_hash(struct hash * h);

void add_hash(void * key, uint32_t keylen,
              void * val, hash * h) {

   uint32_t idx = fnv1_a(key,keylen) % h->size;

   struct hash_entry * bin = &h->entries[idx];

   if (bin->key == NULL) {
      /* empty bin! */
      bin->key = key;
      bin->keylen = keylen;
      bin->val = val;

      h->count += 1;
   }
   else {

      do { 
         if (bin->keylen == keylen &&
             memcmp(bin->key,key,keylen) == 0) {

            bin->val = val;

            return;
         }
      } while (bin->next != NULL && (bin = bin->next));

      hash_entry * new_bin = malloc(sizeof(hash_entry));
      memset(new_bin, 0, sizeof(hash_entry));

      new_bin->key = key;
      new_bin->keylen = keylen;
      new_bin->val = val;

      bin->next = new_bin;

      h->count += 1;
   }
}

int get_hash(void * key, uint32_t keylen,
             void ** val, hash * h) {
   uint32_t idx = fnv1_a(key,keylen) % h->size;

   struct hash_entry * bin = &h->entries[idx];

   if (bin->key == NULL) {
      /* empty bin! */
      return 0;
   }
   else {

      do { 
         if (bin->keylen == keylen &&
             memcmp(bin->key,key,keylen) == 0) {

            *val = bin->val;

            return 1;
         }
      } while (bin->next != NULL && (bin = bin->next));

      return 0;
   }
}

void * rem_hash(void * key, uint32_t keylen, hash * h) {
   uint32_t idx = fnv1_a(key,keylen) % h->size;

   struct hash_entry * bin = &h->entries[idx];

   if (bin->key == NULL) {
      /* empty bin! */
      return NULL;
   }
   else {

      if (bin->keylen == keylen &&
          memcmp(bin->key,key,keylen) == 0) {

         void * retval = bin->val;

         if (bin->next != NULL) {

            struct hash_entry * ne = bin->next->next;
            bin->val = bin->next->val;
            bin->key = bin->next->key;
            bin->keylen = bin->next->keylen;
            
            free(bin->next);
            bin->next = ne;

            return retval;
         }
         else {
            void * retval = bin->val;
            memset(bin,0,sizeof(hash_entry));
            return retval;
         }
      }

      struct hash_entry * prev = bin;
      bin = bin->next;

      while (bin != NULL) {

         if (bin->keylen == keylen &&
             memcmp(bin->key,key,keylen) == 0) {

            void * retval = bin->val;

            prev->next = bin->next;
            free(bin);

            return retval;
         }

         prev = bin;
         bin = bin->next;
      }

      return NULL;
   }
}
