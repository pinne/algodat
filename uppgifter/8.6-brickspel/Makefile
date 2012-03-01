# Author: skers@kth.se Varm kod
CC = gcc
OBJS = main.o
COMPILER_FLAGS = -Wall -O2
UNAME := $(shell uname -s)
INCLUDE = 
LIBS = 

EXEC = brickspel.out

$(EXEC): $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o $(EXEC) $(OBJS) $(LIBS)

%.o:	%.c
	$(CC) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f $(EXEC) $(OBJS)
