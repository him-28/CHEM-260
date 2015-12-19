#include <stdio.h>
#include <string.h>
main() {
  char str1[100],str2[100];
  printf("Enter a string up to 100 chars spaces okay\n");
  /* Add line here */
fgets(str2,100,stdin); 
  printf("Here is your string: %s\n",str2);
  printf("Enter a string up to 100 chars no spaces\n");
  /* Add line here */
scanf("%s",str1); 
  printf("Here is your string: %s\n",str1);
}
    
    
