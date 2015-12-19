#include <stdio.h>
#include <math.h>

int main ()
{
	int i,n;
	printf ("Enter number of inputs : ");
	scanf("%d", &n);

	printf ("Enter point 1: ");
	
	double dist = 0;
	double avg1[n], avg2[n];
	for ( i = 0; i < n; i++) scanf("%lf" , &avg1[i]);	

	printf ("Enter point 2: ");
	for ( i = 0; i < n; i++) scanf("%lf" , &avg2[i]);
		
	for ( i = 0; i < n; i++) {
		double temp = avg1[i] - avg2[i];
		temp = pow(temp,2);
		dist+= temp;
	}

	printf("Distance: %lf\n", pow(dist,0.5));

}
