#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define LEN 16
#define LINELEN 32
#define DEBUG 0


struct HashEntry{
	char *eng;
	char *dialet;
};

struct HashEntry *newHashEntry(char *eng, char *dialet){
	struct HashEntry *h;
	h = (struct HashEntry *) malloc(sizeof(struct HashEntry));
	h->eng = strdup(eng);
	h->dialet = strdup(dialet);
	return h;
}

int compareHashEntry(const void *a, const void *b){
	struct HashEntry *x, *y;
	x = (struct HashEntry *)a;
	y = (struct HashEntry *)b;
	return strcmp(x->dialet, y->dialet);
}



int main(){
	void *root;
	char eng[LEN], dialet[LEN];
	char line[LINELEN];
	struct HashEntry *h, *match;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	root = NULL;
	while(NULL != fgets(line, LINELEN, fp)){
		if(line[0] == '\n') break;
		
		if(2 != sscanf(line, "%s %s", eng, dialet)){
			printf("error parsing line\n");
			exit(0);
		}
		h = newHashEntry(eng, dialet);
		tsearch(h, &root, compareHashEntry);		
	}
	while(NULL != fgets(line, LINELEN, fp)){
		sscanf(line, "%s", dialet);
		h = newHashEntry("", dialet);
		match = tfind(h, &root, compareHashEntry);
		if(match == NULL){
			puts("eh");
		} 
		else{
			match = *(struct HashEntry **) match;
			puts(match->eng);
		}
		free(h);
	}
	tdestroy(root, free);
	return 0;
}