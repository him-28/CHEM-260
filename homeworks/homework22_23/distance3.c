#include <stdio.h>
#include <math.h>

int main ()
{
	int i;
	//printf ("Enter number of inputs : ");
	//scanf("%d", &n);

	printf ("Enter point 1: ");
	
	double dist = 0;
	double avg1[100], avg2[100];
	for ( i = 0; ; i++) {scanf("%lf" , &avg1[i]);	
    	break;}
	printf ("Enter point 2: ");
	for ( i = 0; ; i++){ scanf("%lf" , &avg2[i]);
	break;	}
	for ( i = 0; ; i++) {
		double temp = avg1[i] - avg2[i];
		temp = pow(temp,2);
		dist+= temp;
	}

	printf("Distance: %lf\n", pow(dist,0.5));

}
