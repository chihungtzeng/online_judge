#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define LEN 128
#define MAX 2048
#define DEBUG 1



struct Country{
	char name[LEN];
	short nPeople;
};

struct Country *newCountry(char *name){
	assert(name != NULL);
	struct Country *c;
	c = (struct Country *) malloc(sizeof(struct Country));
	strcpy(c->name, name);
	c->nPeople = 1;
	return c;
}



int compareCountry(const void *a, const void *b){
	struct Country *x, *y;
	x = (struct Country *)a;
	y = (struct Country *)b;
	return strcmp(x->name, y->name);
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct Country *c;
	if( (which == leaf) || (which == postorder)){
		c = *(struct Country **)rootp;
		printf("%s %hd\n",c->name, c->nPeople);
	}
}

int main(){
	void *root, *match;
	struct Country *country;
	char line[LEN], cn[16];
	short nLine, i, nPerson, nCountry;
	char *tok;
	FILE *fp = stdin;

	fgets(line, LEN, fp);
	nLine = atoi(line);
	nPerson = 0;
	root = NULL;
	for(i=0; i<nLine; i++){
		fgets(line, LEN, fp);
		tok = strtok(line, " ");
		country = newCountry(tok);
		match = tsearch(country, &root, compareCountry);
		if(*(struct Country **) match != country){
			free(country);
			country = *(struct Country **) match;
			country->nPeople += 1;
		}
	}
	twalk(root, twalkAction);
	tdestroy(root, free);
	
	return 0;
}