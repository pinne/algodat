#include <stdio.h>
#include <stdlib.h>
#include "list.h"

person *laesin(void){
  FILE *infil;
  int nlistor,listor[100],i,antal,lista=1,n;
  person *downp,*rightp,*start,*ny;
  char fnamn[20];

  printf("Filnamn: ");
  scanf("%s",fnamn);
  infil=fopen(fnamn,"rt");
  fscanf(infil,"%d",&nlistor);
  for(i=1;i<=nlistor;i++)
    fscanf(infil,"%d",&listor[i]);
  fscanf(infil,"%d",&antal);
  start=(person *)malloc(sizeof(person));
  fscanf(infil,"%s",start->namn);
  start->right=NULL;
  start->down=NULL;
  rightp=start;
  downp=start;
  n=1;
  for(i=1;i<antal;i++){
    // L„s in person
    ny=(person *)malloc(sizeof(person));
    fscanf(infil,"%s",ny->namn);
    ny->right=NULL;
    ny->down=NULL;
    // Var ska personen l„ggas till
    if(n==listor[lista]){
      n=1;
      lista++;
      rightp->right=ny;
      downp=ny;
      rightp=ny;
    }
    else{
      n++;
      downp->down=ny;
      downp=ny;
    }
  }
  return start;
}

void tabort(person *start){
  person *d,*r,*s;
  r=start;
  d=start;
  do{
    if(d->down!=NULL){
      d=d->down;
      do{
        s=d;
        d=d->down;
        free(s);
      }while(d!=NULL);
    }
    s=r;
    r=r->right;
    d=r;
    free(s);
  }while(r!=NULL);
}


