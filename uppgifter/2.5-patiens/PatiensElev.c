#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct kort {
	int valor, farg;
};

struct kortelement {
	struct kort kort;
	struct kortelement *nasta;
};

struct kortelement *start[4] = { NULL, NULL, NULL, NULL };
int nstack[4] = { 0, 0, 0, 0 };

int tom(int nr)
{
	return (start[nr] == NULL);
}

void push(struct kort p, int nr)
{
	struct kortelement *ny;
	ny = malloc(sizeof(struct kortelement));
	nstack[nr]++;
	ny->kort = p;
	ny->nasta = start[nr];
	start[nr] = ny;
}

struct kort pop(int nr)
{
	struct kort p;
	struct kortelement *tmp;
	p = start[nr]->kort;
	tmp = start[nr];
	nstack[nr]--;
	start[nr] = start[nr]->nasta;
	free(tmp);
	return p;
}

int length(int nr)
{
	return nstack[nr];
}

struct kort overst(int nr)
{
	int i;
	struct kortelement *target = *start;

	printf("kort: %d\t\n", target->kort.valor);
	for (i = 0; i < nr; i += 1) {
		printf("kort: %d\t\n", target->kort.valor);
		target = target->nasta;
	}

	return target->kort;
}

void blanda(int lek[])
{
	int k, plats, tmp;

	for (k = 1; k <= 52; k++)
		lek[k] = k;
	for (k = 1; k <= 52; k++) {
		plats = k + rand() % (53 - k);
		tmp = lek[k];
		lek[k] = lek[plats];
		lek[plats] = tmp;
	}
}

int samma_farg(int *hog)
{
	int hog1, hog2;
	struct kort k1, k2;
	for (hog1 = 0; hog1 < 3; hog1++) {
		k1 = overst(hog1);
		for (hog2 = hog1 + 1; hog2 < 4; hog2++) {
			k2 = overst(hog2);
			if (k1.farg == k2.farg && k1.farg != -1) {
				if (k1.valor > k2.valor)
					*hog = hog2;
				else
					*hog = hog1;
				return 1;
			}
		}
	}
	return 0;
}

int hogsta_topp(void)
{
	int hog, hogmax = -1, max = -1;
	struct kort p;

	for (hog = 0; hog < 4; hog++) {
		p = overst(hog);
		if (p.valor > max && length(hog) > 1) {
			hogmax = hog;
			max = p.valor;
		}
	}
	return hogmax;
}

void hog_tom(void)
{
	int hog, fhog;
	struct kort p;
	for (hog = 0; hog < 4; hog++) {
		if (tom(hog)) {
			fhog = hogsta_topp();
			if (fhog > -1) {
				p = pop(fhog);
				push(p, hog);
			}
		}
	}
}

int kvar(void)
{
	// Kod in här
}

int lyckat(void)
{
	int hog, k;
	struct kort p;
	for (hog = 0; hog < 4; hog++) {
		p = overst(hog);
		if (p.valor != 12) {
			kvar();
			return 0;
		}
	}
	k = kvar();
	return k == 4;
}

int lagg_patiens(int lek[])
{
	int n = 0, omgang, nr, hog;
	struct kort p;

	for (omgang = 1; omgang <= 13; omgang++) {
		for (nr = 0; nr < 4; nr++) {
			n++;
			p.valor = (lek[n] - 1) % 13;
			p.farg = (lek[n] - 1) / 13;
			push(p, nr);
		}
		while (samma_farg(&hog)) {
			pop(hog);
			hog_tom();
		}
	}
	return lyckat();
}

#define ANTALFORSOK 300000
int main(void)
{
	int lek[53], antal = 0;
	int forsok;

	srand(time(0));
	for (forsok = 1; forsok <= ANTALFORSOK; forsok++) {
		blanda(lek);
		if (lagg_patiens(lek))
			antal++;
	}
	printf("Av %d försök har %d lyckats\n", ANTALFORSOK, antal);
	return 0;
}

