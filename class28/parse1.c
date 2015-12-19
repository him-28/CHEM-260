#include <stdio.h>
#include <string.h>
main() {
 char line[100];
 FILE* inputfp;
 inputfp=fopen("data.txt","r");
 while(fgets(line,100,inputfp)) {
 printf("%s",line);
 }
} 
