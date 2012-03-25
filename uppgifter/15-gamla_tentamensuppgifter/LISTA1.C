#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tecken{
  char c;
  struct tecken *next;
};
typedef struct tecken tecken;

tecken *laggtill(char namn[]){
  tecken *start,*p1,*p2;
  int i=0;
  while(namn[i]!='\0'){
    p1=(tecken *)malloc(sizeof(tecken));
    p1->c=namn[i];
    p1->next=NULL;
    if(i==0)
      start=p1;
    else
      p2->next=p1;
    i++;
    p2=p1;
  }
  return start;
}

void skrivut(tecken *start){
  while(!start=='\0'){
    printf("%c",start->c);
    start=start->next;
  }
  printf("\n");
}

void rivner(tecken *p){
  tecken *sp;
  sp=p;
  while(sp!=NULL){
    p=p->next;
    free(sp);
    sp=p;
  }
}

tecken *abort(tecken *p,char t){
  // KOD IN HÄR
}

int main(void){
  tecken *start;
  char namn[81];
  printf("Ett namn: ");
  scanf("%s",namn);
  start=laggtill(namn);
  skrivut(start);
  start=abort(start,'A');
  skrivut(start);
  rivner(start);
  getch();
}

