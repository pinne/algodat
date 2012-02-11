#include "tree.h"
#include <assert.h>

int main(int argc, char *argv[])
{
	struct tree *root = malloc(sizeof(struct tree));

	create_tree(root, 5);
	traverse_preorder(root);

	int nodes = 1;
	nnodes(root, &nodes);
	printf("nodes %d\n", nodes);

	int leaves = 0;
	nleaves(root, &leaves);
	printf("leaves %d\n", leaves);

	return 0;
}

void create_tree(struct tree *node, int depth)
{
	if (node->level < depth) {
		node->left = spawn_child(node, node->left);
		create_tree(node->left, depth);
		node->right = spawn_child(node, node->right);
		create_tree(node->right, depth);

#ifndef TWO_DIMENSION
		node->up = spawn_child(node, node->up);
		create_tree(node->up, depth);
		node->down = spawn_child(node, node->down);
		create_tree(node->down, depth);
#endif
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
#ifndef TWO_DIMENSION
	leaf->up = NULL;
	leaf->down = NULL;
#endif
	return leaf;
}

void clear_children(struct tree *node)
{
	if (node->level > 0) {
		if (node->left != NULL)
			clear_children(node->left);
		if (node->right != NULL)
			clear_children(node->right);
#ifndef TWO_DIMENSION
		if (node->up != NULL)
			clear_children(node->up);
		if (node->down != NULL)
			clear_children(node->down);
#endif
		free(node);
	} else if (node->level == 0) {
		clear_children(node->left);
		clear_children(node->right);
#ifndef TWO_DIMENSION
		clear_children(node->up);
		clear_children(node->down);
#endif
	}
}

void print_node(struct tree *node)
{
	printf("Node%12p   ", node);
	printf("Level%3d   x %2d y %2d  parent %12p\n",
	       node->level, node->x, node->y, node->parent);
}

/*
 * count total number of leaves from node
 */
void nleaves(struct tree *node, int *n)
{
	if (node->left == NULL && node->right == NULL) {
		*n += 1;
		return;
	}
	if (node->left != NULL)
		nleaves(node->left, n);
	if (node->right != NULL)
		nleaves(node->right, n);
}

/*
 * count total number of nodes below node
 */
void nnodes(struct tree *node, int *n)
{
	if (node->left != NULL) {
		*n += 1;
		nnodes(node->left, n);
	}
	if (node->right != NULL) {
		*n += 1;
		nnodes(node->right, n);
	}
}

void traverse_preorder(struct tree *node)
{
	if (node == NULL)
		return;
	print_node(node);
	traverse_preorder(node->left);
	traverse_preorder(node->right);
#ifndef TWO_DIMENSION
	traverse_preorder(node->up);
	traverse_preorder(node->down);
#endif
}

void traverse_inorder(struct tree *node)
{
	if (node == NULL)
		return;
	traverse_inorder(node->left);
	print_node(node);
	traverse_inorder(node->right);
#ifndef TWO_DIMENSION
	traverse_inorder(node->up);
	traverse_inorder(node->down);
#endif
}

void traverse_postorder(struct tree *node)
{
	if (node == NULL)
		return;
	traverse_postorder(node->left);
	traverse_postorder(node->right);
#ifndef TWO_DIMENSION
	traverse_postorder(node->up);
	traverse_postorder(node->down);
#endif
	print_node(node);
}
