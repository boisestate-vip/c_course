
#include <stdio.h>

int print(char text[]) {

   int idx = 0;
   while (text[idx] != '\0') {

      char next_char = text[idx];

      putchar(next_char);

   }

   return idx;
}

/*
int int_print(int text[]) {

   for (int idx = 0; text[idx] != 44; idx = idx + 1) {

      if (text[idx] == 57) {

         putchar(10);

      }
      else {

         putchar(97);

      }
   }

   return 4;
}
*/

int main(void) {

   int res = 0;

   res = print("hello there!");
   printf("res: %d\n",res);

   /*
   
   int string[] = { 1, 2, 3, 23, 57, 4, 4, 57, 8, 9, 44 };

   res = int_print(string);
   printf("res: %d\n",res);

   */


   return 0;
}
