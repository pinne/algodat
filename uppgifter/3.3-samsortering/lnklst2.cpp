#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namntyp{
	char namn[10];
	struct namntyp *nasta;
}namntyp;

void laes_in(namntyp **l1,char filnamn[]){
	FILE *fil;
	struct namntyp *a,*forra;
	char namn[10];

	fil=fopen(filnamn,"rt");
	*l1=NULL;
	while(!feof(fil)){
		fscanf(fil,"%s",namn);
		if (!feof(fil)){
			if (*l1!=NULL) forra=a;
			a=(namntyp *)malloc(sizeof(namntyp));
			a->nasta=NULL;
			strcpy(a->namn,namn);
			if (*l1==NULL)
				*l1=a;
			else
				forra->nasta=a;
		}
	}
	fclose(fil);
}

void merge(namntyp *l1,namntyp *l2,namntyp **sl){
	// ******************
	// Här ska din kod in
	// ******************
}

void skriv_ut(namntyp *sl){
	namntyp *a;
	while (sl!=NULL) {
		printf("%s\n",sl->namn);
		a=sl;
		sl=sl->nasta;
		free(a);
	}
}

void main(void){
	namntyp *lista1,*lista2,*slutlista;
	laes_in(&lista1,"uppg3b.dat");
	laes_in(&lista2,"uppg3d.dat");
	merge(lista1,lista2,&slutlista);
	skriv_ut(slutlista);
}
