#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void){
	int i, j, *pek, n, *lista;
	FILE *fil;

	/* skapar 20 stackar med storlek 100 */
	InitStack(20, sizeof(int), 100);
	fil = fopen("TAL.DAT", "rt");
	fscanf(fil, "%d", &n); /* antal rader */

	/* allokerar minne värt (n * int) */
	/* som en array fylld med NULL */
	lista = (int *)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		fscanf(fil, "%d", &lista[i]);
	fclose(fil);

        /* placerar arrayens element i stackar,
	 * där stack# == värde på (element `floor div` 10)
	 *
	 * 0 - 9 hamnar i stack[0]
	 * 10-19 hamnar i stack[1]
	 *
	 * sortering på tiotal!
	 */
	for (i = 0; i < n; i++)
		Push(lista[i] / 10, &lista[i]);
	free(lista); /* frigör minnet som innehas av array */

	/* tömmer stack 0-9 */
	for (j = 0; j < 10; j++) {
		while (!IsEmpty(j)) {
			pek = (int *)Pop(j);
			/* exempel: 
			 * let pek = 5
			 * pek % 10 + 10 = 15
			 *
			 * pek pushas till stack #11
			 *
			 * sortering på ental!
			 */
			Push(*pek % 10 + 10, pek);
		}
		/*
		 * siffrorna transponerade +10
		 */
		for (i = 10; i < 20; i++)
			while (!IsEmpty(i)) {
				pek = (int *)Pop(i);
				printf("stack %d\t*pek%3d ", i, *pek);
				printf("\n");
			}
	}
	printf("\n");
	return 0;
}
