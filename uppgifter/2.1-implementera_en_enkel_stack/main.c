#include "stack.h"
#include <stdio.h>

int main(void) {
	if (!isfull())
		push('S');
	if (!isfull())
		push('i');
	if (!isfull())
		push('m');
	if (!isfull())
		push('o');
	if (!isfull())
		push('n');

	while(!isempty())
		printf("%c", pop());    

	printf("\n");

	return 0;
}

