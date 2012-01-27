#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namntyp {
	char namn[10];
	struct namntyp *nasta;
} namntyp;

void laes_in(namntyp **l1, char filnamn[])
{
	FILE *fil;
	struct namntyp *a;
	struct namntyp *forra;
	char namn[10];

	fil = fopen(filnamn, "rt");
	*l1 = NULL;
	while(!feof(fil)) {
		fscanf(fil, "%s",namn);
		if (!feof(fil)) {
			if (*l1 != NULL)
				forra = a;
			a = (namntyp *)malloc(sizeof(namntyp));
			a->nasta = NULL;
			strcpy(a->namn, namn);
			if (*l1 == NULL)
				*l1 = a;
			else
				forra->nasta = a;
		}
	}
	fclose(fil);
}

void merge(namntyp *l1, namntyp *l2, namntyp **sl)
{
}

void skriv_ut(namntyp *sl)
{
	namntyp *a;
	while (sl!=NULL) {
		printf("%s\n", sl->namn);
		a = sl;
		sl = sl->nasta;
		free(a);
	}
}

int main(void)
{
	namntyp *lista1;
	namntyp *lista2;
	namntyp *slutlista;
	laes_in(&lista1, "UPPG3A.DAT");
	laes_in(&lista2, "UPPG3B.DAT");
	merge(lista1, lista2, &slutlista);
	laes_in(&lista1, "UPPG3C.DAT");
	laes_in(&lista2, "UPPG3D.DAT");
	merge(lista1, lista2, &slutlista);
	laes_in(&lista1, "UPPG3E.DAT");
	skriv_ut(slutlista);

	return 0;
}

