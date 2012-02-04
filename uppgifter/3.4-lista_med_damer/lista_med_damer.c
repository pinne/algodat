#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct dam {
	char namn[15];
	struct dam *next;
} dam;

void init(dam ** liststart)
{
	FILE *fil;
	char innamn[15];
	dam *ny, *sist;
	fil = fopen("DAMNAMN.DAT", "rt");
	*liststart = NULL;
	if (fil != NULL) {
		while (!feof(fil)) {
			fscanf(fil, "%s", innamn);
			if (!feof(fil)) {
				ny = (dam *) malloc(sizeof(dam));
				strcpy(ny->namn, innamn);
				ny->next = NULL;
				if (*liststart == NULL) {
					*liststart = ny;
					sist = ny;
				} else {
					sist->next = ny;
					sist = ny;
				}
			}
		}
		fclose(fil);
	}
}

void skrivlista(dam * p)
{
	int n = 0;
	printf("\n------------------------------\n");
	while (p != NULL) {
		n++;
		printf("%s ", p->namn);
		if (n % 7 == 0)
			printf("\n");
		p = p->next;
	}
}

int tabortnamn(dam ** p, char n[])
{
	dam *curr = *p;

	if (strcmp(curr->namn, n) == 0) {
		dam *del = curr;
		*p = curr->next;
		free(del);
		return 1;
	} else {
		while (curr->next != NULL) {
			if (strcmp(curr->next->namn, n) == 0) {
				dam *del = curr->next;
				curr->next = curr->next->next;
				free(del);
				return 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}

int tabortplats(dam ** p, int n)
{
	dam *curr = *p;

	if (n == 1 && curr != NULL) {
		dam *del = *p;
		*p = curr->next;
		free(del);
		return 1;
	} else if (n > 1 && curr->next != NULL) {
		int i;
		for (i = 2; i < n; i += 1) {
			curr = curr->next;
			if (curr->next == NULL) {
				return 0;
			}
		}
		dam *del = curr->next;
		curr->next = curr->next->next;
		free(del);
		return 1;
	}
	return 0;
}

int antal(dam * p)
{
	int n;
	if (p == NULL) {
		n = 0;
	} else {
		for (n = 1; p->next != NULL; n += 1) {
			p = p->next;
		}
	}
	return n;
}

void placeraforst(dam ** p, char n[])
{
	dam *new = malloc(sizeof(dam));

	strcpy(new->namn, n);
	new->next = *p;
	*p = new;
}

void placerasist(dam ** p, char n[])
{
	dam *i = *p;
	while (i->next != NULL) {
		i = i->next;
	}

	dam *new = malloc(sizeof(dam));
	strcpy(new->namn, n);
	i->next = new;
	new->next = NULL;
}

int placeraefter(dam * p, char nytt[], char gam[])
{
	dam *i = p;
	dam *after = i->next;
	while (i != NULL) {
		if (strcmp(i->namn, gam) == 0) {
			dam *new = malloc(sizeof(dam));
			strcpy(new->namn, nytt);
			i->next = new;
			new->next = after;
			return 1;
		}
		if (i->next == NULL)
			break;
		i = i->next;
		after = i->next;
	}
	return 0;
}

int placerafore(dam ** p, char nytt[], char gam[])
{
	if (strcmp((*p)->namn, gam) == 0) {
		placeraforst(p, nytt);
		return 1;
	} else {
		dam *before = *p;
		dam *i = before->next;

		while (i != NULL) {
			if (strcmp(i->namn, gam) == 0) {
				dam *new = malloc(sizeof(dam));
				strcpy(new->namn, nytt);
				before->next = new;
				new->next = i;
				return 1;
			}
			before = i;
			i = i->next;
		}
		return 0;
	}
}

int finns(dam * aktuell, char n[])
{
	while (aktuell != NULL) {
		if (strcmp(aktuell->namn, n) == 0)
			return 1;
		aktuell = aktuell->next;
	}
	return 0;
}

dam *fore(dam * p, char n[])
{
	dam *before = p;

	if (strcmp(before->next->namn, n) == 0)
		return before;

	while (before->next != NULL) {
		if (strcmp(before->next->namn, n) == 0) {
			return before;
		}
		before = before->next;
	}
	return NULL;
}

dam *efter(dam * p, char n[])
{
	while (p != NULL) {
		if (strcmp(p->namn, n) == 0)
			return p->next;
		p = p->next;
	}
	return NULL;
}

void clear_mem(dam ** p)
{
	dam *del;
	while (*p != NULL) {
		del = *p;
		*p = (*p)->next;
		free(del);
	}
}

int main(void)
{
	int test = 1;
	dam *liststart, *p;
	int r;
	init(&liststart);
	skrivlista(liststart);
	if (test == 1) {
//              skrivlista(liststart);
//              r = tabortnamn(&liststart, "Anna");
//              r = tabortnamn(&liststart, "Anna");
//              r = tabortnamn(&liststart, "Zigne");
//              r = tabortnamn(&liststart, "Zigne");
//              skrivlista(liststart);

//              printf("efter::: %s\n", efter(liststart, "Anna"));
//              printf("efter::: %s\n", efter(liststart, "Zigne"));

//              printf("fore ::: %s\n", fore(liststart, "Zigne"));

//              placeraefter(liststart, "Simon", "Anna");

//              int tmp = 0;
//              r = tabortplats(&liststart, tmp);
//              printf("\n\n");
//              if (r == 1)
//                      printf("Lyckades ta bort plats %d\n", tmp);
//              else
//                      printf("Lyckades inte ta bort plats%d\n", tmp);
//              skrivlista(liststart);
//              exit(0);
	}
	r = tabortnamn(&liststart, "Daniella");
	skrivlista(liststart);
	r = tabortplats(&liststart, 8);
	skrivlista(liststart);
	printf("\nAntal namn i listan är %d\n", antal(liststart));
	placeraforst(&liststart, "Ann");
	skrivlista(liststart);
	placerasist(&liststart, "Åsa");
	skrivlista(liststart);
	r = placeraefter(liststart, "Karin", "Gun");
	skrivlista(liststart);
	r = placerafore(&liststart, "Nelly", "Marie");
	skrivlista(liststart);
	r = finns(liststart, "Ulla");
	if (r == 1)
		printf("\nPersonen finns\n");
	else
		printf("\nPersonen finns inte\n");
	p = fore(liststart, "Jenny");
	printf("\n%s finns före Jenny\n", p->namn);
	skrivlista(liststart);
	exit(0);
	p = efter(liststart, "Kristina");
	printf("\n%s finns efter Kristina\n", p->namn);
	skrivlista(liststart);

	printf("\n");
	clear_mem(&liststart);

	return 0;
}
