
#include <stdio.h>

/* using the min and max functions from
 * the previous examples, write a function
 * that prints out a list of integers in
 * sorted order with the largest first. 
 * This can be done by repeating
 * the same set of operations on the passed
 * array for a total number of times equal to
 * the length of the array.
 *
 * I will give two hints. The first is that
 * you can assign to array indicies, i.e.
 * a[i] = 5 will set the ith index of a to 5.
 *
 * The second hint is that there should be
 * a method you can use to ensure that a number
 * is replaced with one that is a new minimum
 * in the array...
 */

void print_sorted(int arr[], int len) {
}

int main(void) {

   int arr0[13] = { 1, 3, 8, -4, 12, -20, 1, 4, 5, 3, 3, 8, 2 };
   int arr1[4] = { 9, 6, 3, 0 };
   int arr2[5] = {0, 0, 1, 0, 0};
   int arr3[10];

   // should output:
   // 12 8 8 5 4 3 3 3 2 1 1 -4 -20
   print_sorted(arr0,13);

   // should output:
   // 9 6 3 0
   print_sorted(arr1,4);
  
   // should output:
   // 1 0 0 0 0
   print_sorted(arr2,5);

   // not sure what this will output,
   // but it should be sorted :)
   print_sorted(arr3,10);


   return 0;
}
