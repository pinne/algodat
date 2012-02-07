/*
 * copyright varm kod 2012
 * skers@kth.se
 */
#ifndef _queue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct queue {
	struct queue *next;
	struct queue *prev;
	int val;
} *FIRST, *LAST;

void init_queue(void);
struct queue *encapsulate(int);
void enqueue(struct queue *);
struct queue *dequeue();
void print_element(struct queue *);
void print_queue();
int queue_len(void);

#endif
