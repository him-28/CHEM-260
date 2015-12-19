#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
main() {
 //char *str1="Spring Literal";
 char str2[]="Hi";
 int n = sizeof(str2);
 /* str1[1]='t'; */ /* This will fail on some computers */
 //str2[1]='t'; /* This will work */
 printf("%d Size of array = %d\n",strlen(str2),n);
 //printf("%s\n",strstr("Fe fi fo fum","fo"));
 printf("%s\n",strtok("fe;fi;fo;fum",";"));
} 
