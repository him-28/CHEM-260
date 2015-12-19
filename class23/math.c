#include <stdio.h>
#include <math.h>
int main(void) {
int i;
double x;
printf("Enter an integer: "); /* Note no "\n" */
scanf("%d",&i);
printf("Here's your integer: %d and its square: %d\n",i,i*i);
printf("Enter a double: ");
scanf("%lf",&x);
printf("Here's your double: %lf and its square root %lf\n",x,sqrt(x));
}
