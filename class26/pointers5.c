#include <stdio.h>
main() {
 int *iptr;
 float *xptr;
 *iptr=20; /* Data assigned to unallocated location */
 *xptr=20.0; /* Data assigned to unallocated location */
 printf("i is at memory address %p and has the value %d\n",iptr,*iptr);
 printf("x is at memory address %p and has the value %f\n",xptr,*xptr);
} 
