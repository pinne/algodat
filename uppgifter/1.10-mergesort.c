#include <stdio.h>
#include <stdlib.h>

int cost(int n);

int main(int argc, char *argv[])
{
	int n;
	n = atoi(argv[1]);

	printf("%d", cost(n));
	printf("\n");

	return 0;
}

int cost(int n)
{
	if (n == 1) {
		return 0;
	} else {
		return cost((n+2-1) / 2) + cost(n / 2) + n - 1;
	}
}

