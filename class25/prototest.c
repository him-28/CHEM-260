#include <stdio.h>
 int add(int, int);  /* Function prototype */
main() {
 int i=10, j=15;
 printf("%d+%d=%d\n",i,j,add(i)); /* Note error */
}
int add(int a, int b) {
 return a+b;
}
