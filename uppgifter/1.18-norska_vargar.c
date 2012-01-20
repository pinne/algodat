#include <stdio.h>
#include <stdlib.h>

#define TARGET 42

int last_prod(int n)
{
	int ten = n % 100 / 10;
	int one = n % 10;
	if (ten == 0 || one == 0)
		return 0;
	else
		return ten * one;
}

void kill(int n)
{
	if (n == TARGET) {
		printf("Målet kan nås\n");
		exit(0);
	} else if (n > TARGET) {
		if (n % 2 == 0)
			kill(n / 2);
		if (n % 3 == 0 || n % 4 == 0)
			if (last_prod(n) > 0)
				kill(n - last_prod(n));
		if (n % 5 == 0)
			kill(n - 42);
	}
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	if (argc == 3) {
		printf("%d\n", last_prod(atoi(argv[2])));
		exit(0);
	}

	kill(n);
	printf("Målet kan inte nås\n");
	return 0;
}

