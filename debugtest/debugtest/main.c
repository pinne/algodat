#include <stdio.h>

int tab[5][4],tal[21];

void solve(int ball){
  int i,j;
  if(ball==5){
    printf("Osynliga tal : ");
    for(i=0;i<5;i++)
      for(j=2;j<4;j++)
        printf("%d ",tab[i][j]);
    printf("\n");
  }
  for(i=1;i<=19;i++)
    for(j=i+1;j<=20;j++)
      if(tal[i]==0 && tal[j]==0 &&
         i+j+tab[ball][0]+tab[ball][1]==42){
        tal[i]=1; tal[j]=1;
        tab[ball][2]=i;
        tab[ball][3]=j;
        solve(ball+1);
        tal[i]=0; tal[j]=0;
      }
}

int main(void){
  int i,j;
  FILE *fil;
  for(i=0;i<5;i++)
    for(j=0;j<4;j++)
      tab[i][j]=0;
  for(i=0;i<21;i++)
    tal[i]=0;
  fil=fopen("talen.txt","rt");
  for(i=0;i<5;i++)
    for(j=0;j<2;j++){
      fscanf(fil,"%d",&tab[i][j]);
      tal[tab[i][j]]=1;
    }
  solve(0);
  fclose(fil);
  printf("*** KLART ***\n");
}
