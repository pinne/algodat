#ifndef _queue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct queue {
	struct tree *node;
	struct queue *next;
	struct queue *prev;
	int visited;
} *first, *last;

struct queue *init_queue(void);
struct queue *encapsulate(struct tree *);
void enqueue(struct queue *);
struct queue *dequeue(struct queue *);
int queue_len(void);

#endif
