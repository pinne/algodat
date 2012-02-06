#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDEBUG
#define MAXTREEDEPTH 2

int TARGET_X;
int TARGET_Y;
int STEP_N;
int STEP_S;
int STEP_E;
int STEP_V;
int MINMOVE = INT_MAX;

void traverse_levelorder(struct tree *root)
{
	first = NULL;
	last = NULL;

	printf("Encapsulating:\t");
	struct queue *root_queue = encapsulate(root);
	print_node(root);

	assert(root_queue != NULL);
	printf("Enqueueing:\t");
	enqueue(root_queue);
	print_node(root_queue->node);

	printf("Dequeueing\t");
	struct queue *new;
	new = dequeue(first);
	assert(new != NULL);
	assert(new->node != NULL);
	print_node(new->node);

//	printf("\nat one\t:: Queue length %d\n", queue_len());
//	enqueue(encapsulate(root->left));
//	printf("\nat two\t:: Queue length %d\n", queue_len());
//	enqueue(encapsulate(root->right));
//	printf("\nat thre :: Queue length %d\n", queue_len());
//	enqueue(encapsulate(root->left->right));
//	printf("\nat four :: Queue length %d\n", queue_len());

//	while (queue_len() > 0) {
//		new = dequeue();
//		print_node(new->node);
//		free(new);
//	}
}

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
#ifndef TWO_DIMENSION
	struct tree root = { 0, start_x, start_y,
		NULL, NULL, NULL, NULL, NULL };
#else
	struct tree root = { 0, start_x, start_y,
		NULL, NULL, NULL, NULL, NULL };
#endif
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

