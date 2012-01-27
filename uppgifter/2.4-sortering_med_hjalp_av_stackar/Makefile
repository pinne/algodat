# Author: skers@kth.se Varm kod
CC = gcc
OBJS = BC52_StckSort.o stack.o 
COMPILER_FLAGS = -Wall
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = stack.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
