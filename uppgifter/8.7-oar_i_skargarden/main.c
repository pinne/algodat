#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDEBUG

#define LAND 'x'
#define WATER 'o'

char **MAP;
int TOTAL_ISLANDS;

void count_islands(int rows, int cols);
void flood(int rows, int cols, int maxrow, int maxcol);
void load_map(char [], int *, int *);
void clean_up_map(int);
void print_map(int, int);

int main(int argc, char *argv[])
{
	TOTAL_ISLANDS = 0;
	int rows;
	int cols;
	load_map(argv[1], &rows, &cols);
#ifndef NDEBUG
	print_map(rows, cols);
#endif
	count_islands(rows, cols);
	printf("%d islands\n", TOTAL_ISLANDS);

	clean_up_map(rows);

	return 0;
}

void count_islands(int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i += 1) {
		int j;
		for (j = 0; j < rows; j += 1) {
			if (MAP[i][j] == LAND) {
				flood(i, j, rows, cols);
				TOTAL_ISLANDS += 1;
			}
		}
	}
}

void flood(int row, int col, int maxrow, int maxcol)
{
	if (MAP[row][col] == LAND) {
		MAP[row][col] = WATER;
		if (row > 0 && MAP[row - 1][col] != WATER) {
			flood(row - 1, col, maxrow, maxcol);
		}
		if (col > 0 && MAP[row][col - 1] != WATER) {
			flood(row, col - 1, maxrow, maxcol);
		}
		if (row + 1 < maxrow && MAP[row + 1][col] != WATER) {
			flood(row + 1, col, maxrow, maxcol);
		}
		if (col + 1 < maxcol && MAP[row][col + 1] != WATER) {
			flood(row, col + 1, maxrow, maxcol);
		}
	}
}

void load_map(char filename[], int *rows, int *cols)
{
	FILE *fp;
	fp = fopen(filename, "rt");

	/* get dimensions */
	fscanf(fp, "%d %d\n", rows, cols);
#ifndef NDEBUG
	printf("%d rows %d cols\n", *rows, *cols);
#endif

	/* alloc mem for map */
	MAP = malloc(*rows * sizeof(char *));
	int i;
	for (i = 0; i < *rows; i += 1) {
		MAP[i] = malloc(*cols * sizeof(char) + 2);
	}

	/* fill map */
	for (i = 0; i < *rows; i += 1) {
		fscanf(fp, "%s", MAP[i]);
		MAP[i][*cols] = '\n';
	}
	fclose(fp);
}

void clean_up_map(int rows)
{
	int i;
	for (i = 0; i < rows; i += 1)
		free(MAP[i]);
	free(MAP);
}

void print_map(int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i += 1) {
		int j;
		for (j = 0; j < cols; j += 1) {
			printf("%c", MAP[i][j]);
		}
		printf("\n");
	}
}
