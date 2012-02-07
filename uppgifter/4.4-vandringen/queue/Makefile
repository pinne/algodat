# Author: skers@kth.se Varm kod
CC = gcc
OBJS = queue.o
COMPILER_FLAGS = -Wall -g
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = queuetest.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
