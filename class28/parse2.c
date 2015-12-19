#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main() {
  char line[100];
  int day, month, year;
  float pH;
  while(fgets(line,100,stdin)) {
    if (strstr(line, "pH:")) {
      /* add 5 lines here */
	day=atoi(strtok(line," /"));
 month=atoi(strtok(NULL," /"));
 year=atoi(strtok(NULL," /"));
 strtok(NULL," /"); /* Skip "pH:" */
 pH=atof(strtok(NULL," /")); 
      printf("day=%2d month=%2d year=%d pH=%5.2f\n",day,month,year,pH);
    }
  }
}
    
    
