#include <stdio.h>
main() {
  int arr1[10];
  int arr2[10][10];
  int arr3[10][10][10];
  int i,j,k;

  for (i=0; i<10; i++) {
    arr1[i]=i;
    for (j=0; j<10; j++) {
      arr2[i][j]=j*10+i;
      for (k=0; k<10; k++) {
	arr3[i][j][k]=k*100+j*10+i;
      }
    }
  }
  while (1) {
    printf("Enter i, j, and k (all<10): ");
    scanf("%d %d %d",&i,&j,&k);
    if (i>=10 || j>=10 || k>=10) {
      printf("Oops, they have to be less than 10\n");
      continue;
    }
    printf("arr1[%d]=%d\n",i,arr1[i]);
    printf("arr2[%d][%d]=%d\n",i,j,arr2[i][j]);
    printf("arr3[%d][%d][%d]=%d\n",i,j,k,arr3[i][j][k]);
  }
}

