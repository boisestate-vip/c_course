
#include <stdio.h>

/* write some nice helper functions for
 * math operations.
 *
 * min will take an array and length and return the
 * smallest element.
 *
 * max will do the same but return the largest element.
 *
 * product will do the same but produce the product
 * of the elements.
 *
 * sum will return the sum of the elements.
 *
 * Kind of a boring one but it is a classic :)
 */

int min(int arr[], int len) {
   return 0;
}

int max(int arr[], int len) {
   return 0;
}

int product(int arr[], int len) {
   return 0;
}

int sum(int arr[], int len) {
   return 0;
}

int main(void) {

   int arr[9] = { 1, 5, 7, 3, 4, -2, 8, -9, 1 };

   // returns -9
   printf("min: %d\n",min(arr,9));
   // returns 8
   printf("max: %d\n",max(arr,9));
   // returns 60480
   printf("product: %d\n",product(arr,9));
   // returns 18
   printf("sum: %d\n",sum(arr,9));

}
