#include <stdio.h>
main() {
 int A[10];
 int *Aptr1, *Aptr2;
 Aptr1=A;
 Aptr2=&A[0];
 printf("Aptr1=%p Aptr2=%p\n",Aptr1,Aptr2);
} 
