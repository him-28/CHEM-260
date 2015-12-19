#include <stdio.h>
void change(int *, int);
main() {
 int i=10, j=20;
 change(&i, j); /* Passing in i pointer and j value*/
 printf("After change, i=%d, j=%d\n",i,j);
}
void change(int *a, int b) {
 *a=44;
 b=55;
} 
