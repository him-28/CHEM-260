#include <stdio.h>
#define DIM 10
main() {
  int arr1[DIM];
  int arr2[DIM][DIM];
  int arr3[DIM][DIM][DIM];
  int i,j,k;

  for (i=0; i<DIM; i++) {
    arr1[i]=i;
    for (j=0; j<DIM; j++) {
      arr2[i][j]=j*10+i;
      for (k=0; k<DIM; k++) {
	arr3[i][j][k]=k*100+j*10+i;
      }
    }
  }
  while (1) {
    printf("Enter i, j, and k (all<%d): ",DIM);
    scanf("%d %d %d",&i,&j,&k);
    if (i>=DIM || j>=DIM || k>=DIM) {
      printf("Oops, they have to be less than %d\n",DIM);
      continue;
    }
    printf("arr1[%d]=%d\n",i,arr1[i]);
    printf("arr2[%d][%d]=%d\n",i,j,arr2[i][j]);
    printf("arr3[%d][%d][%d]=%d\n",i,j,k,arr3[i][j][k]);
  }
}

