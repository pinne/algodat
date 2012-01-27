#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	char          namn[11];
	struct person *next;
} person;

void las_in(person **start) {
	FILE   *fil;
	person *p;
	person *gp;
	char   n[11];

	*start = NULL;
	gp = NULL;
	fil = fopen("NAMN2.DAT", "rt");
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

/* Här ska den önskade funktionen in
   void overst( ...
   }
   */

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

int main(void) {
	person *start;

	las_in(&start);
	//overst(...
	//overst(...
	skriv_ut(start);
	avsluta(&start);
}

