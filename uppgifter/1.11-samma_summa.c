#include <stdio.h>
#include <stdlib.h>

int part(int n, int m);

int main(int argc, char *argv[])
{
	int n, m;
	n = atoi(argv[1]);
	m = atoi(argv[2]);

	printf("%d", part(n, m));
	printf("\n");

	return 0;
}

int part(int n, int m)
{
	if ((n == 1 && m >= 0) || m == 0 || m == 1)
		return 1;
	else if (m < 0)
		return 0;
	else
		return part(n-1, m) + part(n, m-n);
}

