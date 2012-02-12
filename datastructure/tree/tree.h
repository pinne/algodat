#ifndef _tree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TWO_DIMENSION

struct tree {
	int level;
	int x;
	int y;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
#ifndef TWO_DIMENSION
	struct tree *up;
	struct tree *down;
#endif
};

void create_tree(struct tree *, int);
void do_level(struct tree *, int);
void print_node(struct tree *);
struct tree *spawn_child(struct tree *, struct tree *);
void traverse_preorder(struct tree *);
void traverse_inorder(struct tree *);
void traverse_postorder(struct tree *);
void traverse_levelorder(struct tree *);
void clear_children(struct tree *);
int nleaves(struct tree *, int);
int nnodes(struct tree *, int *);
int height(struct tree *);

#endif
