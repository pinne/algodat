# Author: skers@kth.se Varm kod
CC = gcc
OBJS = taltriangeln.o queue.o
COMPILER_FLAGS = -Wall -g
#COMPILER_FLAGS = -Wall -O2
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = taltriangeln.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
