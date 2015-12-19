/* C-language translation of Ising_model.py from class 11 */
#define MAXSPIN 50
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

main() {
  double Temp=2.3;     /* Temperature */
  int n=20,*A,index,index1,index2,index3,index4;            /* Sites per edge for n x n system */
  int ntrials=1000000;        /* Number Trials */
  int nequil=500000 ;         /* Equilibration steps */
  int trial, flip, i, j;     /* Loop indices */
  time_t t;
  A=(int*)malloc(n*n*sizeof(int));
  if (A==NULL) {
  printf("Trouble, could not allocate A\n");
  exit(1);
  } 
  /* Initialize sums for averages */
  double E_sum=0.0;
  double E2_sum=0.0;
  double deltaE, E_ave, E2_ave, Cv;
  double energy, spinsum, n2;

  /* Set random seed */
  srand((unsigned) time(&t));
  n2=n*n;

  /* Test to be sure the grid is large enough */
  if (n > MAXSPIN) {
    printf("Trouble, n too large, increase MAXSPIN and recompile\n");
    exit(1);
  }

  /* Create matrix of spins */
  int spins[MAXSPIN][MAXSPIN];
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      index=i*n+j;
      A[index]=1;
    }
  }

  /* Run simulation */
  for (trial=0; trial<(ntrials+nequil); trial++) {
 
    /* Randomly pick a site */
    i=rand()%n;
    j=rand()%n;
    index=i*n+j;
    //  index=i*n+j;
          index1=i*n+((j+1)%n);
          index2=i*n+((j-1+n)%n);
          index3=((i+1)%n)*n+j;
          index4=((i+n-1)%n)*n+j;
          deltaE=2*(A[index]*(A[index1]+A[index2]+
                                A[index3]+A[index4]));


    /* Calculate the change in energy if we flip this spin */
    //deltaE=2*(spins[i][j]*(spins[i][(j+1)%n]+spins[i][(j-1+n)%n]+
//			   spins[(i+1)%n][j]+spins[(i-1+n)%n][j]));

    /* Flip the spin using Metropolis MC */
    if (exp(-deltaE/Temp) > (rand()/(double)RAND_MAX)) {
    A[index]=-A[index];
    } else {
      deltaE=0.0;
    }

    /* Calculate system energy at first production cycle */
    if (trial == nequil) {
      energy=0.0;  
      for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
          index=i*n+j;
          index1=i*n+((j+1)%n);
	  index2=i*n+((j-1+n)%n);
	  index3=((i+1)%n)*n+j;
	  index4=((i+n-1)%n)*n+j;
	  energy-=(A[index]*(A[index1]+A[index2]+
				A[index3]+A[index4]));
	}
      }
      energy/=n2;
    }
    
    /* Increment system energy during production run */
    if (trial > nequil) {
      energy+=deltaE/n2;
      E_sum+=energy;
      E2_sum+=energy*energy;
    }
  }
  E_ave=E_sum/(double)ntrials;
  E2_ave=E2_sum/(double)ntrials;
  Cv=1./(Temp*Temp)*(E2_ave-E_ave*E_ave);
  printf("%8.4lf %10.4lf %10.4lf\n", Temp, E_ave, Cv);
}
