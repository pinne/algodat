#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct objekt {
	char nyckel[10];
	struct objekt *left, *right;
};
typedef struct objekt objekt;

// Rekusiv ins�ttning
objekt *InsertTree(objekt * p, objekt ny)
{
	objekt *z;

	if (p == NULL) {
		z = (objekt *) malloc(sizeof(objekt));
		*z = ny;
		z->left = NULL;
		z->right = NULL;
		return z;
	} else if (strcmp(ny.nyckel, p->nyckel) < 0)
		p->left = InsertTree(p->left, ny);
	else
		p->right = InsertTree(p->right, ny);
	return p;
}

// Iterativ ins�ttning
objekt *InsertTree2(objekt * start, objekt ny)
{
	objekt *x, *y, *z;

	z = (objekt *) malloc(sizeof(objekt));
	*z = ny;
	y = NULL;
	x = start;
	while (x != NULL) {
		y = x;
		if (strcmp(z->nyckel, x->nyckel) < 0)
			x = x->left;
		else
			x = x->right;
	}
	if (y == NULL)
		start = z;
	else {
		if (strcmp(z->nyckel, y->nyckel) < 0)
			y->left = z;
		else
			y->right = z;
	}
	return start;
}

// Borttagning av hela tr�det
void DeleteTree(objekt ** x)
{
	objekt *z;

	if (*x != NULL) {
		if ((*x)->right == NULL) {
			z = *x;
			*x = (*x)->left;
			free(z);
		} else if ((*x)->left == NULL) {
			z = *x;
			*x = (*x)->right;
			free(z);
		} else {
			z = (*x)->right;
			while (z->left != NULL)
				z = z->left;
			z->left = (*x)->left;
			z = *x;
			*x = (*x)->right;
			free(z);
		}
	}
}

// S�k given nyckel
objekt *SearchTree(objekt * x, char namn[])
{
	if (x == NULL) {
		return NULL;
	} else if (x != NULL && strcmp(x->nyckel, namn) == 0) {
		return x;
	} else if (x != NULL) {
		if (strcmp(namn, x->nyckel) < 0)
			x = SearchTree(x->left, namn);
		else
			x = SearchTree(x->right, namn);
	}
	return x;
}

// S�k fader (y) till given nyckel (x)
objekt *SearchFather(objekt * x, objekt * y, char namn[])
{
	if (x == NULL)
		return NULL;
	if (x != NULL && strcmp(x->nyckel, namn) == 0)
		return y;
	if (x != NULL) {
		if (strcmp(namn, x->nyckel) < 0)
			y = SearchFather(x->left, x, namn);
		else
			y = SearchFather(x->right, x, namn);
	}
	return y;
}

// Borttagnng av given nod. H�r uppdelat i tv� steg. Jfr boken
void DeleteName(objekt ** x, char namn[])
{
	objekt *tmp;

	tmp = SearchFather(*x, NULL, namn);
	if (tmp == NULL)
		DeleteTree(x);
	else if (strcmp(tmp->nyckel, namn) == 0)
		DeleteTree(&tmp->left);
	else
		DeleteTree(&tmp->right);
}

// Skriv ut tr�det
void PrintTree(objekt * x)
{
	if (x != NULL) {
		PrintTree(x->left);
		printf("%s ", x->nyckel);
		PrintTree(x->right);
	}
}

void PrintTree_Preorder(objekt * x)
{
	if (x != NULL) {
		printf("%s ", x->nyckel);
		PrintTree(x->left);
		PrintTree(x->right);
	}
}

void PrintTree_Postorder(objekt * x)
{
	if (x != NULL) {
		PrintTree(x->left);
		PrintTree(x->right);
		printf("%s ", x->nyckel);
	}
}

// N�gra anv�ndningar av funktionerna
int main(void)
{
	objekt *start, ny;
	int k;
	FILE *fil;

	start = NULL;
	fil = fopen("BINTRAD3.DAT", "rt");
	for (k = 1; k <= 14; k++) {
		fscanf(fil, "%s", ny.nyckel);
		ny.left = NULL;
		ny.right = NULL;
		start = InsertTree2(start, ny);
	}
	if (SearchTree(start, "Gustav"))
		printf("Finns\n");
	else
		printf("Finns Ej\n");

	printf("Printing in-order\n");
	PrintTree(start);
	printf("\n");
	printf("Printing pre-order\n");
	PrintTree_Preorder(start);
	printf("\n");
	printf("Printing post-order\n");
	PrintTree_Postorder(start);
	printf("\n");
	printf("\n");
	DeleteName(&start, "Jan");
	PrintTree(start);
	printf("\n");
	strcpy(ny.nyckel, "Jan");
	InsertTree(start, ny);
	PrintTree(start);
	printf("\n");

	while (start != NULL)
		DeleteTree(&start);

	return 0;
}
