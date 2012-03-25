#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATION 1
#define EMPTY 0
#define MAXDEPTS 15
#define MAXMOVES 500

int **distance;
int *fire_dept;
int global_min = MAXDEPTS;
int max_dist;
int ntowns;

int is_safe(int town, int max_dist, int ntowns);
int test(int max_dist, int ntowns);
void clean_up(int);
void read_from_file(int);
void print_distance(int ntowns);

void permute(int *array, int i, int len, int ndepts);
void swap(int *a, int *b);
void printArray(int *array, int len);

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen("brand.dat", "rt");

	fscanf(fp, "%d", &max_dist);
	fscanf(fp, "%d", &ntowns);
	rewind(fp);
	fclose(fp);

	distance = malloc(ntowns * sizeof(int *));
	fire_dept = malloc(ntowns * sizeof(int));
	int i;
	for (i = 0; i < ntowns; i += 1)
		fire_dept[i] = EMPTY;

	for (i = 0; i < ntowns; i += 1)
		distance[i] = malloc(ntowns * sizeof(int));

	read_from_file(ntowns);
	print_distance(ntowns);

	for (i = 0; i < ntowns; i += 1) {
		fire_dept[i] = STATION;
		permute(fire_dept, 0, ntowns, i + 1);
	}

	clean_up(ntowns);
	return 0;
}

void permute(int *array, int i, int len, int ndepts)
{
	if (len == i) {
		if (test(max_dist, ntowns) == 0) {
			if (ndepts <= global_min) {
				global_min = ndepts;
				printf("Det behövs %d brandstationer\n",
						global_min);
				exit(0);
			}
		}
	} else {
		int j;
		for (j = i; j < len; j++) {
			swap(array + i, array + j);
			permute(array, i + 1, len, ndepts);
			swap(array + i, array + j);
		}
	}
}
void printArray(int *array, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (array[i] == 1)
			printf("%3c", 'o');
		else
			printf("%3c", ' ');
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int test(int max_dist, int ntowns)
{
	int nsafe = 0;
	int i;
	for (i = 0; i < ntowns; i += 1) {
		if (is_safe(i, max_dist, ntowns) == 0)
			nsafe += 1;
	}

	if (nsafe < ntowns)
		return -1;
	else
		return 0;
}

int is_safe(int town, int max_dist, int ntowns)
{
	int i;
	for (i = 0; i < ntowns; i += 1) {
		if (distance[town][i] <= max_dist && fire_dept[i] == STATION)
			return 0;
	}
	return -1;
}

void read_from_file(int ntowns)
{
	FILE *fp;
	fp = fopen("brand.dat", "rt");
	int tmp;
	fscanf(fp, "%d", &tmp);
	fscanf(fp, "%d", &tmp);
	int i;
	for (i = 0; i < ntowns; i += 1) {
		int j;
		for (j = 0; j < ntowns; j += 1) {
			fscanf(fp, "%d", &distance[i][j]);
		}
	}
	fclose(fp);
}

void print_distance(int ntowns)
{
	int i;
	for (i = 0; i < ntowns; i += 1) {
		int j;
		for (j = 0; j < ntowns; j += 1) {
			printf("%3d", distance[i][j]);
		}
		printf("\n");
	}
}

void clean_up(int ntowns)
{
	int i;
	for (i = 0; i < ntowns; i += 1)
		free(distance[i]);
	free(distance);
}
