#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	char namn[11];
	struct person *next;
} person;

char FILNAMN[24];

void las_in(person **start) {
	FILE   *fil;
	person *p;
	person *gp;
	char   n[11];

	*start = NULL;
	gp = NULL;
	//fil = fopen("NAMN1.DAT", "rt");
	fil = fopen(FILNAMN, "rt");
	while (!feof(fil)) {
		fscanf(fil, "%s", n);
		if (!feof(fil)) {
			p = (person*)malloc(sizeof(person));
			strcpy(p->namn, n);
			p->next = NULL;
			if (*start == NULL)
				*start = p;
			else
				gp->next = p;
			gp = p;
		}
	}
	fclose(fil);
}

/*
 * returns the element before the target for ->next trickery.
 */
person *find(person **start, char *namn)
{
	person *p;
	p = *start;
	
	while (strcmp(p->next->namn, namn)) {
		p = p->next;
	}
	return p;
}

void overst(person **start, char *namn)
{
	person *before = find(start, namn);
	person *target;
	target = before->next;

	before->next = target->next;
	target->next = *start;
	*start = target;
}

void skriv_ut(person *start) {
	person *p;

	p = start;
	while (p != NULL) {
		printf("%s ", p->namn);
		p = p->next;
	}
	printf("\n");
}

void avsluta(person **start) {
	person *p;
	while (*start != NULL) {
		p = *start;
		*start = (*start)->next;
		free(p);
	}
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("USAGE: %s <filename> <name> [<name>]\n", argv[0]);
		return 1;
	}
	person *start;
	strcpy(FILNAMN, argv[1]);

	las_in(&start);
	skriv_ut(start);

	int n;
	for (n = 2; n < argc; n++) {
		overst(&start, argv[n]);
	}

	skriv_ut(start);
	avsluta(&start);

	return 0;
}

