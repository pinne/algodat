#include "queue.h"

#define NDEBUG

//int main(int argc, char *argv[])
//{
//      init_queue();
//
//      /* queue all the things */
//      struct queue *new_queue;
//      int i;
//      for (i = 0; i < 10; i += 1) {
//              new_queue = malloc(sizeof(struct queue));
//              new_queue->val = i;
//              enqueue(new_queue);
//      }
//
//#ifndef NDEBUG
//      /* queue is in place */
//      printf("in queue: ");
//      print_queue();
//#endif
//
//      /* dequeue and print */
//      struct queue *from_queue;
//      while (queue_len() > 0) {
//              from_queue = dequeue();
//              print_element(from_queue);
//              free(from_queue);
//      }
//
//      return 0;
//}

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

void print_element(struct queue *q)
{
	printf("level %4d", q->level);
	printf("%4d:", q->x);
	printf("%d", q->y);
	//printf("%4d", q->visited);
	printf("\n");
}

void print_queue()
{
	struct queue *i = FIRST;
	while (i->next != LAST) {
		i = i->next;
		printf("%10d\n", i->level);
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
