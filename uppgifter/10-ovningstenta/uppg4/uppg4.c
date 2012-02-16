#include <stdio.h>
#include <stdlib.h>

#define STORLEK 10
int tab[STORLEK][STORLEK];
int sum[STORLEK];

int max = 0;

void print_tab(void);
void fill_array(char*);
void fall_down(int, int, int);
void append(int, int);

int main(void)
{
	fill_array("pyramid1.txt");
	fall_down(0, 0, 0);
	fill_array("pyramid2.txt");
	fall_down(0, 0, 0);

	return 0;
}

void test()
{
	int i;
	int left = STORLEK;
	int try[STORLEK];
	for (i = 0; i < STORLEK; i += 1)
		try[i] = -1;
	for (i = 0; i < STORLEK; i += 1) {
		try[sum[i]] = 0;
	}
	for (i = 0; i < STORLEK; i += 1)
		if (try[i] == 0)
			left -= 1;

	if (left == 0) {
		for (i = 0; i < STORLEK; i += 1) {
			printf("%d", sum[i]);
		}
		printf("\n");
	}

}

void append(int n, int len)
{
	sum[len] = n;
}

void fall_down(int row, int col, int len)
{
	if (len <= STORLEK) {
		append(tab[row][col], len);
		fall_down(row + 1, col, len + 1);
		fall_down(row + 1, col + 1, len + 1);
		test(sum);
	}
}

void print_tab(void)
{
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			printf("%3d ", tab[i][j]);
		}
		printf("\n");
	}
}

void fill_array(char *filename)
{
	FILE *fp;
	fp = fopen(filename, "rt");
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			fscanf(fp, "%d", &tab[i][j]);
		}
	}
	fclose(fp);
}

