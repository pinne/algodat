#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(int argc, char *argv[])
{
	int i;
	int n;
	int count = 0;
	n = atoi(argv[1]);

	for (i = 1; i <= n; i += 1)
		if (gcd(i, n) == 1)
			count++;

	printf("%d\n", count);

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

