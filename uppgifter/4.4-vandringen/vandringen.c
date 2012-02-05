#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXDEPTH 2

int TARGET_X;
int TARGET_Y;
int STEP_N;
int STEP_S;
int STEP_E;
int STEP_V;
int MINMOVE = INT_MAX;
int been_here[100][100];

struct tree {
	int level;
	int x;
	int y;
	struct tree *left;
	struct tree *right;
} *root;

void print_node(struct tree *);
void spawn_child(struct tree *);
int vandra(struct tree *);
void clear_mem(struct tree *);

int main(int argc, char *argv[])
{
	TARGET_X = 0;
	TARGET_Y = 0;
	STEP_N = 8;
	STEP_S = 3;
	STEP_E = 5;
	STEP_V = 6;
	int start_x = 36;
	int start_y = 27;
	if (argc > 3) {
		start_x = atoi(argv[1]);
		start_y = atoi(argv[2]);
	}
	struct tree root = {0, start_x, start_y, NULL, NULL};
	vandra(&root);
	clear_mem(&root);

	return 0;
}

int vandra(struct tree * node)
{
	print_node(node);
	if (node->level < MAXDEPTH) {
		spawn_child(node);
		vandra(node->left);
	}
	return 0;
}

void spawn_child(struct tree * node)
{
	node->left = malloc(sizeof(struct tree));
	node->left->level = node->level + 1;
	node->left->x = node->x;
	node->left->y = node->y;
	node->left->left = NULL;
	node->left->right = NULL;
}

void clear_mem(struct tree * node)
{
	if (node->level != 0) {
		clear_mem(node->left);
	}
	free(node);
}

void print_node(struct tree * node)
{
	printf("Node\t%p\t", node);
	printf("Level\t%d\tx %2d y %2d\n", node->level, node->x, node->y);
}

