#include <stdio.h>
int swap(int, int);
main() {
 int i, j, val;
 i=10;
 j=20;
 printf("Before swap i=%d j=%d\n",i,j);
 val=swap(i,j);
 printf(" After swap i=%d j=%d\n",i,j);
}
int swap(int i,int j) {
 int temp;
 temp=i;
 i=j;
 j=temp;
 return 1;
}
