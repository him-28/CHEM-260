#include <stdio.h>
#include <string.h>
main() {
  char str1[30]="Between the idea ", str2[20];
  char str3[]="and the reality";
  char str4[]="Punctuation,separates:words; Indeed.";
  char *word;
   strcpy(str2,str1); 
  /* add line here */
  printf("str2='%s'\n",str2);
  /* add line here */
strcpy(str1,str3); 
  printf("str1='%s'\n",str1);
  printf("str4='%s'\n",str4);
  /* add 5 lines here */
word=strtok(str4,",.;: ");
 while (word!=NULL) {
 printf("%s\n",word);
 word=strtok(NULL,",.;: ");
 } 
}
    
    
