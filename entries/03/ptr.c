
#include <stdio.h>

int main(void) {

   int k = 5;
   int x = 1;
   int z = 2;

   struct a {
      int x;
      int y;
      float z;
   } a;

   struct a * aa = &a;
   int * b = aa;

   int * y = &x;
   int * kk = &k;
   printf("%d\n", *y);
   printf("%d\n", *(y-1));

   a.x = 10;
   a.y = 16;
   a.z = 24.5;
   printf("%d\n", b[2]);

   return 0;
}
