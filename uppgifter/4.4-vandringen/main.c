#include "tree.h"
#include "queue.h"

#define DEBUG
#define MAXTREEDEPTH 3

int TARGET_X;
int TARGET_Y;
int STEP_N;
int STEP_S;
int STEP_E;
int STEP_V;
int MINMOVE = INT_MAX;

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
	create_tree(&root, MAXTREEDEPTH);

#ifndef NDEBUG
	printf("Pre-order traversal\n");
	traverse_preorder(&root);
	printf("In-order traversal\n");
	traverse_inorder(&root);
	printf("Post-order traversal\n");
	traverse_postorder(&root);
#endif
	printf("Level-order traversal\n");
	traverse_levelorder(&root);

	clear_children(&root);

	return 0;
}

