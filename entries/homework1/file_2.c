
#include <stdio.h>

/* you can read about the fibonacci sequence here:
 *
 * https://en.wikipedia.org/wiki/Fibonacci_sequence
 *
 * write a function to compute and return it for
 * the number given. Note that I use long long for
 * the return type as numbers will get very large
 * very fast.
 */

long long fib(int input) {

   return 0;
}

int main(void) {

   // should print 0
   printf("%lld\n", fib(0));
  
   // should print 1
   printf("%lld\n", fib(1));
  
   // should print 3
   printf("%lld\n", fib(4));

   // should print 337
   printf("%lld\n", fib(14));
  
   // should print 2178309
   printf("%lld\n", fib(32));
  
   // should print 6557470319842
   printf("%lld\n", fib(63));

   return 0;
}

