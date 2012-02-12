#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define NDEBUG
#define STORLEK 100
int tab[STORLEK][STORLEK];
int sum[STORLEK][STORLEK];
int max = 0;

//void berakna(int rad, int kol, int s);
void berakna();
void print_tab(void);
void print_sum(void);
void clear_array(void);
void fill_array(void);
void find_max_bottom(void);

int main(void)
{
	fill_array();	/* read from file */
	clear_array();	/* sum { 0 } */
	//print_tab();

	//berakna(0, 0, 0);
	berakna();
	printf("Maximal summa: %d\n", max);

	return 0;
}

/*
 *  while not q.empty do
 *  node := q.dequeue()
 *  visit(node)
 *  if node.left ≠ null
 *      q.enqueue(node.left)
 *  if node.right ≠ null
 *      q.enqueue(node.right)
 */
void berakna()
{
	init_queue();

	struct queue *root = malloc(sizeof(struct queue));
	root->level = 0;
	root->x = 0;
	root->y = 0;
	root->val = tab[0][0];
	sum[0][0] = root->val;
	enqueue(root);

#ifndef NDEBUG
	print_tab();
#endif
	struct queue *node;

	while (1) {
		node = dequeue();
#ifndef NDEBUG
		print_element(node);
#endif
		if (node->level == STORLEK-1) {
			free(node);
			break;
		} else if (node->val >= sum[node->x][node->y]) {
			/* move straight down */
			struct queue *down = malloc(sizeof(struct queue));
			down->level = node->level + 1;
			down->x = node->x + 1;
			down->y = node->y;
			down->val = sum[node->x][node->y]
				+ tab[down->x][down->y];
			if (down->val >= sum[down->x][down->y]) {
				sum[down->x][down->y] = down->val;
				enqueue(down);
			} else {
				free(down);
			}

			/* move diagonally down */
			struct queue *diag = malloc(sizeof(struct queue));
			diag->level = node->level + 1;
			diag->x = node->x + 1;
			diag->y = node->y + 1;
			diag->val = sum[node->x][node->y]
				+ tab[diag->x][diag->y];
			if (diag->val >= sum[diag->x][diag->y]) {
				sum[diag->x][diag->y] = diag->val;
				enqueue(diag);
			} else {
				free(diag);
			}
		}
	}
	free(root);
	find_max_bottom();
#ifndef NDEBUG
	print_sum();
#endif
	//	print_tab();
}

//void berakna(int rad, int kol, int s)
//{
//	if (rad == STORLEK - 1) {
//		s = s + tab[rad][kol];
//		if (s > max)
//			max = s;
//	} else {
//		berakna(rad + 1, kol, s + tab[rad][kol]);
//		berakna(rad + 1, kol + 1, s + tab[rad][kol]);
//	}
//}

void print_tab(void)
{
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			printf("%3d ", tab[i][j]);
		}
		printf("\n");
	}
}

void print_sum(void)
{
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			printf("%7d ", sum[i][j]);
		}
		printf("\n");
	}
}

void clear_array(void)
{
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			sum[i][j] = 0;
		}
	}
}

void find_max_bottom()
{
	int j;
	for (j = 0; j < STORLEK; j++) {
		if (sum[STORLEK-1][j] > max) {
			max = sum[STORLEK-1][j];
		}
	}
}

void fill_array(void)
{
	FILE *fp;
	fp = fopen("triangeldata.dat", "rt");
	//fp = fopen("input.dat", "rt");
	int i, j;
	for (i = 0; i < STORLEK; i++) {
		for (j = 0; j <= i; j++) {
			fscanf(fp, "%d", &tab[i][j]);
		}
	}
	fclose(fp);
}

