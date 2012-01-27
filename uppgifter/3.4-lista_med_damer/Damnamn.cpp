#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct dam{
   char namn[15];
   struct dam *next;
}dam;

void init(dam **liststart){
   FILE *fil;
   char innamn[15];
   dam *ny,*sist;
   fil=fopen("damnamn.dat","rt");
   *liststart=NULL;
   if (fil!=NULL){
      while(!feof(fil)){
         fscanf(fil,"%s",innamn);
         if (!feof(fil)){
            ny=(dam *) malloc(sizeof(dam));
            strcpy(ny->namn,innamn);
            ny->next=NULL;
            if (*liststart==NULL){
               *liststart=ny;
               sist=ny;
            }
            else{
               sist->next=ny;
               sist=ny;
            } 
         }
      }
      fclose(fil);
   }
}

void skrivlista(dam *p){
   int n=0;
   printf("\n------------------------------\n");
   while(p!=NULL){
      n++;
      printf("%s ",p->namn); 
      if (n%7==0) printf("\n");
      p=p->next;
   }
}

int tabortnamn(dam **p,char n[]){
}

int tabortplats(dam **p,int n){
}

int antal(dam *p){
}

void placeraforst(dam **p,char n[]){
}

void placerasist(dam **p,char n[]){
}

int placeraefter(dam *p,char nytt[],char gam[]){
}

int placerafore(dam **p,char nytt[],char gam[]){
}

int finns(dam *aktuell,char n[]){
}

dam* fore(dam *p,char n[]){
}

dam* efter(dam *p,char n[]){
}

void main(void){
   dam *liststart,*p;
   int r;
   init(&liststart);
   skrivlista(liststart);
   r=tabortnamn(&liststart,"Daniella");
   skrivlista(liststart);
   r=tabortplats(&liststart,8);
   skrivlista(liststart);
   printf("\nAntal namn i listan är %d\n",antal(liststart));
   placeraforst(&liststart,"Ann");
   skrivlista(liststart);
   placerasist(&liststart,"Åsa");
   skrivlista(liststart);
   r=placeraefter(liststart,"Karin","Gun");
   skrivlista(liststart);
   r=placerafore(&liststart,"Nelly","Marie");
   skrivlista(liststart);
   r=finns(liststart,"Ulla");
   if(r==1) 
      printf("\nPersonen finns\n");
   else
      printf("\nPersonen finns inte\n"); 
   p=fore(liststart,"Jenny");
   printf("\n%s finns före Jenny\n",p->namn);
   skrivlista(liststart);
   p=efter(liststart,"Kristina");
   printf("\n%s finns efter Kristina\n",p->namn);
   skrivlista(liststart);
}
