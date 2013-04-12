/*
 * Algodat
 * 6.11 Musvandring
 *
 * skers@kth.se 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GRAPH[64][2];
int ROWS;

int STACK[64];
int LEN = 0;
int ROOM = 1;

int random_dir(void);
int get_dirs(int);
void print_dirs(int);
void fill_stack(int);
void print_stack(void);
void push(int);
int pop(void);
void next(void);
void read_file(char*);
int find_path(int);

int main(int argc, char *argv[])
{
	srand(time(0));
	if (argc < 1)
		read_file("hus.txt");
	else
		read_file(argv[1]);

	for (int i = 1; i <= ROWS+1; i++) {
		fill_stack(i);
		printf("%d: ", i);
		//printf("ran_dir: %d\t", random_dir());
		print_stack();
	}

	int destination;
	printf("Destination: ");
	scanf("%d", &destination);

	ROOM = 1;
	int start = 1;
	int samples = 10000;
	int tot_moves = 0;
	for (int i = 0; i < samples; i++) {
		ROOM = start;
		tot_moves += find_path(destination);
	}
	printf("It takes ~%.2f moves\n", (float)tot_moves/samples);
}

int find_path(int dest)
{
	int moves = 0;
	while (ROOM != dest) {
		next();
		moves++;
	}
	return moves;
}

void next(void)
{
	fill_stack(ROOM);
	ROOM = random_dir();
}

int random_dir(void)
{
	return STACK[rand() % LEN];
}

void empty_stack(void)
{
	while (LEN > 0)
		pop();
}

void fill_stack(int node)
{
	LEN = 0;
	for (int i = 0; i < ROWS; i++) {
		if (GRAPH[i][0] == node)
			push(GRAPH[i][1]);
		if (GRAPH[i][1] == node)
			push(GRAPH[i][0]);
	}
}

void push(int dir)
{
	STACK[LEN++] = dir;
}

int pop(void)
{
	return STACK[--LEN];
}

void print_stack(void)
{
	printf("-> ");
	while (LEN > 0)
		printf("%2d", pop());
	printf("\n");
}

void read_file(char filename[])
{
	FILE *fp;
	fp = fopen(filename, "rt");
	fscanf(fp, "%d\n", &ROWS);
	//printf("%d\n", ROWS);

	for (int i = 0; i < ROWS; i++) {
		fscanf(fp, "%d %d\n", &GRAPH[i][0], &GRAPH[i][1]);
	}

	fclose(fp);
}

