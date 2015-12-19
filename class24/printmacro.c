#include <stdio.h>
#define FPRINT(i,j,x) printf("Data(%02d,%02d)=%6.2f\n",i,j,x)
main() {
 int a=92,b=43,c=24,d=14;
 float val1=10.32,val2=41.32;
 FPRINT(a,b,val1);
 FPRINT(c,d,val2);
} 
