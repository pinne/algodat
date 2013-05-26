/*
 * Algodat
 * 6.11 Musvandring
 *
 * skers@kth.se 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GRAPH[64][2] = {{0}};
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
	if (argc < 2)
		read_file("hus.txt");
	else
		read_file(argv[1]);

	/* print paths */
	for (int i = 1; i <= 20; i++) {
		fill_stack(i);
		if (LEN > 0) {
			printf("%d -> ", i);
			print_stack();
		}
	}

	/* read destination if not in command line arguments */
	int destination;
	if (argc < 3) {
		printf("Destination: ");
		scanf("%d", &destination);
	} else {
		destination = atoi(argv[2]);
	}

	int start = 1; /* mouse always start in this room */
	int samples = 10000;
	int tot_moves = 0;
	/* run several simulations and sum their distance */
	for (int i = 0; i < samples; i++) {
		ROOM = start;
		tot_moves += find_path(destination);
	}
	printf("It takes ~%.2f moves\n", (float)tot_moves/samples);

	return 0;
}

/* run a simulation */
int find_path(int dest)
{
	int moves = 0;
	while (ROOM != dest) {
		next();
		moves++;
	}
	return moves;
}

/* randomly enter a room */
void next(void)
{
	fill_stack(ROOM);
	ROOM = random_dir();
}

/* return a random direction from current room */
int random_dir(void)
{
	if (LEN == 0)
		return 0;
	else
		return STACK[rand() % LEN];
}

void empty_stack(void)
{
	while (LEN > 0)
		pop();
}

/* fill stack of paths from distance table */
void fill_stack(int node)
{
	empty_stack();
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
	while (LEN > 0) {
		printf("%2d", pop());
	}
	printf("\n");
}

/* read filename and fill distance table */
void read_file(char filename[])
{
	FILE *fp;
	fp = fopen(filename, "rt");
	fscanf(fp, "%d\n", &ROWS);

	for (int i = 0; i < ROWS; i++) {
		fscanf(fp, "%d %d\n", &GRAPH[i][0], &GRAPH[i][1]);
	}

	fclose(fp);
}

