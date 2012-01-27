#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *stack;
static int plats=-1;
static int antal,size;

void Push(void *x){
   plats++;
   assert(plats<antal-1);
   memcpy(stack+plats*size,x,size);
}

void *Pop(void){
   void *p;
   assert(plats>=0);
   p=stack+plats*size;
   plats--;
   return p;
}

int IsEmpty(void){
  return (plats==0);
}

int IsFull(void){
  return (plats==antal);
}

void InitStack(int s, int m){
  size=s;
  antal=m;
  stack=(char *)calloc(antal,sizeof(size));
}

void FreeStack(void){
  free(stack);
}

