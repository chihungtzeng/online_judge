#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 65536
#define NELE 4096

enum {
	PROPER_SUBSET,
	DISJOINT,
	INTERSECT
};

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int parseLine(int *set, char line[]){
	char *tok;
	int i=0;
	tok = strtok(line, " \t\n");
	while(tok){
		set[i++] = atoi(tok);
		tok = strtok(NULL, " \t\n");
	}
	return i;
}

int isSubset(int *setA, int sizeA, int *setB, int sizeB){
	void *match;
	int i, nMatch;
	for(i=0, nMatch = 0; i<sizeA; i++){
		match = bsearch(setA + i, setB, sizeB, sizeof(int), compareInt);
		if(match) {
			nMatch++;
		}
	}
	if(nMatch == 0) return DISJOINT;
	if(nMatch == sizeA) return PROPER_SUBSET;
	else return INTERSECT;
}

void solve(char *line[2]){
	int *set[2], nEle[2];
	int i;
	int verdict[2];
	for(i=0; i<2; i++){
		set[i] = (int *) malloc(sizeof(int)*NELE);
		nEle[i] = parseLine(set[i], line[i]);
		qsort(set[i], nEle[i], sizeof(int), compareInt);
	}

	do {
		verdict[0] = isSubset(set[0], nEle[0], set[1], nEle[1]);
		if(verdict[0] == DISJOINT){
			puts("A and B are disjoint");
			break;
		}
		verdict[1] = isSubset(set[1], nEle[1], set[0], nEle[0]);
		if((verdict[0] == PROPER_SUBSET) && (verdict[1] == PROPER_SUBSET)){
			puts("A equals B");
		} else if ((verdict[0] == PROPER_SUBSET) && (verdict[1] != PROPER_SUBSET)){
			puts("A is a proper subset of B");
		} else if ((verdict[0] != PROPER_SUBSET) && (verdict[1] == PROPER_SUBSET)){
			puts("B is a proper subset of A");
		} else if ((verdict[0] != PROPER_SUBSET) && (verdict[1] != PROPER_SUBSET)){
			puts("I'm confused!");
		}
	} while(0);
	
	for(i=0; i<2; i++){
		free(set[i]);
	}
}

int main(){
	char *line[2];
	int i;
	for(i=0; i<2; i++){
		line[i] = (char *) malloc(sizeof(char)*LEN);
	}	
	

	while(NULL != fgets(line[0], LEN, stdin)){
		fgets(line[1], LEN, stdin);
		solve(line);
	}	
	
	for(i=0; i<2; i++){
		free(line[i]);
	}	
	return 0;
}
