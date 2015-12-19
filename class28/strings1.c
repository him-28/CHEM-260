#include <stdio.h>
main() {
 char *str1="Spring Literal";
 char str2[]="Spring Array";
  str1[1]='t';  /* This will fail on some computers */
 str2[1]='t'; /* This will work */
 printf("%s\n%s\n",str1,str2);
} 
