#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define USAGE "./3D_randomwalk.out Nsteps Nwalks>=2"


double make_walk(int nsteps);

int main(int argc, char **argv){

  if(argc!=3){
    printf("USAGE: %s\n", USAGE);
    exit(1);
  }

  int semilla;
  int nwalks;
  int nsteps;
  int i;
  double sumap=0.0;
  double sumad=0.0;
  double D;
  double Desv;


  semilla=time(NULL);
  srand48(semilla);

  nsteps=atoi(argv[1]);
  nwalks=atoi(argv[2]);

  double value[nwalks];

  if(nwalks<2){
    printf("El número de marchas debe ser igual o mayor a 2\n");
  }

  for(i=0;i<nwalks;i++){
     value[i]=make_walk(nsteps);
     sumap=sumap+value[i];
  }
  D=sumap/nwalks;

  for(i=0;i<nwalks;i++){
     sumad=sumad+(value[i]-D)*(value[i]-D);
  }
  Desv=sqrt(sumad/(nwalks-1.0));

  printf("%.10lf\n%.10lf\n",D,Desv);

  return 0;
}


double make_walk(int nsteps){
  double x0,y0,z0,norma;
  double dist=0.0;
  double xi=0;
  double yi=0;
  double zi=0;
  int i=0;
  while(i<nsteps){
    x0=2*(drand48()-0.5);
    y0=2*(drand48()-0.5);
    z0=2*(drand48()-0.5);
    norma=sqrt(x0*x0+y0*y0+z0*z0);
    xi=xi+x0/norma;
    yi=yi+y0/norma;
    zi=zi+z0/norma;
    dist=sqrt(xi*xi+yi*yi+zi*zi);
    i=i+1;
  }
  return dist;
}
