#include <stdio.h>
float rnorm(void);
main() {


  int N=200,ntrial=5000,k,j,i;
  float sum,max=0.0,div=0.0,array[200];
  //int k,j,i;
  for (k=1; k<=N; k++) {
                        sum=0.0;
                  for (j=0; j<ntrial; j++){
			array[0]=rnorm();
		        max = array[0];
                 	 for (i=1; i<N; i++){
		            //printf("%f\n",rnorm());
		             array[i]=rnorm();
		             //max = array[0];
		             if ( array[i] > max){
		                max=array[i];
		                                  }
		             //return(max);
		                             }
                          sum+=max;


                                        }
         div = sum/ntrial ;
         printf(" N = %d  and Average Maximum value = %f\n",k,div);
                      }
}
