#include <stdio.h>
#include <stdlib.h>
main() {
  int **A, M, N, index, i, j;
  M=8; N=7;
  /* Add 1 line */
  if (A==NULL) {
    printf("Failed to allocate memory for A\n");
    exit(1);
  }
  /* Add 3 lines */
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      A[i][j]=i*100+j*10;
    }
  }
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      printf("A[%d][%d]=%3d\n",i,j,A[i][j]);
    }
  }
}
