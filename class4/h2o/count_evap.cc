/*
Created by Mike Colvin
Modified by Jane Lee 2010.10.10.
Remodified by Mike Colvin 2012.08.20 for use in Chem 260

Reads in a gromacs .gro file and counts water molecules that have evaporated from the droplet

*/

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#define MAX_WATERS 10000
#define MAX_ATOMS 3*MAX_WATERS
//using namespace std;

double dist2(double x1, double y1, double z1, double x2, double y2, double z2);
int compare_doubles(const void *a, const void *b);


/*-------------------- BIGIN main --------------------*/
int main(int argc, char *argv[]){
  double dist_cutoff=1.0;
  double dist_cutoff2=dist_cutoff*dist_cutoff;
  char line[120], commentline[120], boxsize[120], value[8], ivalue[5], evapfile[100], comfilename[100];
  double *OW_x, *OW_y, *OW_z;
  double *HW1_x, *HW1_y, *HW1_z;
  double *HW2_x, *HW2_y, *HW2_z;
  double *OW_vx, *OW_vy, *OW_vz;
  double *HW1_vx, *HW1_vy, *HW1_vz;
  double *HW2_vx, *HW2_vy, *HW2_vz;
  int waternum[MAX_ATOMS], atomnum[MAX_ATOMS];
  int atomtype[MAX_ATOMS]; //0: OW, 1: HW1; 2: HW2
  int total_evap[MAX_ATOMS];
  
  FILE *gro_in, *gro_out, *top_out;

  // Allocate memory for main arrays
  OW_x=(double *)malloc(MAX_WATERS*sizeof(double));
  OW_y=(double *)malloc(MAX_WATERS*sizeof(double));
  OW_z=(double *)malloc(MAX_WATERS*sizeof(double));
  OW_vx=(double *)malloc(MAX_WATERS*sizeof(double));
  OW_vy=(double *)malloc(MAX_WATERS*sizeof(double));
  OW_vz=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_x=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_y=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_z=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_vx=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_vy=(double *)malloc(MAX_WATERS*sizeof(double));
  HW1_vz=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_x=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_y=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_z=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_vx=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_vy=(double *)malloc(MAX_WATERS*sizeof(double));
  HW2_vz=(double *)malloc(MAX_WATERS*sizeof(double));
  //printf("%d\n",argc);
  //printf("%s %s %s\n",argv[0],argv[1],argv[2]);
  //Process command line arguments
  switch(argc) {
  case 2: /* modified by Jane */
    if ((gro_in = fopen(argv[1],"r")) == NULL) {
      fprintf(stderr, "%s:  Cannot open input gro file %s\n", argv[0],argv[1]);
      return(2);
    }
    break;
  default:
    fprintf(stderr, "Usage: %s Input-gro-file\n", argv[0]);
    return(2);
  }

  //Read comment line
  if (!fgets(commentline, 100, gro_in)) {   //Stop if we are at the end of the pdb file
    fprintf(stderr, "Could not read comment line \n", argv[0]);
    return(2);
  }
  //Read number of atoms
  if (!fgets(line, 100, gro_in)) {   //Stop if we are at the end of the pdb file
    fprintf(stderr, "Could not read # atoms line \n", argv[0]);
    return(2);
  }
  int natoms=strtol(line,NULL,10);
  //printf("natoms read in: %d\n",natoms);
  if (natoms > MAX_ATOMS) {
    fprintf(stderr, "Sorry this program only works for less than %d atoms\n",MAX_ATOMS);
    return(2);
  }
  if (natoms%3 !=0) {
    fprintf(stderr, "Number of atoms is not a multiple of 3\n");
    return(2);
  }
  int nwaters=natoms/3;

  int iatoms=0;
  for (int iwater=0; iwater<nwaters; iwater++) {   //loops over each water in the input file
    if (!fgets(line, 120, gro_in)) {   //Stop if we are at the end of the pdb file
      fprintf(stderr, "Error reading atom number %d, expected %d\n", iatoms+1, natoms);
      return(2);
    }
    if (line[5]=='S'&&line[6]=='O'&&line[7]=='L') {
      if (line[13]=='O' and line[14]=='W') {
	strncpy(ivalue,line,5);
	waternum[iatoms]=atol(ivalue);
	if (waternum[iatoms]!=iwater+1) {
	  fprintf(stderr, "Error reading water number %d, expected %d\n", waternum[iatoms], iwater+1);
	  return(2);
	}
	strncpy(ivalue,line+15,5);
	atomnum[iatoms]=strtol(ivalue, NULL,10);
	if (atomnum[iatoms]!=iatoms+1) {
	  fprintf(stderr, "Error reading atom number %d, expected %d\n", atomnum[iatoms], iatoms+1);
	  return(2);
	}
	atomtype[iatoms]=0;
	strncpy(value,line+20,8);
	OW_x[iwater] = strtod(value, NULL);
	strncpy(value,line+28,8);
	OW_y[iwater] = strtod(value, NULL);
	strncpy(value,line+36,8);
	OW_z[iwater] = strtod(value, NULL);
	strncpy(value,line+44,8);
	OW_vx[iwater] = strtod(value, NULL);
	strncpy(value,line+52,8);
	OW_vy[iwater] = strtod(value, NULL);
	strncpy(value,line+60,8);
	OW_vz[iwater] = strtod(value, NULL);
      }
      else {
	  fprintf(stderr,"Trouble--expect OW for atom %d\n",iatoms);
	  return(2);
      }
    }
    else {
	  fprintf(stderr,"Trouble--expect SOL for atom %d\n",iatoms);
	  return(2);
    }

    iatoms++;
    if (!fgets(line, 120, gro_in)) {   //Stop if we are at the end of the pdb file
      fprintf(stderr, "Error reading atom number %d, expected %d\n", iatoms+1, natoms);
      return(2);
    }
    if (line[5]=='S'&&line[6]=='O'&&line[7]=='L') {
      if (line[12]=='H' and line[13]=='W' and line[14]=='1') {
	strncpy(ivalue,line,5);
	waternum[iatoms]=atol(ivalue);
	if (waternum[iatoms]!=iwater+1) {
	  fprintf(stderr, "Error reading water number %d, expected %d\n", waternum[iatoms], iwater+1);
	  return(2);
	}
	strncpy(ivalue,line+15,5);
	atomnum[iatoms]=strtol(ivalue, NULL, 10);
	if (atomnum[iatoms]!=iatoms+1) {
	  fprintf(stderr, "Error reading atom number %d, expected %d\n", atomnum[iatoms], iatoms+1);
	  return(2);
	}
	atomtype[iatoms]=1;
	strncpy(value,line+20,8);
	HW1_x[iwater] = strtod(value, NULL);
	strncpy(value,line+28,8);
	HW1_y[iwater] = strtod(value, NULL);
	strncpy(value,line+36,8);
	HW1_z[iwater] = strtod(value, NULL);
	strncpy(value,line+44,8);
	HW1_vx[iwater] = strtod(value, NULL);
	strncpy(value,line+52,8);
	HW1_vy[iwater] = strtod(value, NULL);
	strncpy(value,line+60,8);
	HW1_vz[iwater] = strtod(value, NULL);
      }
      else {
	  fprintf(stderr, "Trouble--expect HW1 for atom %d\n",iatoms);
	  return(2);
      }
    }
    else {
	  fprintf(stderr,"Trouble--expect SOL for atom %d\n",iatoms);
	  return(2);
    }

    iatoms++;
    if (!fgets(line, 120, gro_in)) {   //Stop if we are at the end of the pdb file
      fprintf(stderr, "Error reading atom number %d, expected %d\n", iatoms+1, natoms);
      return(2);
    }
    if (line[5]=='S'&&line[6]=='O'&&line[7]=='L') {
      if (line[12]=='H' and line[13]=='W' and line[14]=='2') {
	strncpy(ivalue,line,5);
	waternum[iatoms]=atol(ivalue);
	if (waternum[iatoms]!=iwater+1) {
	  fprintf(stderr, "Error reading water number %d, expected %d\n", waternum[iatoms], iwater+1);
	  return(2);
	}
	strncpy(ivalue,line+15,5);
	atomnum[iatoms]=atol(ivalue);
	if (atomnum[iatoms]!=iatoms+1) {
	  fprintf(stderr, "Error reading atom number %d, expected %d\n", atomnum[iatoms], iatoms+1);
	  return(2);
	}
	atomtype[iatoms]=2;
	strncpy(value,line+20,8);
	HW2_x[iwater] = strtod(value, NULL);
	strncpy(value,line+28,8);
	HW2_y[iwater] = strtod(value, NULL);
	strncpy(value,line+36,8);
	HW2_z[iwater] = strtod(value, NULL);
	strncpy(value,line+44,8);
	HW2_vx[iwater] = strtod(value, NULL);
	strncpy(value,line+52,8);
	HW2_vy[iwater] = strtod(value, NULL);
	strncpy(value,line+60,8);
	HW2_vz[iwater] = strtod(value, NULL);
      }
      else {
	  fprintf(stderr, "Trouble--expect HW2 for atom %d\n",iatoms);
	  return(2);
      }
    }
    else {
	  fprintf(stderr,"Trouble--expect SOL for atom %d\n",iatoms);
	  return(2);
    }
    iatoms++;
  }

  //Read comment line
  if (!fgets(boxsize, 100, gro_in)) {   //Stop if we cannot read the box size
    fprintf(stderr, "Could not read boxsize line \n", argv[0]);
    return(2);
  }

  // Identify evaporated atoms based on inter-OW distances
  /* printf("Starting sort (each . indicates 100 waters completed)\n");   ---> commented out by Jane */
  int n_evap=0;
  int evap_list[MAX_ATOMS];
  double dists[MAX_ATOMS];
  for (int i=0; i<nwaters; i++) {
    //printf("%d\n",i);
    //if (i%100==0) printf(".");
    /* if (i%100==0) {
	printf(".");
	fflush(stdout);
    }   ---> commented out by Jane */
    for (int j=0; j<nwaters; j++) {
      dists[j]=dist2(OW_x[i],OW_y[i],OW_z[i],OW_x[j],OW_y[j],OW_z[j]);
    }
    //sort(dists,nwaters);
    qsort(dists, nwaters, sizeof(double), compare_doubles);
    //for (int j=0; j<atom_count_in; j++) {
    //if (i==0) printf("Sorted distance=%lf\n",dists[j]);
    //}
    if (dists[3] > dist_cutoff2) {
      evap_list[n_evap]=i;
      n_evap++;
    }
  }
  printf("%d waters evaporated\n",n_evap);
  fclose(gro_in);
}


/*-------------------- END main --------------------*/

double dist2(double x1, double y1, double z1, double x2, double y2, double z2) {
  return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int compare_doubles(const void *a, const void *b) {
  const double *da = (const double *) a;
  const double *db = (const double *) b;
  return (*da > *db) - (*da < *db);
}
