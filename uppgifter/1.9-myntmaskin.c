#include <stdio.h>
#include <stdlib.h>

#define MAXSUM 99999

int find_score(int target, int point, int sum, int* minsum, int coin);

int main(int argc, char *argv[])
{
	int target;
	int minsum = MAXSUM;
	int* ptr_ms = &minsum;
	target = atoi(argv[1]);

	find_score(target, 1, 0, ptr_ms, 0);

	if (minsum < MAXSUM) {
		printf("%d", minsum);
		printf("\n");
	}

	return 0;
}

int find_score(int target, int point, int sum, int* minsum, int coin)
{
	if (point == target) {
		if (sum < *minsum) {
			*minsum = sum;
		}
		return 0;
	} else if (point > target) {
		return 0;
	}
	if (coin == 5)
		point += 4;
	if (coin == 10)
		point *= 3;
	sum += coin;

	find_score(target, point, sum, minsum, 5);
	find_score(target, point, sum, minsum, 10);
	return 0;
}

