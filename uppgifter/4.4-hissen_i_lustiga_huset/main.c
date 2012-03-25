#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXMOVE 128
int MINMOVE;
int FLOORS;
int UPWARD;
int DOWNWARD;
int TARGET;

void elevator(int pos, int n);
void print_usage(char *name);
void bfs_elevator(int pos, int moves);

int main(int argc, char *argv[])
{
	if (argc <= 4) {
		print_usage(argv[1]);
		return -1;
	}

	MINMOVE  = MAXMOVE;
	FLOORS   = atoi(argv[1]);
	UPWARD   = atoi(argv[2]);
	DOWNWARD = atoi(argv[3]);
	TARGET   = atoi(argv[4]);

	bfs_elevator(1, 0);

	if (MINMOVE < MAXMOVE)
		printf("%d\n", MINMOVE);

	return 0;
}

void bfs_elevator(int pos, int moves)
{
	init_queue();

	struct queue *root = malloc(sizeof(struct queue));
	root->val = 1;
	root->moves = 0;
	enqueue(root);

	struct queue *node;

	while (1) {
		node = dequeue();

		if (node->val == TARGET) {
			printf("%d\n", node->moves);
			free(node);
			break;
		}
		/* move down */
		if (node->val - DOWNWARD > 1) {
			struct queue *down;
			down = malloc(sizeof(struct queue));
			down->val = node->val - DOWNWARD;
			down->moves = node->moves + 1;
			enqueue(down);
		}

		/* move up */
		if (node->val + UPWARD <= FLOORS) {
			struct queue *up;
			up = malloc(sizeof(struct queue));
			up->val = node->val + UPWARD;
			up->moves = node->moves + 1;
			enqueue(up);
		}
	}
	printf("\n");
	free(root);
}

void print_usage(char *name)
{
	printf("USAGE: %s <floors> <up> <down> <target>", name);
	printf("\n");
}

