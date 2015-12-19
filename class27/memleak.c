#include <stdio.h>
#include <stdlib.h>
void leak(void);
main() {
  int i;
  for (i=0; i<10000; i++) {
    leak();
  }
}
void leak(void) {
  int *a;
  a=(int *)malloc(1000*sizeof(int));
  if (a==NULL) {
    printf("Failed to allocate memory\n");
    exit(1);
  }
  /* This is a memory leak unless I free a */
  /* free(a); */
  return;
}

