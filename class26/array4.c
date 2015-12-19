#include <stdio.h>
#include <stdlib.h>
void randset(int *, int); 
main() {
  int a[3], n=3;
  a[0]=0; a[1]=0; a[2]=0;
  randset(a,n);
  printf("a[0]=%d, a[1]=%d, a[2]=%d\n",a[0],a[1],a[2]);
}

void randset(int *in, int nvals) {
 int i;
 for (i=0;i<nvals;i++) {
 in[i]=rand();
 }
}
