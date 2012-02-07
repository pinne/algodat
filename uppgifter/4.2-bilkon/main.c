#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDEBUG
#define FILENAME "Trafik.dat"

void clear_queue(void);

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(FILENAME, "rt");
	int nrows;
	fscanf(fp, "%d", &nrows);
#ifndef NDEBUG
	printf("%d rows\n", nrows);
#endif

	init_queue();
	assert(FIRST->next == LAST); /* empty queue test */

	int i;
	struct queue *tmp;
	for (i = 0; i < nrows; i += 1) {
		int ndrive;
		tmp = malloc(sizeof(struct queue));
		char command[100];
		fscanf(fp, "%s", command);
		if (strncmp(command, "ANLÄNDER", 2) == 0) {
			fscanf(fp, "%s", tmp->car);
			enqueue(tmp);
		} else if (strncmp(command, "KÖR", 1) == 0) {
			fscanf(fp, "%d", &ndrive);
			while (ndrive-- > 0) {
				tmp = dequeue();
				free(tmp);
			}
		} else if (strncmp(command, "BACKAR", 2) == 0) {
			fscanf(fp, "%d", &ndrive);
			while (ndrive-- > 0) {
				tmp = remove_last();
				free(tmp);
			}
		}
	}

	fclose(fp);

	while (queue_len() > 0) {
		tmp = dequeue();
		printf("%s\n", tmp->car);
		free(tmp);
	}

	return 0;
}

void clear_queue(void)
{
	while (queue_len() > 0) {
		struct queue *node = dequeue();
		free(node);
	}
}
