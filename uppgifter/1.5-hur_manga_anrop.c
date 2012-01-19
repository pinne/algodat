#include <stdio.h>
#include <stdlib.h>

int CALL_COUNT;

int antal_vagar(int m, int n);

int main(int argc, char *argv[])
{
	int m;
	int n;
	m = atoi(argv[1]);
        n = atoi(argv[2]);

	CALL_COUNT = 0;

	printf("%d\n", antal_vagar(m, n));
	printf("%d calls\n", CALL_COUNT);

	return 0;
}

int antal_vagar(int m, int n)
{
	int v = 0;
	CALL_COUNT += 1;

	if (m == 0 || n == 0) {
//	if (m == 0 && n == 0) {
		return 1;
	} else {
		if (m > 0)
			v += antal_vagar(m-1, n);
		if (n > 0)
			v += antal_vagar(m, n-1);

		return v;
	}
}

