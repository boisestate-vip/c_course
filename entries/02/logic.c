
#include <stdio.h>

int main(void) {

   int a = 1 == 2;
   printf("1 == 2 : %d\n",a);
   int b = 1 == 1;
   printf("1 == 1 : %d\n",b);
   int c = 1 > 2;
   printf("1 > 2 : %d\n",c);
   int d = 1 < 2;
   printf("1 < 2 : %d\n",d);
   int e = 3 > 3;
   printf("3 > 3 : %d\n",e);
   int f = 3 >= 3;
   printf("3 >= 3 : %d\n",f);
   int g = 3 != 3;
   printf("3 != 3 : %d\n",g);
   int h = 3 != 4;
   printf("3 != 4 : %d\n",h);

   int i = 1 && 1;
   printf("1 && 1 : %d\n",i);
   int j = 1 && 0;
   printf("1 && 0 : %d\n",j);
   int k = 1 || 1;
   printf("1 || 1 : %d\n",k);
   int l = 1 || 0;
   printf("1 || 0 : %d\n",l);
   int m = 0 || 0;
   printf("0 || 0 : %d\n",m);
   int n = 0 || 0 || 0 || 0 || 1;
   printf("0 || 0 || 0 || 0 || 1: %d\n",n);
   int o = 1 && 1 && 1 && 1 && 0;
   printf("1 && 1 && 1 && 1 && 0: %d\n",o);


   return 0;
}
