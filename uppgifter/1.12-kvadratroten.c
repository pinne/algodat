#include <stdio.h>
#include <stdlib.h>

#define ABS(val) ((val) < 0) ? -(val) : (val) 

float rot(float n, float a, float e);

int main(int argc, char *argv[])
{
	float n;
	float e;
	n = atof(argv[1]);
	e = atof(argv[2]);

	printf("%f", rot(n, 1, e));
	printf("\n");

	return 0;
}

float rot(float n, float a, float e)
{
	if ((ABS(a*a - n)) < e)
		return a;
	else
		return (float)rot(n, (a*a+n) / (2*a), e);
}

