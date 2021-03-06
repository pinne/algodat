#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct objekt {
	char nyckel[10];
	struct objekt *left, *right;
};

typedef struct objekt objekt;

objekt *insert(objekt * start, objekt ny)
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

// Den h�r funktionen ska du skriva
void inorder(objekt * start)
{
}

void postorder(objekt * start)
{
	objekt *x;
	x = start;
	if (x != NULL) {
		postorder(x->left);
		postorder(x->right);
		printf("%s ", x->nyckel);
	}
}

// Den h�r funktionen ska du skriva
void preorder(objekt * start)
{
}

void main(void)
{
	objekt *start, ny;
	FILE *fil;
	int klar = 0;
	char namn[10];

	start = NULL;
	fil = fopen("bintrad3.dat", "rt");
	while (!klar) {
		fscanf(fil, "%s", namn);
		if (!feof(fil)) {
			strcpy(ny.nyckel, namn);
			ny.left = NULL;
			ny.right = NULL;
			start = insert(start, ny);
		} else
			klar = 1;
	}
	fclose(fil);
	preorder(start);
}
