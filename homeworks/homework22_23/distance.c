#include <stdio.h>
#include <math.h>

int main ()
{
	printf ("Enter point 1: ");
      	int i;
	double dist = 0;
	double avg1[3], avg2[3];
	for ( i = 0; i < 3; i++) scanf("%lf" , &avg1[i]);	

	printf ("Enter point 2: ");
	for ( i = 0; i < 3; i++) scanf("%lf" , &avg2[i]);
		
	for ( i = 0; i < 3; i++) {
		double temp = avg1[i] - avg2[i];
		temp = pow(temp,2);
		dist+= temp;
	}

	printf("Distance: %lf\n", pow(dist,0.5));
}
