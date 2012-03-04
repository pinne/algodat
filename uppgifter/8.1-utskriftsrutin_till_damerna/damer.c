#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NPRINT

void AddQueen(int rad, int size);
unsigned long long int identifier(int size);
void fill_array(int array[], int item, int len);
void SkrivUt(int size);

int *kolumn;
int *kolfri;
int *uppfri;
int *nerfri;

int ANTAL = 0;
int EXEC;

int main(void)
{
	int size;
	char solutions[1000] = "{";
	for (size = 1; size < 14; size += 1) {
		EXEC = 0;
		kolumn = malloc(sizeof(int) * size);
		kolfri = malloc(sizeof(int) * size);
		uppfri = malloc(sizeof(int) * (size * 2) - 0);
		nerfri = malloc(sizeof(int) * (size * 2) - 0);
		fill_array(kolumn, 0, size);
		fill_array(kolfri, 1, size);
		fill_array(uppfri, 1, size*2);
		fill_array(nerfri, 1, size*2);
		AddQueen(0, size);
#ifndef NPRINT
		printf("Antal lösningar %d\n", ANTAL);
		printf("{%d, %d}\n", size, EXEC);
#endif
		sprintf(solutions, "%s{%d, %d}, ", solutions, size, EXEC);
		free(kolumn);
		free(kolfri);
		free(uppfri);
		free(nerfri);
	}
	solutions[strlen(solutions) - 2] = '\0';
	strcat(solutions, "}");
	printf("%s\n", solutions);
	return 0;
}

void AddQueen(int rad, int size)
{
	int kol;
	rad++;
	EXEC += 1;
	for (kol = 1; kol < size; kol++) {
		if (kolfri[kol] && uppfri[rad + kol]
				&& nerfri[rad - kol + size-1]) {
			kolumn[rad] = kol;
			kolfri[kol] = 0;
			uppfri[rad + kol] = 0;
			nerfri[rad - kol + size-1] = 0;
			if (rad == size-1) {
				SkrivUt(size);
				ANTAL += 1;
			} else {
				AddQueen(rad, size);
			}
			kolfri[kol] = 1;
			uppfri[rad + kol] = 1;
			nerfri[rad - kol + size-1] = 1;
		}
	}
	rad--;
}

void SkrivUt(int size)
{
	char board[100][100];

	int i;
	for (i = 0; i < size; i += 1) {
		int j;
		for (j = 0; j < size; j += 1) {
			board[i][j] = '·';
		}
	}
	for (i = 0; i < size; i += 1) {
		board[i][kolumn[i]] = '0';
	}
#ifndef NPRINT
	for (i = 0; i < size; i += 1) {
		int j;
		for (j = 0; j < size; j += 1) {
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
	printf("id %Ld\n", identifier(size));
#endif
}

unsigned long long int identifier(size)
{
	int i;
	int id = 0;
	for (i = 0; i < size; i += 1) {
		id += kolumn[i] * pow(2, i);
	}
	return id;
}

void fill_array(int array[], int item, int len)
{
	int i;
	for (i = 0; i < len; i += 1)
		array[i] = item;
}

