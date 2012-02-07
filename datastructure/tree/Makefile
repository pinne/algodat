# Author: skers@kth.se Varm kod
CC = gcc
OBJS = tree.o
COMPILER_FLAGS = -Wall -g
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = treetest.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
