#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define NANSI /* No ANSI color codes */

#ifndef NANSI
#define COL_EMPTY "\033[1;30;40m"
#define COL_TAKEN "\033[37;40m"
#define COL_NEW "\033[1;37;40m"
#define COL_SHADOW "\033[1;30;40m"
#define COL_ILLEGAL "\033[30;44m"
#define ENDCOLOR "\033[0m"
#else
#define COL_EMPTY ""
#define COL_TAKEN ""
#define COL_NEW ""
#define COL_SHADOW ""
#define COL_ILLEGAL ""
#define ENDCOLOR ""
#endif

#define EMPTY 0
#define TAKEN 1
#define NEW 3
#define SHADOW -1
#define ILLEGAL 2

#define ANIMATIONDELAY 400000
#define STACKCYCLE 6

int stack_head = 0;
int stack[10000];
int stack_len;

int brade[11][11];
int losning[32][6];

void init(void)
{
	int i, j;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			brade[i][j] = ILLEGAL;
	for (i = 2; i <= 8; i++)
		for (j = 4; j <= 6; j++)
			brade[i][j] = TAKEN;
	for (i = 4; i <= 6; i++)
		for (j = 2; j <= 8; j++)
			brade[i][j] = TAKEN;
	brade[5][5] = 0;
}

void draggen(int lista[32][6], int *n)
{
	int i, j;
	*n = 0;
	for (i = 2; i <= 8; i++)
		for (j = 2; j <= 8; j++)
			if (brade[i][j] == TAKEN) {
				if (brade[i + 1][j] == TAKEN
				    && brade[i + 2][j] == EMPTY) {
					/* up */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i + 1;
					lista[*n][3] = j;
					lista[*n][4] = i + 2;
					lista[*n][5] = j;
				}
				if (brade[i - 1][j] == TAKEN
				    && brade[i - 2][j] == EMPTY) {
					/* down */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i - 1;
					lista[*n][3] = j;
					lista[*n][4] = i - 2;
					lista[*n][5] = j;
				}
				if (brade[i][j + 1] == TAKEN
				    && brade[i][j + 2] == EMPTY) {
					/* right */
					(*n)++;
					lista[*n][0] = i;
					lista[*n][1] = j;
					lista[*n][2] = i;
					lista[*n][3] = j + 1;
					lista[*n][4] = i;
					lista[*n][5] = j + 2;
				}
				if (brade[i][j - 1] == TAKEN
				    && brade[i][j - 2] == EMPTY) {
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

/*
 * Print stack from the bottom up, listing all the moves
 */
void print_stack(void)
{
	int i = 0;
	while (i++ < stack_len) {
		printf("%d ", stack[i]);
		if (i % STACKCYCLE == 0)
			printf("\n");
		else if (i % STACKCYCLE/2 == 0)
			printf(" ");
	}
}

void play_stack(void)
{
	/* reset board */
	init();
	while (stack_head < stack_len) {
		int i = 0;
		/* remove pebbles to move */
		int removed[2];
		removed[0] = stack[stack_head++];
		removed[1] = stack[stack_head++];
		brade[removed[0]][removed[1]] = EMPTY;
		/* remove jumped-over pebble */
		int shadow[2];
		shadow[0] = stack[stack_head++];
		shadow[1] = stack[stack_head++];
		brade[shadow[0]][shadow[1]] = SHADOW;
		/* place pebble */
		int new[2];
		new[0] = stack[stack_head++];
		new[1] = stack[stack_head++];
		brade[new[0]][new[1]] = NEW;

		/* call clear from console */
		system("clear");
		/* print board */
		for (i = 1; i < 10; i += 1) {
			int j;
			for (j = 1; j < 10; j += 1) {
				if (brade[i][j] == TAKEN) {
					printf(COL_TAKEN);
					printf(" o ");
					printf(ENDCOLOR);
				} else if (brade[i][j] == NEW) {
#ifndef NANSI
					printf(COL_NEW);
					printf(" O ");
					printf(ENDCOLOR);
#else
					printf(" 0 ");
#endif
				} else if (brade[i][j] == SHADOW) {
					printf(COL_SHADOW);
					printf(" · ");
					printf(ENDCOLOR);
				} else if (brade[i][j] == EMPTY) {
					printf(COL_EMPTY);
					printf("   ");
					printf(ENDCOLOR);
				} else if (brade[i][j] == ILLEGAL) {
					printf(COL_ILLEGAL);
					printf("   ");
					printf(ENDCOLOR);
				}
			}
			printf("\n");
		}
		/* fade shadow */
		brade[shadow[0]][shadow[1]] = EMPTY;
		brade[new[0]][new[1]] = TAKEN;
		usleep(ANIMATIONDELAY);
	}
}

void nastadrag(int nr)
{
	int k, n;
	int lista[32][6];
	if (nr == 31) {
		printf("Lösning funnen\n");
		play_stack();
		//print_stack();

		exit(0);
	} else {
		draggen(lista, &n);
		for (k = 1; k <= n; k++) {
			brade[lista[k][0]][lista[k][1]] = EMPTY;
			brade[lista[k][2]][lista[k][3]] = EMPTY;
			brade[lista[k][4]][lista[k][5]] = TAKEN;
			stack[stack_len++] = lista[k][0];
			stack[stack_len++] = lista[k][1];
			stack[stack_len++] = lista[k][2];
			stack[stack_len++] = lista[k][3];
			stack[stack_len++] = lista[k][4];
			stack[stack_len++] = lista[k][5];
			nastadrag(nr + 1);
			brade[lista[k][0]][lista[k][1]] = TAKEN;
			brade[lista[k][2]][lista[k][3]] = TAKEN;
			brade[lista[k][4]][lista[k][5]] = EMPTY;
			stack_len -= STACKCYCLE;
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
