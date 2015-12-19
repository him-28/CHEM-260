#include <stdio.h>
main() {
 int i=10;
 double *x;
 x =(double *)malloc(1000*sizeof(double));
 int *iptr; /* Can hold a pointer to an int */
 float *xptr; /* Can hold a pointer to a float */
 iptr=&i;
 xptr=&x;
 printf("i is at memory address %p and has the value %d\n",*iptr,*iptr);
 printf("x is at memory address %p and has the value %n \n",xptr,x);
} 
