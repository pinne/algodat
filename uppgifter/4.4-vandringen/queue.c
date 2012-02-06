#include "queue.h"

struct queue *init_queue(void)
{
	struct queue *new_queue;
	new_queue = malloc(sizeof(struct queue));
	assert(new_queue != NULL);
	
	return new_queue;
}

struct queue *encapsulate(struct tree *node)
{
	struct queue *new_queue;
	new_queue = malloc(sizeof(struct queue));
	assert(new_queue != NULL);
	new_queue->visited = 42;

	new_queue->node = node;
	return new_queue;
}

void enqueue(struct queue *element)
{
	if (first == NULL) {
		/* empty queue */
		element = init_queue();
		assert(element != NULL);
		first = element;
		last = first;
		first->prev = NULL;
		first->next = NULL;
		assert(first->prev == NULL);
		return;
	}

	last->next = element;
	element->prev = last;
	last = element;

	return;
}

struct queue *dequeue(struct queue *first)
{
	struct queue *curr_first;
	curr_first = first;
	printf("Visited %3d\n", (first)->visited);

	if ((first)->next == NULL)
		first = NULL;
	else {
		first = (first)->next;
		assert(first != NULL);
	}

	return curr_first;
}

int queue_len(void)
{
	if (first == NULL)
		return 0;
	if (last == first)
		return 1;

	struct queue *i = first;
	int len = 2;
	while (i->next != last) {
		i = i->next;
		len += 1;
	}

	return len;
}

