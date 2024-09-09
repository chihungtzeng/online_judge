#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define LEN 32

struct Specie{
	char name[32];
	int nTree;
};

int totalTree;

struct Specie *newSpecie(char name[]){
	struct Specie *s;
	s = (struct Specie *) malloc(sizeof(struct Specie));
	s->nTree = 1;
	strcpy(s->name, name);
	return s;
}

int compareSpecie(const void *a, const void *b){
	struct Specie *x, *y;
	x = (struct Specie *)a;
	y = (struct Specie *)b;
	return strcmp(x->name, y->name);
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct Specie *s;
	if( (which == leaf) || (which == postorder)){
		s = *(struct Specie **)rootp;
		printf("%s %.4lf\n", s->name, 100.0*s->nTree/totalTree);
	}
}

int main(){
	char line[LEN], *state;
	char first = 1;
	short nTest;
	FILE *fp = stdin;
	void *root = NULL;
	void *match;
	int len;
	struct Specie *specie;	

	fgets(line, LEN, fp);
	nTest = atoi(line);
	fgets(line, LEN, fp);
	totalTree = 0;
	
	while(nTest >= 1){
		state = fgets(line, LEN, fp);
		if((state == NULL) || (line[0] == '\n')){
			if(first){
				first = 0;
			}
			else{
				printf("\n");
			}
			twalk(root, twalkAction);			
			tdestroy(root, free);
			root = NULL;
			nTest--;
			totalTree = 0;
		}
		else{
			totalTree++;
			len = strlen(line);
			line[--len] = '\0';
			specie = newSpecie(line);
			match = tsearch(specie, &root, compareSpecie);
			if(*(struct Specie **)match != specie){
				free(specie);
				specie = *(struct Specie **) match;
				specie->nTree += 1;
			}
		}
	}		
	return 0;
}