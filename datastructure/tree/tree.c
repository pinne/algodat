#include "tree.h"
#include <assert.h>

int main(int argc, char *argv[])
{
	struct tree *root = malloc(sizeof(struct tree));

	create_tree(root, 5);
	traverse_preorder(root);
	
	printf("nodes %d\n", nnodes(root, 0));
	printf("leaves %d\n", nleaves(root, 0));
	printf("height %d\n", height(root));

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
int nleaves(struct tree *node, int n)
{
	if (node->left == NULL && node->right == NULL)
		return 1;
	if (node->left != NULL)
		n += nleaves(node->left, 0);
	if (node->right != NULL)
		n += nleaves(node->right, 0);
	return n;
}

/*
 * count total number of nodes including start node
 */
int nnodes(struct tree *node, int *n)
{
	
	if (node == NULL)
		return 0;
	else
		return 1 + nnodes(node->right, 0) + nnodes(node->left, 0);
}

int height(struct tree *node)
{
	if (node->left == NULL && node->right == NULL) {
		return 0;
	} else {
		int left = 1 + height(node->left);
		int right = 1 + height(node->right);
		if (left > right)
			return left;
		else
			return right;
	}
}

void traverse_preorder(struct tree *node)
{
	if (node == NULL)
		return;
	print_node(node);
	traverse_preorder(node->left);
	traverse_preorder(node->right);
}

void traverse_inorder(struct tree *node)
{
	if (node == NULL)
		return;
	traverse_inorder(node->left);
	print_node(node);
	traverse_inorder(node->right);
}

void traverse_postorder(struct tree *node)
{
	if (node == NULL)
		return;
	traverse_postorder(node->left);
	traverse_postorder(node->right);
	print_node(node);
}
