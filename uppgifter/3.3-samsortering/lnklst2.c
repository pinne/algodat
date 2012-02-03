#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namntyp {
	char namn[10];
	struct namntyp *nasta;
} namntyp;

namntyp *head;
namntyp *tail;

void laes_in(namntyp **l1, char filnamn[])
{
	FILE *fil;
	struct namntyp *a;
	struct namntyp *forra;
	char namn[10];

	fil = fopen(filnamn, "rt");
	*l1 = NULL;
	while(!feof(fil)) {
		fscanf(fil, "%s", namn);
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

//void append(namntyp **sl, namntyp *l1)
//{
//	namntyp *new;
//	new = malloc(sizeof(namntyp));
//	strcpy(new->namn, l1->namn);
//
//	tail->nasta = new;
//	tail = tail->nasta;
//}

void append(namntyp **sl, namntyp *list)
{
	namntyp *new;
	new = malloc(sizeof(namntyp));
	strcpy(new->namn, list->namn);

	tail->nasta = new;
	tail = tail->nasta;
	tail->nasta = NULL;
}

void merge(namntyp *l1, namntyp *l2, namntyp **sl)
{
	if (strcmp(l1->namn, l2->namn) <= 0) {
		append(sl, l1);
		if (l1->nasta != NULL)
			merge(l1->nasta, l2, sl);
		else if (l2 != NULL)
			tail->nasta = l2;
	} else if (strcmp(l1->namn, l2->namn) > 0) {
		append(sl, l2);
		if (l2->nasta != NULL)
			merge(l1, l2->nasta, sl);
		else if (l1 != NULL)
			tail->nasta = l1;
	}
}

void skriv_ut(namntyp *sl)
{
	namntyp *a;
	while (sl != NULL) {
		printf("%s\n", sl->namn);
		a = sl;
		sl = sl->nasta;
		free(a);
	}
}

int len(namntyp *lista)
{
	int n = 0;
	while (lista != NULL) {
		lista = lista->nasta;
		n++;
	}
	return n;
}

int main(int argc, char *argv[])
{
	namntyp *lista1;
	namntyp *lista2;
	namntyp *slutlista = malloc(sizeof(namntyp)*20);
	head = slutlista;
	tail = slutlista;

	if (argc < 2) {
		laes_in(&lista1, "UPPG3A.DAT");
		laes_in(&lista2, "UPPG3E.DAT");
	} else {
		laes_in(&lista1, argv[1]);
		laes_in(&lista2, argv[2]);
	}
	if (len(lista1) > len(lista2))
		merge(lista1, lista2, &slutlista);
	else
		merge(lista2, lista1, &slutlista);

	skriv_ut(slutlista);
	free(lista1);
	free(lista2);

	return 0;
}

