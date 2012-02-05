#include "tree.h"

void create_tree(struct tree *node, int depth)
{
#ifdef NDEBUG
#endif
	if (node->level < depth) {
		node->left = spawn_child(node, node->left);
		create_tree(node->left, depth);
		node->right = spawn_child(node, node->right);
		create_tree(node->right, depth);
	}
}
void traverse_levelorder(struct tree *node)
{
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
	printf("Node%12p   ", node);
	printf("Level%3d   x %2d y %2d  parent %12p\n",
	       node->level, node->x, node->y, node->parent);
}

void traverse_preorder(struct tree *node)
{
	if (node != NULL) {
		print_node(node);
		traverse_preorder(node->left);
		traverse_preorder(node->right);
	}
}

void traverse_inorder(struct tree *node)
{
	if (node != NULL) {
		traverse_inorder(node->left);
		print_node(node);
		traverse_inorder(node->right);
	}
}

void traverse_postorder(struct tree *node)
{
	if (node != NULL) {
		traverse_postorder(node->left);
		traverse_postorder(node->right);
		print_node(node);
	}
}

