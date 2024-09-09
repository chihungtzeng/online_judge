#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>
#include <math.h>
#define MAX 65
#define BOUND 65536

char *cprime;
int nPossiblePow, *possiblePow;


void buildTable(){
	int t, i;
	cprime = (char *) malloc(sizeof(char)*MAX);
	memset(cprime, 1, sizeof(char)*MAX);
	for(t=2; t<MAX; t++){
		if(cprime[t]){
			for(i=t << 1; i < MAX; i += t){
				cprime[i] = 0;
			} 
		}
	}
	nPossiblePow = 0;
	possiblePow = (int *) malloc(sizeof(int)*MAX);
	for(i=4; i< MAX; i++){
		if(!cprime[i]){
			possiblePow[nPossiblePow++] = i;
		}
	}
	#if 0
	for(i=0; i<nPossiblePow; i++){
		printf("%d ", possiblePow[i]);
	}
	printf("\n");
	#endif
	free(cprime);
}

int compareLL(const void *a, const void *b){
	unsigned long long x, y;
	x = *(unsigned long long *)a;
	y = *(unsigned long long *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

unsigned long long mypow(int b, int k){
	/*return b^k*/
	unsigned long long result = 1;
	if(k==0) return 1;
	result = mypow(b, k >> 1);
	result = result * result;
	if(k & 1) result *= b;
	return result;
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
	if((way == leaf) || (way == postorder)){
		printf("%llu\n", **(unsigned long long **)rootp);
	}
}

unsigned long long *newLL(unsigned long long n){
	unsigned long long *ell;
	ell = (unsigned long long *) malloc(sizeof(unsigned long long));
	*ell = n;
	return ell;
}

int main(){
	int i, k;
	void *root = NULL, *match;
	unsigned long long *ans;
	int nIteration;
	buildTable();

	ans = newLL(1);
	tsearch(ans, &root, compareLL);
	
	for(i=2; i<BOUND; i++){
		nIteration = (int) ceil(64.0/log2(i));
		for(k = 0; possiblePow[k] < nIteration; k++){
			ans = newLL(mypow(i, possiblePow[k]));
			match = tsearch(ans, &root, compareLL);
			if(*(unsigned long long **)match != ans){
				free(ans);
			}
		}
	}	
	
	twalk(root, twalkAction);
	tdestroy(root, free);
	free(possiblePow);
	return 0;
}