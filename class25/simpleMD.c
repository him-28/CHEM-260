/* C translation of Simple Soft Sphere Molecular Dynamics Program  */

#define MAXATOMS 1000
#define REAL double
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/* Function to produce a random number from 0-1 */
REAL randomfloat(void) {
  return rand()/(double)RAND_MAX;
}

/* Function to produce a random unit vector */
REAL *random_unit(void) {
  static REAL rvec[3];
  REAL x,y,z,theta;
  z=randomfloat()*2.0-1;
  theta=randomfloat()*2.*M_PI;
  x=sqrt(1-z*z)*cos(theta);
  y=sqrt(1-z*z)*sin(theta);
  rvec[0]=x;
  rvec[1]=y;
  rvec[2]=z;
  return rvec;
}

/* Function to produce distance between two list points */
REAL dist(REAL *a, REAL *b) {
  return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2]));
}

/*  Function to produce square magnitude of vector */
REAL sqmag(REAL *a) {
  return (a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
}

/* Function to return unit vector pointing between two points */
REAL *vector(REAL *a, REAL *b) {
  static REAL vect[3];
  REAL r;
  r=dist(a,b);
  vect[0]=(a[0]-b[0])/r;
  vect[1]=(a[1]-b[1])/r;
  vect[2]=(a[2]-b[2])/r;
  return vect;
}

/* Simulation program */
main() {
  /* Set parameters */
  int natoms;
  REAL mass=39.948;      /* AMU (g/mole) */
  REAL sigma=.341;       /* nm */
  REAL epsilon=0.9661;   /* kj/mole equals nm^2 AMU/ps^2 */
  REAL T=40.;            /* Temp in deg K */
  REAL tstep=0.002;      /* Time step in ps */
  int nsteps=500;        /* Simulation steps */
  int equil=1000;          /* Equilibration period NOT USED */
  int temp_intvl=10;       /* Interval between calculating T */
  int e_intvl=10;          /* #Interval between calculating E */
  REAL tstep2, rm, sep, sigma6, sigma12, k, speed2, speed;
  REAL *runit, *unit, r, r6, r7, r12, r13, forcemag, PE, KE;
  int side, iatom, x, y, z, dim, step, jatom; 

  /* Allocate arrays for results */
  REAL pos[MAXATOMS][3];
  REAL pos_new[MAXATOMS][3];
  REAL vel[MAXATOMS][3];
  REAL vel_new[MAXATOMS][3];
  REAL force[MAXATOMS][3];
  REAL force_new[MAXATOMS][3];

  /*  Convert units and precalculate constants */
  natoms=pow(8,3);
  tstep2=tstep*tstep;  /* ps^2 */
  rm=pow(2,(1./6.))*sigma;
  sep=1.*rm; 
  sigma6=pow(sigma,6);
  sigma12=pow(sigma,12);
  k=0.00831446;        /* KJ/mol*K equals nm^2 AMU/ps^2*K */
  speed2=3.*k*T/mass;  /* nm^2/ps^2 */
  speed=sqrt(speed2);
  side=(int)(pow(natoms,(1./3.))-.01)+1;

  /* Initialize all of the simulation lists */
  iatom=0;
  for (x=0; x<side; x++) {
    for (y=0; y<side; y++) {
      for (z=0; z<side; z++) {
	pos[iatom][0]=x*sep;
	pos[iatom][1]=y*sep;
	pos[iatom][2]=z*sep;
	runit=random_unit();
	for (dim=0; dim<3; dim++) {
	  vel[iatom][dim]=runit[dim]*speed;
	  pos_new[iatom][dim]=0.;
	  vel_new[iatom][dim]=0.;
	  force[iatom][dim]=0.;
	  force_new[iatom][dim]=0;
	}
	iatom++;
	if (iatom==natoms) {
	  goto finished;
	}
      }
    }
  }
 finished:
  /* Run dynamics */
  for (step=0; step<nsteps; step++) {
    /* Update positions using velocity verlet integration 
       and zero out force matrix */
    for (iatom=0; iatom<natoms; iatom++) {
      for (dim=0; dim<3; dim++){
	pos_new[iatom][dim]=pos[iatom][dim]+vel[iatom][dim]*tstep+force[iatom][dim]/mass*tstep2;
	force_new[iatom][dim]=0.0;
      }
    }

    /* Calculate force on each atom */
    for (iatom=0; iatom<(natoms-1); iatom++) {
      for (jatom=iatom+1; jatom<natoms; jatom++) {  /* Loop over unique pairs of atoms */
	r=dist(pos_new[iatom],pos_new[jatom]);
	r7=pow(r,-7);
	r13=pow(r,-13);
	forcemag=24.*epsilon*(-2.*sigma12*r13+sigma6*r7);

	/* Resolve force into vector components */
	unit=vector(pos_new[iatom],pos_new[jatom]);
	for (dim=0; dim<3; dim++){
	  force_new[iatom][dim]-=unit[dim]*forcemag;
	  force_new[jatom][dim]+=unit[dim]*forcemag;
	}
      }
    }
    /* Update velcities using velocity verlet integration */
    for (iatom=0; iatom<natoms; iatom++) {
      for (dim=0; dim<3; dim++){
	vel_new[iatom][dim]=vel[iatom][dim]+0.5/mass*(force[iatom][dim]+force_new[iatom][dim])*tstep;
  }
    }

    /* Calculate energy */
    if (step%e_intvl==0) {
      PE=0.;
      KE=0.;
      for (iatom=0; iatom<(natoms-1); iatom++) {
	KE+=mass*sqmag(vel_new[iatom])/2.0;
	for (jatom=iatom+1; jatom<natoms; jatom++) {	/* Loop over unique pairs of atoms */
	  r=dist(pos_new[iatom],pos_new[jatom]);
	  r6=pow(r,-6);
	  r12=pow(r,-12);
	  PE+=4.*epsilon*(sigma12*r12-sigma6*r6);
	}
      }
      KE+=mass*sqmag(vel_new[natoms-1])/2.0;	/* Add final contribution that's missed in loops */
      printf("At step %5d PE is %7.2f	 KE is %7.2f TE is %7.2f\n",step,PE,KE,PE+KE);
    }	       

    memcpy(pos, pos_new, natoms*3*sizeof(REAL));
    memcpy(vel, vel_new, natoms*3*sizeof(REAL));
    memcpy(force, force_new, natoms*3*sizeof(REAL));
  } 
}      
