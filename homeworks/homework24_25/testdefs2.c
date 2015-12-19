#include <stdio.h>
#include <assert.h>
#define DEBUG
main() {
int n,i;
        printf ("Enter first number : ");
        scanf("%d", &n);
        printf ("Enter second number : ");
        scanf("%d", &i);
        #ifdef DEBUG
        assert(n==i);
	#endif	
        printf ("First number : %d \n",n);
        printf ("Second number : %d \n",i);     
     
     
     
 }
    
