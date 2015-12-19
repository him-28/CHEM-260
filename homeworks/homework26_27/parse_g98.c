#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main() {
 char line[100];
 int NBasis=0,RedAO=0,NBF=0;
 double Done;
 FILE *outputfp;
 outputfp=fopen("energies.out","w");
 if (outputfp==NULL) {
 printf("Trouble, could not open output.txt\n");
 exit(1); }
 while(fgets(line,100,stdin)) {
 if (strstr(line, "Done:")) {
 NBasis=atoi(strtok(line," ="));
 RedAO=atoi(strtok(NULL," ="));
 NBF=atoi(strtok(NULL," ="));
 strtok(NULL," /"); /* Skip "pH:" */
 Done=atof(strtok(NULL," =  "));
 printf("day=%2d month=%2d year=%d E=%5.8f\n",NBasis,RedAO,NBF,Done);
 fprintf(outputfp,"Energy=%5.8f\n",Done); 
 //printf("E=%5.6f\n",Done);
 }
 }
}
