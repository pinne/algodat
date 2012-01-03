#include <stdio.h>
#include <stdlib.h>

int CALL_COUNT;

int binomkoeff(int n, int m);

int main(int argc, char *argv[])
{
	int n, m;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	CALL_COUNT = 0;	

	printf("%d\n", binomkoeff(n, m));
	printf("%d calls\n", CALL_COUNT);

	return 0;
}

int binomkoeff(int n, int m)
{
	CALL_COUNT += 1;
	if (n == 0 || m == 0 || m == n)
		return 1;
	else if (m == 1)
		return n;
	else
		return binomkoeff(n-1, m) + binomkoeff(n-1, m - 1);
}

