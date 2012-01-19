#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMOVE 18
int MINMOVE;

int move(char boxen[], char orig[], int moves);//, char type);
void shift_right(char boxen[], int i);

int main(int argc, char *argv[])
{
	MINMOVE = MAXMOVE;
	char last[6] = "ABCDE";
	move(argv[1], last, 0);//, 'q');

	if (MINMOVE <= MAXMOVE) {
		printf("MIN MOVES: %d", MINMOVE);
		printf("\n");
	}

	return 0;
}

int match(char boxen[], char orig[], int moves)
{
	if (strcmp(boxen, "ABCDE") == 0) {
		if (moves < MINMOVE) {
			MINMOVE = moves;
			printf("minmove %d\n", MINMOVE);
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

int move(char boxen[], char last[], int moves)//, char type)
{
	strcpy(last, boxen);

	if (strcmp(boxen, "ABCDE") == 0) {
		if (moves < MINMOVE) {
			MINMOVE = moves;
		}
		return 0;
	} else if (moves < MINMOVE) {
		swap_first(boxen);
		move(boxen, last, moves + 1);
		swap_first(boxen);

		shift_right(boxen, 1);
		move(boxen, last, moves + 1);
		shift_right(boxen, 4);
	}
	return 0;
}

