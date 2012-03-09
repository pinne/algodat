#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 5
#define TAKEN 1
#define EMPTY -1

#define N_COLORS 7
char *COLORS[N_COLORS] = {
	"\033[1;31;41m", /* Red */
	"\033[1;32;42m", /* Green */    
	"\033[1;33;43m", /* Yellow */   
	"\033[1;34;44m", /* Blue */     
	"\033[1;35;45m", /* Magenta */  
	"\033[1;36;46m", /* Cyan */     
	"\033[1;37;47m"  /* White */
};
#define ENDCOLOR "\033[0m"
int COLOR_COUNTER = 0;

#define N_PIECES 4
char *PIECES[N_PIECES] = {
	"  ",
	"░░",
	"▒▒",
	"▓▓"
};

int MAP[SIZE + 2][SIZE + 2] = {
	{TAKEN, TAKEN, TAKEN, TAKEN, TAKEN, TAKEN, TAKEN}, 
	{TAKEN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TAKEN},
	{TAKEN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TAKEN},
	{TAKEN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TAKEN},
	{TAKEN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TAKEN},
	{TAKEN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TAKEN},
	{TAKEN, TAKEN, TAKEN, TAKEN, TAKEN, TAKEN, TAKEN}
};

int NSOLUTIONS;
unsigned long long int UNIQUE_SOLUTIONS[100000];
int N_UNIQUE;

void fit(int count);
int impossible(void);
int check(void);
unsigned long long int checksum(void);
int save_checksum(unsigned long long int sum);
void print_map(void);
void print_color_map(void);
int place_j(int i, int j);
int place_l(int i, int j);
int place_7(int i, int j);
int place_f(int i, int j);
void remove_j(int i, int j);
void remove_l(int i, int j);
void remove_7(int i, int j);
void remove_f(int i, int j);

int main(int argc, char *argv[])
{
	NSOLUTIONS = 0;
	N_UNIQUE = 0;

	MAP[1][3] = TAKEN;
	print_color_map();

	fit(0);
	printf("Solutions %d\n", NSOLUTIONS);

	printf("Computed sums: ");
	int i;
	for (i = 0; i < N_UNIQUE; i += 1)
		printf("%Ld ", UNIQUE_SOLUTIONS[i]);

	printf("\n");
	printf("Spatially unique %d\n", N_UNIQUE);
	return 0;
}

void fit(int count)
{
	if (check() == 0) {
		/* solution found */
		NSOLUTIONS += 1;
		if (save_checksum(checksum()) == 0) {
			/* found unique solution */
			print_color_map();
		}
		return;
	} else if (impossible() != 0 && count < 8) {
		/* place new piece */
		int i;
		for (i = 1; i < SIZE; i += 1) {
			int j;
			for (j = 1; j < SIZE; j += 1) {
				if (MAP[i][j] == EMPTY) {
					if (place_f(i, j) == 0) {
						fit(count + 1);
						remove_f(i, j);
					}
					if (place_j(i, j) == 0) {
						fit(count + 1);
						remove_j(i, j);
					}
					if (place_7(i, j) == 0) {
						fit(count + 1);
						remove_7(i, j);
					}
					if (place_l(i, j) == 0) {
						fit(count + 1);
						remove_l(i, j);
					}
				}
			}
		}
	}
}

/*
 * Puzzle finished?
 */
int check(void)
{
	int i;
	for (i = 1; i <= SIZE + 1; i += 1) {
		int j;
		for (j = 1; j <= SIZE + 1; j += 1) {
			if (MAP[i][j] == EMPTY)
				return -1;
		}
	}
	return 0;
}

/*
 * Exit early if hole
 */
int impossible(void)
{
	int i, j;
	for (i = 1; i <= SIZE; i += 1) {
		for (j = 1; j <= SIZE; j += 1) {
			if (MAP[i][j] == EMPTY) {
				/* EMPTY with four neighbors makes a hole */
				int neighbors = 0;
				if (MAP[i-1][j] == TAKEN)
					neighbors += 1;
				if (MAP[i+1][j] == TAKEN)
					neighbors += 1;
				if (MAP[i][j-1] == TAKEN)
					neighbors += 1;
				if (MAP[i][j+1] == TAKEN)
					neighbors += 1;
				if (neighbors == 4) {
					return 0;
				}
			}
		}
	}
	return -1;
}

/*
 * primitive checksum computation
 */
unsigned long long int checksum(void)
{
	int i, j;
	unsigned long long int sum = 0;
	for (i = 1; i <= SIZE; i += 1) {
		for (j = 1; j <= SIZE; j += 1) {
			if (MAP[i][j] == 0) {
				/* avoid 0 multiplication */
				sum += pow(i, j) * 13;
			} else {
				sum += pow(i, j) * MAP[i][j];
			}
		}
	}
	return sum;
}

int save_checksum(unsigned long long int sum)
{
	int i;
	for (i = 0; i < N_UNIQUE; i += 1)
		if (UNIQUE_SOLUTIONS[i] == sum)
			return -1;

	UNIQUE_SOLUTIONS[N_UNIQUE] = sum;
	N_UNIQUE += 1;
	return 0;
}

void print_color_map(void)
{
	int i, j;
	for (i = 1; i <= SIZE; i += 1) {
		for (j = 1; j <= SIZE; j += 1) {
			printf(COLORS[MAP[i][j] % N_COLORS]);
			if (MAP[i][j] == -1)
				printf(PIECES[0]);
			else
				printf(PIECES[MAP[i][j] % N_PIECES]);
			printf(ENDCOLOR);
		}
		printf("\n");
	}
	printf("\n");
}          

void print_map(void)
{
	int i, j;
	for (i = 1; i <= SIZE; i += 1) {
		for (j = 1; j <= SIZE; j += 1) {
			printf("%2d", MAP[i][j]);
		}
		printf("\n");
	}
}

int place_j(int i, int j)
{
	COLOR_COUNTER = 0;
	if (MAP[i + 1][j] == EMPTY && MAP[i][j + 1] == EMPTY
			&& MAP[i + 1][j + 1] == EMPTY) {
		MAP[i + 1][j] = COLOR_COUNTER;
		MAP[i][j + 1] = COLOR_COUNTER;
		MAP[i + 1][j + 1] = COLOR_COUNTER;
		COLOR_COUNTER += 1;
		return 0;
	} else {
		return -1;
	}
}

int place_l(int i, int j)
{
	COLOR_COUNTER = 4;
	if (MAP[i][j] == EMPTY && MAP[i + 1][j] == EMPTY
			&& MAP[i + 1][j + 1] == EMPTY) {
		MAP[i][j] = COLOR_COUNTER;
		MAP[i + 1][j] = COLOR_COUNTER;
		MAP[i + 1][j + 1] = COLOR_COUNTER;
		COLOR_COUNTER += 1;
		return 0;
	} else {
		return -1;
	}
}

int place_7(int i, int j)
{
	COLOR_COUNTER = 2;
	if (MAP[i][j] == EMPTY && MAP[i][j + 1] == EMPTY
			&& MAP[i + 1][j + 1] == EMPTY) {
		MAP[i][j] = COLOR_COUNTER;
		MAP[i][j + 1] = COLOR_COUNTER;
		MAP[i + 1][j + 1] = COLOR_COUNTER;
		COLOR_COUNTER += 1;
		return 0;
	} else {
		return -1;
	}
}

int place_f(int i, int j)
{
	COLOR_COUNTER = 3;
	if (MAP[i][j] == EMPTY && MAP[i + 1][j] == EMPTY
			&& MAP[i][j + 1] == EMPTY) {
		MAP[i][j] = COLOR_COUNTER;
		MAP[i + 1][j] = COLOR_COUNTER;
		MAP[i][j + 1] = COLOR_COUNTER;
		COLOR_COUNTER += 1;
		return 0;
	} else {
		return -1;
	}
}

void remove_j(int i, int j)
{
	MAP[i + 1][j] = EMPTY;
	MAP[i][j + 1] = EMPTY;
	MAP[i + 1][j + 1] = EMPTY;
}

void remove_l(int i, int j)
{
	MAP[i][j] = EMPTY;
	MAP[i + 1][j] = EMPTY;
	MAP[i + 1][j + 1] = EMPTY;
}

void remove_7(int i, int j)
{
	MAP[i][j] = EMPTY;
	MAP[i][j + 1] = EMPTY;
	MAP[i + 1][j + 1] = EMPTY;
}

void remove_f(int i, int j)
{
	MAP[i][j] = EMPTY;
	MAP[i + 1][j] = EMPTY;
	MAP[i][j + 1] = EMPTY;
}

