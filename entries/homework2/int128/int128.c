
#include <math.h>
#include <string.h>
#include "int128.h"

int128 add_int128(int128 a, int128 b) {
   return (int128){};
}

int128 sub_int128(int128 a, int128 b) {
   return (int128){};
}

int128 mul_int128(int128 a, int128 b) {
   return (int128){};
}

/* for this I will use long division.
 * There are more complex division
 * algorithms, but this one is fast
 * enough for what we are doing.    
 *
 * https://en.wikipedia.org/wiki/Division_algorithm#Integer_division_(unsigned)_with_remainder
 */
#define bit_at(i, v) \
   ((i) > 64 ? (((v).high>>((i)-64))&1) : (((v).low>>i)&1))
#define set_bit_at(i, x, v) \
   ((i) > 64 ? ((v).high|=((x&1)<<((i)-64))), 
#define lsh_int128(x)   \
do {                    \
    x.high <<= 1;       \
    if (x.low&(1L<<63)) \
      x.high |= 1;      \
    x.low <<= 1;        \
} while (0)
int128 div_int128(int128 num, int128 den) {

   if (den.low == 0 && den.high == 0)
      return (int128){INFINITY,INFINITY};

   int sign = (num.high < 0 ? -1 : 1) * (den.high < 0 ? -1 : 1);
   int128 res;
   memset(&res,0,sizeof(int128));

   for (int i = 126; i >= 0; --i) {

      lsh_int128(res);
      int num_bit = bit_at(i,num);
      res.low |= num_bit;

      if (res.high >= den.high ||
          (res.high == den.high && res.low >= den.low)) {

         res = sub_int128(res,den);
      }
   }

   return res;
}

int128 mod_int128(int128 a, int128 b) {
   return (int128){};
}

char * str_int128(int128 a) {
}

char * hex_int128(int128 a) {
}

int128 __init_int128(char * val) {
}

int128 __init_int128_hex(char * val) {
}
