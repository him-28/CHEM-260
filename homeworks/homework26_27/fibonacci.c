#include <stdio.h>
#include <stdlib.h>
int main ()
{  
	FILE *intfile;
	int *realfile;

	int i, lastNumber=1,secondLast=0,currentNumber=0,counter;


	/* read integer values from "integer.file" */
	printf ("The integers from 'input.txt' follow:\n");
	intfile = fopen ("input.txt", "r");  /* open file for reading */
        //realfile = new [sizeof(intfile); 
	
	FILE *outputfp;
	
	outputfp=fopen("output.txt","w");
	if (outputfp==NULL) {
		printf("Trouble, could not open output.txt\n");
		exit(1);
	}

	while (fscanf (intfile,"%d",&i) != EOF)
	/* continue until scanf returns EOF */
	{
		realfile = (int*) malloc(i*sizeof(int));
		printf("%d\n",i);
		fprintf(outputfp,"upto %d series => ",i);
		for(counter = 0; counter < i ; counter++){
			realfile[counter] = fib(counter);
			//printf ("%10d = %d \n", i,realfile[counter]);
			fprintf(outputfp,"%d ", realfile[counter]);
		}
		free(realfile);
		fprintf(outputfp,"\n");
	}

//	fclose (intfile);
	printf ("Integer file processed\n");

	return 0;
}

int fib(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	else return (fib(x-1) + fib(x-2));
}
