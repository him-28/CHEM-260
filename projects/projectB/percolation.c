#include<stdio.h>
float rnorm(void);
int a,n,j,k;
float i;
float count[10][10];

int numberOfPaths(int m, int n)
{
 
       int i,j,count[m][n];
  
    for (i = 0; i < m; i++)
     count[i][0] = 1;
 
    for ( j = 0; j < n; j++)
        count[0][j] = 1;
 
 
 
    for ( i = 1; i < m; i++)
    {
        for ( j = 1; j < n; j++)
 
 
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
 
    }
    return count[m-1][n-1];
}

main()
{
 
 printf("\n Enter the number of cells:");
 scanf("%d",&a);
 printf("\n Enter the number of trials:\n");
 scanf("%d",&n);
for(i=0.0;i<=1.0;i+=0.1){
  for(j=0;j<n;j++)
  {
 int c=0;
   count[a][a]=rnorm();
   if(count[a][a]==1)
    continue;
  }

k = numberOfPaths(a,a);
 printf(" Density =%f Probability =%f \n",i,k/n);
} }
