#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namntyp {
	char namn[10];
	struct namntyp *nasta;
} namntyp;

void skriv_ut(namntyp *sl);

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

struct namntyp *list_tail(namntyp *list)
{
	while (list != NULL && list->nasta != NULL) {
		list = list->nasta;
	}
	return list;
}

int len(namntyp *list)
{
	int n;

	if (list == NULL) {
		n = 0;
	} else {
		for (n = 1; list->nasta != NULL; n += 1) {
			list = list->nasta;
		}
	}
	return n;
}

void append(namntyp **sl, namntyp *list)
{
	static int counter;
	namntyp *tail = list_tail(*sl);

	if (counter++ == 0) {
		strcpy(tail->namn, list->namn);
		tail->nasta = NULL;
	} else {
		namntyp *new = malloc(sizeof(namntyp));
		strcpy(new->namn, list->namn);
		tail->nasta = new;
		tail->nasta->nasta = NULL;
	}
}

void merge(namntyp *left, namntyp *right, namntyp **sl)
{
	*sl = malloc(sizeof(namntyp));

	while (left != NULL && right != NULL) {
		if (strcmp(left->namn, right->namn) <= 0) {
			append(sl, left);
			left = left->nasta;
		} else {
			append(sl, right);
			right = right->nasta;
		}
	}
}

void rmerge(namntyp *l1, namntyp *l2, namntyp **sl)
{
	if (strcmp(l1->namn, l2->namn) <= 0) {
		/* If l1 is smaller than l2, make sl->nasta point to l1 */
		append(sl, l1);
		if (l1->nasta != NULL)
			rmerge(l1->nasta, l2, sl);
	} else if (strcmp(l1->namn, l2->namn) > 0) {
		/* If l2 is smaller than l1, make sl->nasta point to l2 */
		append(sl, l2);
		if (l2->nasta != NULL)
			rmerge(l1, l2->nasta, sl);
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

int main(int argc, char *argv[])
{
	namntyp *lista1;
	namntyp *lista2;
	namntyp *slutlista;

	if (argc < 2) {
		laes_in(&lista1, "UPPG3A.DAT");
		laes_in(&lista2, "UPPG3E.DAT");
	} else {
		laes_in(&lista1, argv[1]);
		laes_in(&lista2, argv[2]);
	}

	merge(lista1, lista2, &slutlista);
	skriv_ut(slutlista);

	free(lista1);
	free(lista2);
	free(slutlista);

	return 0;
}

