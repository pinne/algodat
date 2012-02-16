#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int test1(int);
int test2(int);
int test3(int);
int test4(int);
int test5(int);

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < MAX; i += 1) {
		int count = 0;
		if (test1(i) == 0)
			count += 1;
		if (test2(i) == 0)
			count += 1;
		if (test3(i) == 0)
			count += 1;
		if (test4(i) == 0)
			count += 1;
		if (test5(i) == 0)
			count += 1;
		if (count == 3)
			printf("%d\n", i);
	}
	return 0;
}

int test1(int n)
{
	if (3 * n > 35)
		return 0;
	else
		return 1;
}
int test2(int n)
{
	if (7 * n >= 43)
		return 0;
	else
		return 1;
}
int test3(int n)
{
	if (2 * n <= 99)
		return 0;
	else
		return 1;
}
int test4(int n)
{
	if (n >= 21)
		return 0;
	else
		return 1;
}
int test5(int n)
{
	if (5 * n >= 51)
		return 0;
	else
		return 1;
}
