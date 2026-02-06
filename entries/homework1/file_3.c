
#include <stdio.h>
#include <limits.h>

/* pretend that you are on a new computing system
 * that does not use any conventional numerical
 * representation and does not have the limits.h
 * header.
 *
 * Write a program that prints the maximum positive
 * representable number for each type (char, short, unsigned short, ...)
 * in order of height.
 *
 * You should be able to do this with a loop and an if
 * check that terminates and prints a number at a certain
 * point. Take advantage of the behavior we observed with
 * the numbers 'overflowing'. Do not just find the numbers
 * and print them. Use a loop to compute the limits.
 */

void print_limits() {
}

int main(void) {

   print_limits();

   /* expected output will be this: */
   printf("%lld\n",CHAR_MAX);
   printf("%lld\n",UCHAR_MAX);
   printf("%lld\n",SHRT_MAX);
   printf("%lld\n",USHRT_MAX);
   printf("%lld\n",INT_MAX);
   printf("%lld\n",UINT_MAX);
   printf("%lld\n",LONG_MAX);
   printf("%lld\n",ULONG_MAX);
   printf("%lld\n",LLONG_MAX);
   printf("%lld\n",ULLONG_MAX);

   return 0;
}
