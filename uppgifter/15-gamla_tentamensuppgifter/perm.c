#include <stdio.h>

void permute(int a[], int len, int v[], int p)
{
	int i;
	if (len == p) {
		for (i = 0; i < len; i++)
			printf("%d ", a[i]);
		printf("\n");
	} else {
		for (i = 0; i < len; i++) {
			if (!v[i]) {
				v[i] = 1;
				a[p] = i;
				permute(a, len, v, p + 1);
				v[i] = 0;
			}
		}
	}
}

int main(void)
{
	int a[5];
        int v[5] = { 0 };
	int len = 3;

	permute(a, len, v, 0);

	return 0;
}

