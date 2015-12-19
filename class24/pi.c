#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mtwist.h"
main() {
  long ntrials=100000000;
  long inside=0;
  long inside_mt=0;
  long i;
  clock_t begin, end;
  double x, y, pi, pi_mt, seconds, error, error_mt;
  mt_seed();
  mt_seed32new(1000);
  srand(time(NULL));
  begin=clock();
  for (i=0; i<ntrials; i++) {
    x=rand()/(double)RAND_MAX;    
    y=rand()/(double)RAND_MAX;
    /*printf("%f %f\n",x,y);*/
    if (x*x+y*y < 1) {
      inside++;
    }
    x=mt_drand();
    y=mt_drand();
    /*printf("%f %f\n",x,y);*/
    if (x*x+y*y < 1) {
      inside_mt++;
    }
  }
  pi=4.*(double)inside/(double)ntrials;
  pi_mt=4.*(double)inside_mt/(double)ntrials;
  error=fabs(pi-M_PI);
  error_mt=fabs(pi_mt-M_PI);
  end=clock();
  seconds=(double)(end-begin)/CLOCKS_PER_SEC;
  printf("Error(rand): %lf Error(mt):%lf\n",error, error_mt);
}

