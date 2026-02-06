
#include <stdio.h>

int main(void) {

   char * hello = "hello\n";

   char hello_array[] = { 'h', 'e', 'l', 'l', 'o', '\n', '\0' };

   printf(hello);
   printf(hello_array);

   /*
   printf("%c \n",hello[0]);
   printf("%c \n",hello_array[0]);
   */

   /*
   for (int i = 0; i < 7; ++i) {

      printf("%d ",hello[i]);

   }
   printf("\n");
   */

   int arr[] = { 1, 2, 3, 4, 3, 2, 1 };

   int i = 0;
   while (i < 7) {

      printf("%d \n",arr[i]);

      i = i + 1;
   }

   return 0;
}
