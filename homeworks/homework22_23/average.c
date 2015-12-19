#include <stdio.h>
main() {
int n,i;
	printf ("Enter number of inputs : ");
	scanf("%d", &n);

	double avg = 0.0, inp;
	for ( i = 0; i < n; i++) {
		scanf("%lf" , &inp);
		avg+= inp;
	}

	printf("Average: %lf \n", avg/n );
 
 }
