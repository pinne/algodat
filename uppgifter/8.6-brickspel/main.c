#include <stdio.h>

#define MOVELIM 15
#define SIZE     7
#define EMPTY    0
#define WHITE    1
#define BLACK    2
#define ILLEGAL -1

int stack[100];
int stack_len = 0;

void push(int);
int  pop(void);
void print_stack(void);
void print_array(int array[]);
void move(int array[], int, int);
int  swap(int array[], int, int);
int  check(int array[]);

int main(void)
{
	int brick[SIZE + 2] = {
		ILLEGAL,	/* 0 */
		BLACK,		/* 1 */
		BLACK,		/* 2 */
		BLACK,		/* 3 */
		EMPTY,		/* 4 */
		WHITE,		/* 5 */
		WHITE,		/* 6 */
		WHITE,		/* 7 */
		ILLEGAL		/* 8 */
	};

	move(brick, 1, 0);

	return 0;
}

void move(int brick[], int to, int moves)
{
	if (check(brick) == 0) {
		printf("done in %d moves\n", moves);
		print_stack();
		return;
	} else if (moves < MOVELIM) {
		int from;
		for (from = 1; from <= SIZE; from += 1) {
			to = from + 1; /* one right */
			if ((brick[from] == WHITE || brick[from] == BLACK)
					&& brick[to] == EMPTY) {
				push(from);
				push(to);
				swap(brick, to, from);
				move(brick, to, moves + 1);
				swap(brick, to, from);
				pop();
				pop();
			}

			to = from - 1; /* one left */
			if ((brick[from] == WHITE || brick[from] == BLACK)
					&& brick[to] == EMPTY) {
				push(from);
				push(to);
				swap(brick, to, from);
				move(brick, to, moves + 1);
				swap(brick, to, from);
				pop();
				pop();
			}

			to = from + 2; /* two right */
			if ((brick[from] == WHITE || brick[from] == BLACK)
					&& brick[to] == EMPTY) {
				push(from);
				push(to);
				swap(brick, to, from);
				move(brick, to, moves + 1);
				swap(brick, to, from);
				pop();
				pop();
			}

			to = from - 2; /* two left */
			if ((brick[from] == WHITE || brick[from] == BLACK)
					&& brick[to] == EMPTY) {
				push(from);
				push(to);
				swap(brick, to, from);
				move(brick, to, moves + 1);
				swap(brick, to, from);
				pop();
				pop();
			}
		}
	}
}

int swap(int array[], int to, int from)
{
	int tmp = array[from];
	array[from] = array[to];
	array[to] = tmp;
	return 0;
}

void print_array(int arr[])
{
	int i;
	for (i = 1; i < SIZE + 1; i += 1)
		printf("%2d", arr[i]);
	printf("\n");
}

/*
 * returns 0 if finished
 */
int check(int array[])
{
	if (array[0] != ILLEGAL)
		return -1;
	if (array[1] != WHITE)
		return -1;
	if (array[2] != WHITE)
		return -1;
	if (array[3] != WHITE)
		return -1;
	if (array[4] != EMPTY)
		return -1;
	if (array[5] != BLACK)
		return -1;
	if (array[6] != BLACK)
		return -1;
	if (array[7] != BLACK)
		return -1;
	if (array[8] != ILLEGAL)
		return -1;
	return 0;
}

void push(int elem)
{
	stack[stack_len++] = elem;
}

int pop(void)
{
	if (stack_len > 0) {
		return stack[--stack_len];
	} else {
		return -1;
	}
}

void print_stack(void)
{
	while (stack_len > 0) {
		printf("%d ->", pop());
		printf(" %d\t", pop());
	}
	printf("\n");
}
