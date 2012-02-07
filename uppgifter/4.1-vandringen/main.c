#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NDEBUG
#define MAXTREEDEPTH 20

int TARGET_X;
int TARGET_Y;
int STEP_N;
int STEP_S;
int STEP_E;
int STEP_W;
int MINMOVE = INT_MAX;
int VISITED[100 * 4][100 * 4];

void vandringen(int start_x, int start_y);
int test_node(struct queue *);
void reset_VISITED(void);

int main(int argc, char *argv[])
{
	TARGET_X = 0;
	TARGET_Y = 0;
	STEP_N = 8;
	STEP_S = 3;
	STEP_E = 5;
	STEP_W = 6;
	int start_x = 36;
	int start_y = 27;
	if (argc > 3) {
		start_x = atoi(argv[1]);
		start_y = atoi(argv[2]);
	}
	vandringen(start_x, start_y);

	return 0;
}

void vandringen(int start_x, int start_y)
{
	init_queue();

	struct queue *root = malloc(sizeof(struct queue));
	root->x = start_x;
	root->y = start_y;
	root->level = 0;
	enqueue(root);

	struct queue *node;

	reset_VISITED();
	while (queue_len() > 0 && test_node(node) != 0) {
		node = dequeue();
#ifndef NDEBUG
		print_element(node);
#endif
		struct queue *north = malloc(sizeof(struct queue));
		north->x = node->x;
		north->y = node->y + STEP_N;
		north->level = node->level + 1;
		breadcrumb(north);

		struct queue *south = malloc(sizeof(struct queue));
		south->x = node->x;
		south->y = node->y - STEP_S;
		south->level = node->level + 1;
		breadcrumb(south);

		struct queue *east = malloc(sizeof(struct queue));
		east->x = node->x + STEP_E;
		east->y = node->y;
		east->level = node->level + 1;
		breadcrumb(east);

		struct queue *west = malloc(sizeof(struct queue));
		west->x = node->x - STEP_W;
		west->y = node->y;
		west->level = node->level + 1;
		breadcrumb(west);
	}

	printf("%d\n", node->level);
	clear_queue();

}

int test_node(struct queue *node)
{
	return (node->x != TARGET_X || node->y != TARGET_Y);
}

void clear_queue(void)
{
	while (queue_len() > 0) {
		struct queue *node = dequeue();
		free(node);
	}
}

void breadcrumb(struct queue *node)
{
	if (node->level < VISITED[node->x + 200][node->y + 200]) {
		enqueue(node);
		VISITED[node->x + 200][node->y + 200] = node->level;
	} else {
		free(node);
	}
}

void reset_VISITED(void)
{
	int i;
	int j;
	for (i = 0; i < 400; i++)
		for (j = 0; j < 400; j++) {
			VISITED[i][j] = MAXTREEDEPTH;
		}

}
