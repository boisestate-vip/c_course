
#include <stdio.h>

int main(void) {

   int a = 1;
   while (a <= 5) {

      printf("a : %d\n",a);

      a = a + 1;
   }

   for (int b = 1; b <= 5; b = b + 1) {
      printf("b : %d\n",b);
   }

   return 0;
}
