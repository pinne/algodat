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

struct tree {
	int level;
	int x;
	int y;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
};

void print_node(struct tree *);
struct tree *spawn_child(struct tree *, struct tree *);
void traverse(struct tree *);
void clear_children(struct tree *);

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
	struct tree root = { 0, start_x, start_y, NULL, NULL, NULL };
	traverse(&root);
	clear_children(&root);

	return 0;
}

int create_tree(struct tree * node)
{
	print_node(node);
	if (node->level < MAXDEPTH) {
		node->left = spawn_child(node, node->left);
		create_tree(node->left);
		node->right = spawn_child(node, node->right);
		create_tree(node->right);
	}
	return 0;
}

void traverse(struct tree * node)
{
	int level = node->level;
	create_tree(node);

	while (level < MAXDEPTH) {

		level += 1;
	}
}

struct tree *spawn_child(struct tree *node, struct tree *leaf)
{
	leaf = malloc(sizeof(struct tree));
	leaf->level = node->level + 1;
	leaf->x = node->x;
	leaf->y = node->y;
	leaf->parent = node;
	leaf->left = NULL;
	leaf->right = NULL;
	print_node(leaf);
	return leaf;
}

void clear_children(struct tree *node)
{
	if (node->level > 0) {
		if (node->left != NULL)
			clear_children(node->left);
		if (node->right != NULL)
			clear_children(node->right);
		free(node);
	} else if (node->level == 0) {
		clear_children(node->left);
		clear_children(node->right);
	}
}

void print_node(struct tree *node)
{
	printf("Node\t%p\t", node);
	printf("Level\t%d\tx %2d y %2d\t parent %p\n",
			node->level, node->x, node->y, node->parent);
}

