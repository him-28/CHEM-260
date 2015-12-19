#include <stdio.h>
main() {
 int i=10;
 float x=100.;
 int *iptr; /* Can hold a pointer to an int */
 float *xptr; /* Can hold a pointer to a float */
 iptr=&i;
 xptr=&x;
 *iptr=20;
 *xptr=30.0;
 printf("i is at memory address %p and has the value %d\n",iptr,*iptr);
 printf("x is at memory address %p and has the value %f\n",xptr,*xptr);
} 
