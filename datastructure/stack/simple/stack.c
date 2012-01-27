#include "stack.h"
#include <string.h>

static char stack[64];
static int plats = -1;

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
	return (plats == 63);
}

