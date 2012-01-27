#include <stdio.h>
#include <stdlib.h>

#define MAXMOVE 128
int MINMOVE;
int FLOORS;
int UPWARD;
int DOWNWARD;
int TARGET;

void elevator(int pos, int n);
void print_usage(char *name);

int main(int argc, char *argv[])
{
	if (argc <= 4) {
		print_usage(argv[1]);
		return -1;
	}

	MINMOVE  = MAXMOVE;
	FLOORS   = atoi(argv[1]);
	UPWARD   = atoi(argv[2]);
	DOWNWARD = atoi(argv[3]);
	TARGET   = atoi(argv[4]);

	elevator(1, 0);

	if (MINMOVE < MAXMOVE)
		printf("%d\n", MINMOVE);

	return 0;
}

void elevator(int pos, int n)
{
	if (pos == TARGET) {
		if (n < MINMOVE + 1)
			MINMOVE = n;
	} else if (n < MINMOVE) {
		if (pos + UPWARD <= FLOORS)
			elevator(pos + UPWARD, n + 1);
		if (pos - DOWNWARD >= 1)
			elevator(pos - DOWNWARD, n + 1);
	}
}

void print_usage(char *name)
{
	printf("USAGE: %s <floors> <up> <down> <target>", name);
	printf("\n");
}

