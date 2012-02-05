#include "queue.h"

struct queue {
	struct tree *node;
	struct queue *next;
} *head, *tail;

