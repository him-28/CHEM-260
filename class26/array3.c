#include <stdio.h>
main() {
 char c[3];
 int i[3],j;
 printf("c=%p &c[0]=%p i=%p &i[0]=%p\n",c,&c[0],i,&i[0]);
 for (j=0; j<3; j++) {
 printf("&c[%d]=%p &i[%d]=%p\n",j,&c[j],j,&i[j]);
 }
}
