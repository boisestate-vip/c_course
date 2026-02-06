
#include <stdio.h>

int main(void) {

   int a = 1;
   int b = 1;

   printf(" 1 + 1 : %d\n", a + b);

   a = a + b;

   printf(" 1 + 1 : %d\n", a);

   printf(" 1 + 2 : %d\n", a + b);

   printf(" 1 - 2 : %d\n", b - a);

   printf(" 2 - 1 : %d\n", a - b);

   a = a + a;
   b = b + a;

   printf(" 4 * 5 : %d\n", a * b);
   printf(" 4 * 5 : %d\n", 4 * 5);

   a = a * b;
   b = b * a;

   printf(" 4 * 5 * 5 : %d\n",b);

   printf(" 100 / 4 : %d\n",b / 4);
   printf(" 100 / 5 : %d\n",b / 5);
   printf(" 100 / 7 : %d\n",b / 7);

   printf(" (100 / 7) * 7 : %d\n", (b / 7) * 7);

   printf(" 100 %% 7 : %d\n", b % 7);

   printf(" (100 / 7) * 7 + (100 %% 7) : %d\n", (b / 7) * 7 + (b % 7));

   return 0;
}
