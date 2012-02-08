#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSUM INT_MAX
#define SIZE 1000000

int MINSUM;
int TARGET;
int BEST[SIZE];

void find_score(int, int);
void reset_array(void);

int main(int argc, char *argv[])
{
	TARGET = atoi(argv[1]);
	MINSUM = MAXSUM;
	reset_array();

	find_score(1, 0);

	if (MINSUM < MAXSUM) {
		printf("%d", MINSUM);
		printf("\n");
	}

	return 0;
}

void find_score(int point, int sum)
{
	/* backtracking */
	if (sum >= BEST[point]) {
		return;
	} else {
		BEST[point] = sum;
	}

	if (point == TARGET) {
		if (sum < MINSUM) {
			MINSUM = sum;
		}
		return;
	} else if (point > TARGET) {
		return;
	}
	find_score(point + 4, sum + 5);
	find_score(point * 3, sum + 10);
}

void reset_array(void)
{
	int i;
	for (i = 0; i < SIZE; i += 1) {
		BEST[i] = INT_MAX;
	}
}
