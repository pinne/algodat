#include <stdio.h>
#include <stdlib.h>

int siffersumma(int t, int r);

int main(int argc, char *argv[])
{
	int t;
	t = atoi(argv[1]);

	printf("%d\n", siffersumma(t, 0));

	return 0;
}

int siffersumma(int t, int r)
{
	if (t == 0)
		return r;
	else
		return siffersumma(t/10, r + t%10);
}

