
#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define STRLEN 5

static char * get_str() {
   char * str = malloc(sizeof(char) * STRLEN);
   for (int i = 0; i < STRLEN; ++i)
      str[i] = rand() % CHAR_MAX;
   return str;
}

int main(void) {

   srand(time(NULL)*clock());

   char * hi = "hi there";

   printf("hash of \"%s\": %d\n",hi,fnv1_a(hi,strlen(hi)));

   int hash_size = 250000 * 4;

   hash h;
   init_hash(hash_size,&h);

   clock_t start_t = clock();

   for (long i = 0; i < 250000; ++i) {

      char * key = get_str();
      add_hash(key,STRLEN,(void *)i,&h);

      long val;
      int success = get_hash(key,STRLEN,(void **)&val,&h);

      /*
      if (success) {
         printf("val: %ld\n",val);
      }
      else {
         printf("\033[31mFAILURE!\033[0m\n");
      }
      */
   }

   clock_t time_diff = clock() - start_t;

   printf("total elapsed: %f\n",(double)time_diff / CLOCKS_PER_SEC);

   return 0;
}
