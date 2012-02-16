#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SIZE;
int tab[100][100];
int try[100][100];

void fill_array(char *);
void print_tab(void);
void print_try(void);
void reset_try(void);
void padding(void);
void walk(int, int, int);
void test(void);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	fill_array("talorm0.txt");
	printf("SIZE %d\n", SIZE);
	padding();
	reset_try();
	print_try();
	print_tab();
	int i;
	int j;
	walk(1, 4, 1);
	//	walk(1, 4, 1);
	//	for (i = 3; i < SIZE; i += 1) {
	//		for (j = 2; j < SIZE; j += 1) {
	//			walk(i, j, 1);
	//			reset_try();
	//		}
	//	}

	return 0;
}

void test(void)
{
	int i;
	int j;
	int good = 6;
	for (i = 1; i < SIZE; i += 1)
		for (j = 1; j < SIZE; j += 1)
			if (try[i][j] != 0)
				good += 1;
	if (good == SIZE * SIZE) {
		print_try();
		exit(0);
	}
}

void walk(int row, int col, int moves)
{
	test();
	if (tab[row][col] == -1 || moves > SIZE * 2
			|| (try[row][col] != tab[row][col] && tab[row][col] != 0)) {
		return;
	} else {
		walk(row + 1, col, moves + 1);
		try[row][col] = moves;
		try[row + 1][col] = tab[row + 1][col]; /* restore */

		walk(row - 1, col, moves + 1);
		try[row][col] = moves;
		try[row - 1][col] = tab[row - 1][col];

		walk(row, col + 1, moves + 1);
		try[row][col] = moves;
		try[row][col + 1] = tab[row][col + 1];

		walk(row, col - 1, moves + 1);
		try[row][col] = moves;
		try[row][col - 1] = tab[row][col - 1];
	}
	print_try();
}

void print_try(void)
{
	int i, j;
	for (i = 0; i < SIZE + 2; i++) {
		for (j = 0; j < SIZE + 2; j++) {
			printf("%3d ", try[i][j]);
		}
		printf("\n");
	}
}

void reset_try(void)
{
	int i, j;
	for (i = 1; i < SIZE+1; i++) {
		for (j = 1; j < SIZE+1; j++) {
			try[i][j] = tab[i][j];
		}
	}
}

void print_tab(void)
{
	int i, j;
	for (i = 0; i < SIZE + 2; i++) {
		for (j = 0; j < SIZE + 2; j++) {
			printf("%3d ", tab[i][j]);
		}
		printf("\n");
	}
}

void padding(void)
{
	int i;
	/* top */
	for (i = 0; i < SIZE + 2; i++)
		tab[0][i] = -1;
	/* left */
	for (i = 0; i < SIZE + 2; i++)
		tab[i][0] = -1;
	/* right */
	for (i = 0; i < SIZE + 2; i++)
		tab[i][SIZE + 1] = -1;
	/* bottom */
	for (i = 0; i < SIZE + 2; i++)
		tab[SIZE + 1][i] = -1;
}

void fill_array(char *filename)
{
	FILE *fp;
	fp = fopen(filename, "rt");
	fscanf(fp, "%d", &SIZE);
	int i, j;
	for (i = 1; i < SIZE + 1; i++) {
		for (j = 1; j < SIZE + 1; j++) {
			fscanf(fp, "%d", &tab[i][j]);
		}
	}
	fclose(fp);
}

