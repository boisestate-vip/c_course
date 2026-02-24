
#ifndef ARRAY

#define ARRAY

/* this array will only hold integers
 * Later we will work out some generic
 * arrays that let us hold anything.  */

struct array {
   /* position of the next value in the array */
   int next;

   /* amount of memory currently allocated to the array */
   int length;

   /* malloced array of memory */
   int * values;
};

/* setup the array for use */
void init_array(int start_size, struct array * arr);

/* free all memory used by the array */
void destroy_array(struct array * arr);

/* get a value at the given array index 
 *
 * because this is C we won't handle any kind of errors :) */
int get_array(int idx, struct array * arr);

/* add a value to the end of the array 
 *
 * the array should grow with values being added.
 *
 * I will hint that the call you want to start
 * the array with is malloc. 
 *
 * When next == length, you should use something 
 * like realloc to grow the size of the array.
 */
void append_array(int val, struct array * arr);

/* always nice to have */
void print_array(struct array * arr);

/* a bit of fun with macros */
#define ARRAY_FOREACH(iterval, arr, body)                                                  \
do {                                                                                       \
   for (int __array_foreach_i = 0; __array_foreach_i < (arr)->next; ++__array_foreach_i) { \
                                                                                           \
      int iterval = (arr)->values[__array_foreach_i];                                      \
                                                                                           \
      body                                                                                 \
   }                                                                                       \
} while(0)

#endif
