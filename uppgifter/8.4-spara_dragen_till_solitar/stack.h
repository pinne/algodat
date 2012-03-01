#include <stdio.h>

struct stack_elem {
	int x;
	int y;
	struct stack_elem *next;
};

struct stack {
	struct stack_elem *top;
};

void stack_init(struct stack *ptr);
struct stack_elem stack_destroy(void);
void stack_push(struct stack *top, struct *stack_elem);
struct stack_elem stack_pop(void);
int stack_depth(void);
