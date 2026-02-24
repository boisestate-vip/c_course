
#include "array.h"
#include <stdio.h>

int main(void) {

   struct array a0;
   init_array(5,&a0);

   /* should print an empty array */
   print_array(&a0);

   append_array(4,&a0);
   append_array(5,&a0);
   append_array(6,&a0);

   /* something like this: [ 4, 5, 6 ] */
   print_array(&a0);

   /* should print something similar */
   ARRAY_FOREACH(i,&a0,{
      printf("%d, ",i);
   });
   putchar('\n');

   destroy_array(&a0);

   struct array a1;
   init_array(20,&a1);

   /* now we will cram the array full of values */
   for (int i = 0; i < 250; ++i)
      append_array(i,&a1);

   /* should print an ordered list from 0 to 249 */
   print_array(&a1);

   /* should print something similar */
   ARRAY_FOREACH(i,&a0,{
      printf("%d, ",i);
   });
   putchar('\n');

   destroy_array(&a1);

   return 0;
}
