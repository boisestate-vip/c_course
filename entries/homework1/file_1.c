
#include <stdio.h>

/* write a small version of printf that has its own syntax
 * and is capable of printing integers as well. It should
 * behave as follows:
 *
 * go through the string the user has provided. print the
 * following on each condition:
 *
 * if a $ character is seen, print a newline
 *
 * if a @ character is seen, print the next integer
 * in the array the user has provided. (use printf("%d",num) to do this)
 *
 * if the zero character is encountered, end execution
 *
 * otherwise, print the current character.
 */

void small_printf(char text[], int nums[]) {
}

int main(void) {

   char * sample_1 = "hello";

   // should print:
   // hello
   // with no newline
   small_printf(sample_1,0);

   char * sample_2 = "I have @ cheese and @ butter$";
   int sample_2_nums[2] = { 12, 3 };

   // should print:
   // I have 12 cheese and 3 butter
   // with a newline

   small_printf(sample_2,sample_2_nums);


   return 0;
}
