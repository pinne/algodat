#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ANTAL_BARN 8
#define ANTAL_ORD 11

struct barn{
  char n;
  struct barn *next;
};
typedef struct barn barn;

barn *skapa(int n){
  barn *start,*ps,*p;
  int i;
  start=(barn *) malloc(sizeof(barn));
  start->n='A';
  ps=start;
  for(i=2;i<=n;i++){
    p=(barn *) malloc(sizeof(barn));
    p->n='A'+i-1;
    ps->next=p;
    ps=p;
  }
  p->next=start;
  return start;
}

int rakna(barn *p){
  barn *slut;
  int m=0;
  slut=p;
  do{
    p=p->next;
    m++;
  }while(p!=slut);
  return m;
}

// Här är ett lämpligt ställe att placera
// funktionen RAKNAUT

void main(void){
  barn *start;
  start=skapa(ANTAL_BARN);
  do{
    start=raknaut(start,ANTAL_ORD);
  }while(rakna(start)>1);
  printf("%c blev kvar till sist\n",start->n);
  getch();
}
