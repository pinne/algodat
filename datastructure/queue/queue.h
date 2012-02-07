#ifndef _queue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct queue {
	int val;
	struct queue *next;
	struct queue *prev;
	int visited;
} *first, *last;

void init_queue(struct queue **, struct queue **);
struct queue *encapsulate(int);
void enqueue(struct queue *);
struct queue *dequeue();
void print_element(struct queue *);
int queue_len(void);

#endif
