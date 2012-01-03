#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMOVE 16

int move(char boxen[], int moves, int* minmove, char type);

int main(int argc, char *argv[])
{
	int minmove = MAXMOVE;
	int* ptr_mm = &minmove;

	move(argv[1], 0, ptr_mm, 'q');

	if (minmove <= MAXMOVE) {
		printf("MIN MOVES: %d", minmove);
		printf("\n");
	}

	return 0;
}

int move(char boxen[], int moves, int* minmove, char type)
{
	printf("%s, m:%d\n", boxen, moves);

	if (strcmp(boxen, "ABCDE") == 0) {
		if (moves < *minmove) {
			*minmove = moves;
			printf("minmove %d\n", *minmove);
		}
		return 0;
	} else if (moves >= *minmove) {
		return 0;
	} else {
		char tmp;
		if (type == 'b') {
			/* swap two first */
			tmp = boxen[1];
			boxen[1] = boxen[0];
			boxen[0] = tmp;
		} else if (type == 's') {
			/* shift right */
			tmp = boxen[4];
			boxen[4] = boxen[3];
			boxen[3] = boxen[2];
			boxen[2] = boxen[1];
			boxen[1] = boxen[0];
			boxen[0] = tmp;
		}
		moves += 1;

		move(boxen, moves, minmove, 'b');
		move(boxen, moves, minmove, 's');
	}
	return 0;
}

