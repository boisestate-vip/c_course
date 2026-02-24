
#ifndef INT128

#define INT128

#include <stdint.h>

/* our int type will just
 * be two smaller ints.
 *
 * note that I made the
 * low one signed and the
 * high one unsigned.    */
typedef struct int128 {

   uint64_t low;
   int64_t high;

} int128;

/* these should be straightforward */

int128 add_int128(int128 a, int128 b);
int128 sub_int128(int128 a, int128 b);
int128 mul_int128(int128 a, int128 b);
int128 div_int128(int128 a, int128 b);
int128 mod_int128(int128 a, int128 b);

/* print the value as a hex string */
char * hex_int128(int128 a);

/* convert the provided number to an int128 
 * again, this is a slow way to do it, but
 * faster ways are incredibly complex.     */
#define int128_init_hex(x) \
   __init_int128_hex(#x)

int128 __init_int128(char * val);
int128 __init_int128_hex(char * val);


#endif
