
#include <stdio.h>

int add3(int a, int b, int c) {
   return a + b + c;
}

/* 
int add4(int res, int a, int b, int c) {
   return res + a + b + c;
}
*/

/*
void set_d(int d) {
   d = 4;
}
*/

/*
int add8(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8) {
   int res = add7(s0, s1, s2, s3, s4, s5, s6, s7);
   return res + s8;
}

int add8(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7) {
   int res = add7(s0, s1, s2, s3, s4, s5, s6);
   return res + s7;
}

int add7(int s0, int s1, int s2, int s3, int s4, int s5, int s6) {
   int res = add6(s0, s1, s2, s3, s4, s5);
   return res + s6;
}

int add6(int s0, int s1, int s2, int s3, int s4, int s5) {
   int res = add5(s0, s1, s2, s3, s4);
   return res + s5;
}

int add5(int s0, int s1, int s2, int s3, int s4) {
   int res = add4(s0, s1, s2, s3);
   return res + s4;
}
*/



int main(void) {

   int res = add3(1,2,3);

   printf("res: %d\n",res);

   /*
   int d = 3;
   set_d(d);

   printf("d: %d\n",d);
   */

   //printf("8: %d\n", add8(1,1,1,1,1,1,1,1));

   return 0;
}
