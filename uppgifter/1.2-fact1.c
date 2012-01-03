#include <stdio.h>
#include <stdlib.h>

int fact(int n);

int main(int argc, char *argv[])
{
	printf("%d\n", fact(atoi(argv[1])));
	return 0;
}

int fact(int n)
{
	int i, p;
	p = 1;

	for (i = 1; i <= n; i += 1)
		p *= i;

	return p;
}

