#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
 int i,ran,n=10,high=0,low=0;
 time_t t;
 srand((unsigned) time(&t));
 for (i=0; i<100000000; i++) {
 ran=rand()%n;
 if (ran < 2) low++;
 if (ran > 7) high++;
 }
 printf("Low=%d High=%d\n",low,high);
} 
