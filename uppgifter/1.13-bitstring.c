#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bitstr(char str[], int k, int len);

int main(int argc, char *argv[])
{
	int val = 0;
	int len;
	len = atoi(argv[1]);

	int i;
	char str[64];
	str[0] = '\0';

	bitstr("", 0, len);

	return 0;
}

void bitstr(char str[], int k, int len)
{
	if (str[len] == '0') {
		str[len] = '1';
	} else {
		str[len] = '0';
		str[len]
	}

	if (
	bitstr(strcat(s, "0"), k+1, len);
}

