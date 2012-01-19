#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMOVE 32

int match(char boxen[], int moves, int* minmove);
void move(char boxen[], int moves, int* minmove);
void swap_first(char boxen[]);
void shift_right(char boxen[], int i);

int main(int argc, char *argv[])
{
	int minmove = MAXMOVE;
	int* mm_ptr = &minmove;
	move(argv[1], 0, mm_ptr);

	if (minmove < MAXMOVE) {
		printf("min moves %d", minmove);
		printf("\n");
	}

	return 0;
}

int match(char boxen[], int moves, int* minmove)
{
	if (strcmp(boxen, "ABCDE") == 0) {
		if (moves < *minmove) {
			*minmove = moves;
			printf("minmove %d\n", *minmove);
		}
		return 1;
	} else {
		return 0;
	}
}

void swap_first(char boxen[])
{
	char tmp = boxen[1];
	boxen[1] = boxen[0];
	boxen[0] = tmp;
}

void shift_right(char boxen[], int i)
{
	if (i-- > 0) {
		char tmp = boxen[4];
		boxen[4] = boxen[3];
		boxen[3] = boxen[2];
		boxen[2] = boxen[1];
		boxen[1] = boxen[0];
		boxen[0] = tmp;
		shift_right(boxen, i);
	}
}

void move(char boxen[], int moves, int* minmove)
{
	if (strcmp(boxen, "ABCDE") == 0) {
		if (moves < *minmove) {
			*minmove = moves;
		}
	} else if (moves < *minmove) {
		swap_first(boxen);
		move(boxen, moves + 1, minmove);
		swap_first(boxen);

		shift_right(boxen, 1);
		move(boxen, moves + 1, minmove);
		shift_right(boxen, 4);
	}
}

