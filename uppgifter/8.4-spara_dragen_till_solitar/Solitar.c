#include <stdio.h>
#include <stdlib.h>

int stack[10000];
int stack_len;

int brade[11][11];
int losning[32][6];

void init(void)
{
	int i, j;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			brade[i][j] = 2;
	for (i = 2; i <= 8; i++)
		for (j = 4; j <= 6; j++)
			brade[i][j] = 1;
	for (i = 4; i <= 6; i++)
		for (j = 2; j <= 8; j++)
			brade[i][j] = 1;
	brade[5][5] = 0;
}

void draggen(int lista[32][6], int *n)
{
	int i, j;
	*n = 0;
	for (i = 2; i <= 8; i++)
		for (j = 2; j <= 8; j++)
			if (brade[i][j] == 1) {
				if (brade[i + 1][j] == 1
				    && brade[i + 2][j] == 0) {
					/* up */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i + 1;
					lista[*n][3] = j;
					lista[*n][4] = i + 2;
					lista[*n][5] = j;
				}
				if (brade[i - 1][j] == 1
				    && brade[i - 2][j] == 0) {
					/* down */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i - 1;
					lista[*n][3] = j;
					lista[*n][4] = i - 2;
					lista[*n][5] = j;
				}
				if (brade[i][j + 1] == 1
				    && brade[i][j + 2] == 0) {
					/* right */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i;
					lista[*n][3] = j + 1;
					lista[*n][4] = i;
					lista[*n][5] = j + 2;
				}
				if (brade[i][j - 1] == 1
				    && brade[i][j - 2] == 0) {
					/* left */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i;
					lista[*n][3] = j - 1;
					lista[*n][4] = i;
					lista[*n][5] = j - 2;
				}
			}
}

void print_stack(void)
{
	int i = 0;
	while (i++ < stack_len) {
		printf("%d ", stack[i]);
		if (i % 4 == 0)
			printf("\n");
		else if (i % 2 == 0)
			printf(" ");
	}
}
 
void nastadrag(int nr)
{
	int k, n;
	int lista[32][6];
	if (nr == 31) {
		printf("Lösning funnen\n");
		print_stack();
		exit(0);
	} else {
		draggen(lista, &n);
		for (k = 1; k <= n; k++) {
			brade[lista[k][0]][lista[k][1]] = 0;
			brade[lista[k][2]][lista[k][3]] = 0;
			brade[lista[k][4]][lista[k][5]] = 1;
			stack[stack_len++] = lista[k][0];
                        stack[stack_len++] = lista[k][1];
//			stack[stack_len++] = lista[k][2];
//                      stack[stack_len++] = lista[k][3];
			stack[stack_len++] = lista[k][4];
                        stack[stack_len++] = lista[k][5];
			nastadrag(nr + 1);
			stack_len -= 4;
			brade[lista[k][0]][lista[k][1]] = 1;
			brade[lista[k][2]][lista[k][3]] = 1;
			brade[lista[k][4]][lista[k][5]] = 0;
		}
	}
}

int main(void)
{
	init();
	stack_len = 0;
	nastadrag(0);
	return 0;
}
