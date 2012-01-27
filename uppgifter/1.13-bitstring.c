#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rpow(int i, int e);

void bitstr(char *str, int pos, int len)
{
	if (pos / 2 < rpow(len, 2) + 1) {
		if (pos % len == 0 && pos > 0)
			strcat(str, ", ");

		if (str[pos - len] == 0)
			bitstr(strcat(str, "1"), pos + 1, len);
		else
			bitstr(strcat(str, "0"), pos + 1, len);
	}
}

int main(int argc, char *argv[])
{
	int len = atoi(argv[1]);
	char *str;
	str = malloc(2 + rpow(len, 2) * 3 * sizeof(char));
	str[0] = '\0';

	bitstr(str, 0, len);
	printf("%s\n", str);
	free(str);

	return 0;
}

int rpow(int i, int e)
{
	if (e-- == 0)
		return 1;
	else
		return i * rpow(i, e);
}

