#include <stdio.h>
int main(void) {
 int current, i;
 int last=1;
 int twoback=0;

 printf("F0=%d\n",twoback);
 printf("F1=%d\n",last);

 for (i=2; i<30; i++) {
 current=last+twoback;
 printf("F%d=%d\n",i,current);
 twoback=last;
 last=current;
 }
} 
