#include <stdlib.h>
int *bfunc(void);
main() {
 int *vals, *vals2;
 vals=bfunc();
 printf("%d %d\n",vals[0],vals[1]);
 vals2=bfunc();
 printf("%d %d\n",vals[0],vals[1]);
}
int *bfunc(void) {
 int data[2];
 data[0]=rand(); data[1]=rand();
 return data; /* Returns pointer to data array */
} 
