
#ifndef __HASH

#define __HASH
#include <stdint.h>

typedef struct hash_entry {
   void * key;
   void * val;
   uint32_t keylen;

   struct hash_entry * next;
} hash_entry;

typedef struct hash {

   struct hash_entry * entries;
   int size;

   int count;

} hash;

uint32_t fnv1_a(void * data, uint32_t len);

void init_hash(int size, struct hash * h);
void destroy_hash(struct hash * h);

void add_hash(void * key, uint32_t keylen, void * val, hash * h);
int get_hash(void * key, uint32_t keylen, void ** val, hash * h);
void * rem_hash(void * key, uint32_t keylen, hash * h);

#endif
