#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT
#define SIZE 3

/*
 * http://www.wolframalpha.com/input/?i=Fit[{{0%2C+0}%2C+{1%2C+1}%2C{5%2C+15}%2C{7%2C+149}%2C{8%2C+512}%2C{10%2C+8042}%2C{12%2C+164246}}%2C{1%2Cn%2Cn^2%2Cn^3%2Cn^4}%2Cn]
 */ 
int kolumn[SIZE] = { 0, 0, 0, 0, 0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,0, 0, 0, 0,             0, 0, 0, 0, 0, 0 };
int kolfri[SIZE] = { 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,            1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,1, 1, 1, 1, 1,       1, 1, 1, 1, 1, 1, 1 };
int uppfri[SIZE*2-1] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int nerfri[SIZE*2-2] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int antal = 0;
int exec = 0;

unsigned long long int identifier(void)
{
	int i;
	int id = 0;
	for (i = 0; i < SIZE; i += 1) {
              id += kolumn[i] * pow(2, i);
	}
	return id;
}

void SkrivUt(void)
{
#ifndef NPRINT
	char board[SIZE][SIZE];

	int i;
	for (i = 0; i < SIZE; i += 1) {
		int j;
		for (j = 0; j < SIZE; j += 1) {
			board[i][j] = '·';
		}
	}
	for (i = 0; i < SIZE; i += 1) {
		board[i][kolumn[i]] = '0';
	}
	for (i = 0; i < SIZE; i += 1) {
		int j;
		for (j = 0; j < SIZE; j += 1) {
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
#endif
	printf("id %Ld\n", identifier());
}

void AddQueen(int rad)
{
	int kol;
	rad++;
	exec++;
	for (kol = 1; kol < SIZE; kol++)
		if (kolfri[kol] && uppfri[rad + kol]
				&& nerfri[rad - kol + SIZE-1]) {
			kolumn[rad] = kol;
			kolfri[kol] = 0;
			uppfri[rad + kol] = 0;
			nerfri[rad - kol + SIZE-1] = 0;
			if (rad == SIZE-1) {
				SkrivUt();
				antal += 1;
			}
			else
				AddQueen(rad);
			kolfri[kol] = 1;
			uppfri[rad + kol] = 1;
			nerfri[rad - kol + SIZE-1] = 1;
		}
	rad--;
}

int main(void)
{
	AddQueen(0);
	printf("Antal lösningar %d\n", antal);
	printf("{%d, %d}\n", SIZE, exec);
	return 0;
}
