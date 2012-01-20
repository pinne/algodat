#include <stdio.h>
#include <stdlib.h>

#define MAXTRADE 15
int MINTRADE;

void trade(int blue, int white, int red, int n)
{
	if (blue == white && blue == red) {
		if (n < MINTRADE + 1)
			MINTRADE = n;
	} else if (n < MINTRADE + 1) {
		if (blue > 0)
			trade(blue - 1, white + 3, red + 1, n + 1);
		if (white > 0)
			trade(blue + 3, white - 1, red + 4, n + 1);
		if (red > 0)
			trade(blue + 2, white + 2, red - 1, n + 1);
	}
}

int main(int argc, char *argv[])
{
	MINTRADE = MAXTRADE;
	int blue  = atoi(argv[1]);
	int white = atoi(argv[2]);
	int red   = atoi(argv[3]);

	trade(blue, white, red, 0);

	if (MINTRADE < MAXTRADE + 1)
		printf("%d", MINTRADE);
	printf("\n");

	return 0;
}

