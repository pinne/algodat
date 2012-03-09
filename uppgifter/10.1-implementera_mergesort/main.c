#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "numbers.txt"

void msort(int numbers[], int len);
void mergesort(int array[], int new[], int n);
void merge(int left[], int len_left, int right[], int len_right, int *t);
void print_array(int array[], int len);
void copy_array(int target[], int source[], int to, int from);
int w_count(FILE *fp);
void stupid_sort(int array[], int len);

int main(int argc, char *argv[])
{
	FILE *fp;
	if (argc < 2)
		fp = fopen(FILENAME, "rt");
	else
		fp = fopen(argv[1], "rt");

	int n_num = w_count(fp);
	rewind(fp);

	int *numbers = malloc(sizeof(int) * n_num);

	/* read from file */
	int i;
	for (i = 0; i < n_num; i += 1)
		fscanf(fp, "%d", &numbers[i]);
	fclose(fp);

	/* before */
	print_array(numbers, n_num);
	printf("\n");

	msort(numbers, n_num);
	print_array(numbers, n_num);

	free(numbers);
	return 0;
}
/* wrapper for mergesort */
void msort(int array[], int len)
{
	int *tmp;
	tmp = malloc(sizeof(int) * len);
	copy_array(tmp, array, len, 0);

	mergesort(array, tmp, len);
	free(tmp);
}

void mergesort(int array[], int new[], int len)
{
	if (len <= 1) {
		return;
	}

	int pivot = len / 2;

	mergesort(new, array, pivot);
	mergesort(new + pivot, array + pivot, len - pivot);

	merge(new, pivot, new + pivot, len - pivot, array);
}

void merge(int *left, int len_left, int *right, int len_right, int *target)
{
	int i = 0;
	int j = 0;
	int k = 0;

	/* merge lists */
	while (i < len_left && j < len_right ) {
		if (left[i] <= right[j])
			target[k++] = left[i++];
		else
			target[k++] = right[j++];
	}
	/* append list */
	while (i < len_left)
		target[k++] = left[i++];
	while (j < len_right)
		target[k++] = right[j++];
}

/* print series */
void print_array(int array[], int len)
{
	int i;
	for (i = 0; i < len; i += 1)
		printf("%d ", array[i]);
	printf("\n");
}

int w_count(FILE *fp)
{
	int n = 0;

	int ch;
	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
		n++;

	return n;
}

void copy_array(int target[], int source[], int to, int from)
{
	int i = 0;
	while (from < to)
		target[i++] = source[from++];
}

