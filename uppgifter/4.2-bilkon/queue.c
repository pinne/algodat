#include "queue.h"

#define NDEBUG

void init_queue(void)
{
	FIRST = malloc(sizeof(struct queue));
	LAST = malloc(sizeof(struct queue));
	FIRST->prev = NULL;
	FIRST->next = LAST;
	LAST->prev = FIRST;
	LAST->next = NULL;
}

void enqueue(struct queue *element)
{
	element->prev = LAST->prev;
	LAST->prev->next = element;
	element->next = LAST;
	LAST->prev = element;
	return;
}

struct queue *dequeue()
{
	if (FIRST->next == LAST) {
		/* the empty queue */
		fprintf(stderr, "ERROR: Queue is empty\n");
		return NULL;
	}

	struct queue *curr;
	curr = FIRST->next;
	FIRST->next = FIRST->next->next;
	FIRST->next->prev = FIRST;

	return curr;
}

struct queue *remove_last()
{
	struct queue *curr = LAST->prev;
	curr->prev->next = LAST;
	LAST->prev = curr->prev;

	return curr;
}

void print_element(struct queue *q)
{
        printf("%s", q->car);
        printf("\n");
}

void print_queue()
{
	struct queue *i = FIRST;
	while (i->next != LAST) {
		i = i->next;
		printf("%10s\n", i->car);
	}
}

int queue_len(void)
{
	if (FIRST->next == LAST)
		return 0;

	struct queue *i = FIRST;
	int len = 1;
	while (i->next != LAST) {
		i = i->next;
		len += 1;
	}

	return len;
}
