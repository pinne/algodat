#include "queue.h"

int main(int argc, char *argv[])
{
	init_queue(&first, &last);
	struct queue *new_queue = malloc(sizeof(struct queue));
	new_queue->val = 42;
	enqueue(new_queue);
	struct queue *tmp = dequeue();
	print_element(tmp);

	return 0;
}

void init_queue(struct queue **first, struct queue **last)
{
	first = malloc(sizeof(struct queue));
	last  = malloc(sizeof(struct queue));
	assert(first != NULL);
	assert(last != NULL);
}

struct queue *encapsulate(int val)
{
	struct queue *new_queue;
	new_queue = malloc(sizeof(struct queue));
	assert(new_queue != NULL);
	new_queue->val = val;

	return new_queue;
}

void enqueue(struct queue *element)
{
	if (&first == NULL) {
		/* empty queue */
		init_queue(&first, &last);
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

	if ((first)->next == NULL)
		first = NULL;
	else {
		first = first->next;
		assert(first != NULL);
	}

	return curr_first;
}

void print_element(struct queue *element)
{
	printf("%3d\n", element->val);
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

