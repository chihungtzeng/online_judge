#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 21
#define LINE_LEN 1024
#define DEBUG 0
#define TRUE 1
#define FALSE 0

typedef int (*pfn)(int, int);

struct Party{
	char name[LEN];
	int rate;
};


int compareParty(const void *a, const void *b){
	struct Party *x, *y;
	x = (struct Party *)a;
	y = (struct Party *)b;
	return strcmp(x->name, y->name);
}

int LE(int a, int b){
	return (a < b)? TRUE : FALSE;
}

int GE(int a, int b){
	return (a > b)? TRUE : FALSE;
}

int LEQ(int a, int b){
	return (a <= b)? TRUE : FALSE;
}

int GEQ(int a, int b){
	return (a >= b)? TRUE: FALSE; 
}

int EQ(int a, int b){
	return (a == b)? TRUE: FALSE;
}



int checkResult(int ans, char *op, int n){
	 pfn pfnOp;
	 if(!strcmp(op, "=")) pfnOp = EQ;
	 else if (!strcmp(op, "<")) pfnOp = LE;
	 else if (!strcmp(op, ">")) pfnOp = GE;
	 else if (!strcmp(op, "<=")) pfnOp = LEQ;
	 else if (!strcmp(op, ">=")) pfnOp = GEQ;
	 
	 return pfnOp(ans, n);
}

int convertRate(char r[]){
/*r is a xx.x -> return xxx*/
	int result = 0;
	char *p;
	p = r;
	while(*p != '\0'){
		if(*p != '.'){
			result = result*10 + *p - '0';
		}
		p++;
	}	
	return result;
}

int main(){
	int nGuess, nParty, i, j, k = 1;
	int n;
	int ans;
	char rate[5];
	char *op;
	struct Party *party, query, *match;
	FILE *fp = (DEBUG)? fopen("in.txt", "r"):stdin;

	fscanf(fp, "%d %d", &nParty, &nGuess);
	party = (struct Party *) malloc(sizeof(struct Party)*nParty);
	for(i=0; i<nParty; i++){
		fscanf(fp, "%s %s", party[i].name, rate);
		party[i].rate = convertRate(rate);
	}	
	qsort(party, nParty, sizeof(struct Party), compareParty);
	#if DEBUG
	for(i=0; i<nParty; i++){
		printf("%s %d\n", party[i].name, party[i].rate);
	}	
	#endif
	for(i=0; i<nGuess; i++){
		fscanf(fp, "%s", query.name);
		ans = 0;
		while(isalnum(query.name[0]) || (query.name[0] == '+')){
			match = (struct Party *) bsearch(&query, party, nParty, sizeof(struct Party), compareParty);
			if(match){
				ans += match->rate;
			}
			fscanf(fp, "%s", query.name);
		}
		op = query.name;
		fscanf(fp, "%d", &n);
		n = n * 10;
		if(checkResult(ans, op, n) == TRUE){
			printf("Guess #%d was correct.\n", k++);
		} else{
			printf("Guess #%d was incorrect.\n", k++);
		}
	}

	free(party);	
	return 0;
}