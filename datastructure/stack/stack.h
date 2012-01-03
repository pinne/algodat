#ifndef STACK_H
#define STACK_H

extern static char stack[64];
extern static int plats = -1;

int  main(void);
void push(char c);
char pop(void);
int  isempty(void);
int  isfull(void);

#endif /* STACK_H */

