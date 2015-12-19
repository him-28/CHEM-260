#include <stdio.h>
main() {
 int i[3],j;
 i[0]=10; i[1]=20; i[2]=30;
 for (j=0; j<3; j++) {
 printf("i[%d]=%d &i[%d]=%p i+%d=%p *(i+%d)=%d\n",
 j,i[j],j,&i[j],j,i+j,j,*(i+j));
 }
} 
