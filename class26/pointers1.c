#include <stdio.h>
main() {
 int i=10;
 float x=100.;
 printf("i is at memory address %p and has the value %d\n",&i,i);
 printf("x is at memory address %p and has the value %f\n",&x,x);
}
