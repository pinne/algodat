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
	if (n == 0)
		return 1;
	else
		return n * (fact(n - 1));
}

