#include <assert.h>
#define DIM 20
#define LIMTEST 
main() {
 int i,array[DIM];
 for (i=0; i<=20; i++) {
#ifdef LIMTEST
 assert(i<DIM);
#endif
 array[i]=i*i;
 }
}
