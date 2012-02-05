# Author: skers@kth.se Varm kod
CC = gcc
OBJS = main.o tree.o queue.o
COMPILER_FLAGS = -Wall
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = vandringen.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
