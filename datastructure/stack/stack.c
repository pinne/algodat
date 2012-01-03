#include "stack.h"
#include <string.h>

void push(char c)
{
	stack[++plats] = c;
}

char pop(void)
{
	return stack[plats--];
}

int isempty(void)
{
	return plats == -1;
}

int isfull(void)
{
	return !(plats == 63);
}

