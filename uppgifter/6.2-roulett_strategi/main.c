#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct status {
	int ngames;
	int balance;
};

struct status_mean {
	int start;
	int balance;
};

#define MAXGAMES 10000
int spin();
int play(int, int);
void play_round(struct status**);

int main(int argc, char *argv[])
{
	srand(time(NULL));

	printf("start överlever går vinst genomsnittlig vinst timpenning\n");
	int start;
	for (start = 50; start <= 50; start += 1) {
		struct status *round = malloc(sizeof(struct status));
		round->ngames = 0;
		round->balance = start;
		play_round(&round);
		printf("%d", start);
		printf("%f", (double)round->ngames/MAXGAMES);
		free(round);
	}
	return 0;
}

void play_thousand_rounds(void)
{
}

void play_round(struct status **round)
{
	int bet = 1;
	while ((*round)->balance > 0 && (*round)->ngames++ < MAXGAMES) {
		int played = play(spin(), bet);
		(*round)->balance += played * 2;
		if (played > 0)
			bet = 1;
		else
			bet = -played;
	}
}

int spin(void)
{
	return rand() % 37;
}

int play(int number, int bet)
{
	if (number <= 18)
		return -bet;
	else
		return +bet;
}
