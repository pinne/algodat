#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct stackinfo{
	int  plats;
	char *stackadr;
};

typedef struct stackinfo stackinfo;

static stackinfo *stack;
static int antal, size;


void Push(int nr, void *x){
	assert(stack[nr].plats < antal - 1);
	stack[nr].plats++;

	memcpy(stack[nr].stackadr + stack[nr].plats * size, x, size);
}

void *Pop(int nr){
	void *p;
	assert(stack[nr].plats >= 0);

	p = stack[nr].stackadr + (stack[nr].plats) * size;
	stack[nr].plats--;

	return p;
}

int IsEmpty(int nr){
	return (stack[nr].plats == -1);
}

int IsFull(int nr){
	return (stack[nr].plats == antal);
}

void InitStack(int antalstackar, int storlek, int maxantal) {
	int i;
	size  = storlek;
	antal = maxantal;
	stack = (stackinfo *)calloc(antal,sizeof(stackinfo));

	for (i = 0; i < antal; i++){
		stack[i].plats = -1;
		stack[i].stackadr = (char *)calloc(antalstackar, sizeof(storlek));
	}
}

void FreeStack(void){
	int i;
	for (i = 0; i < antal; i++)
		free(stack[i].stackadr);

	free(stack);
}

