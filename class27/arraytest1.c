#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 4
main() {
  int *A, B[M][N], index, i, j;
  A=(int*)malloc(M*N*sizeof(int));
  if (A==NULL) {
    printf("Trouble, could not allocate A\n");
    exit(1);
  }
  /* Insert 7 lines here */
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      index=i*N+j;
      printf("B[%d][%d]=%3d  A(%d,%d)=>A[%2d]=%3d\n",i,j,B[i][j],i,j,index,A[index]);
    }
  }
}
