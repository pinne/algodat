/*
 * copyright varm kod 2012
 * skers@kth.se
 */
#ifndef _queue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct queue {
	char car[20];
	struct queue *next;
	struct queue *prev;
} *FIRST, *LAST;

int main(int argc, char *argv[]);
void init_queue(void);
struct queue *encapsulate(int);
void enqueue(struct queue *);
struct queue *dequeue();
struct queue *remove_last();
void print_element(struct queue *);
void print_queue();
int queue_len(void);

#endif
