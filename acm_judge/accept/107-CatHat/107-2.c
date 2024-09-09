#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define MAX 2147483648

struct Entry{
	long nk, nkplus1;
	int n, k;
};

struct Entry *newEntry(long nk, long nkplus1, int n, int k){
	struct Entry *e;
	e = (struct Entry *) malloc(sizeof(struct Entry));
	e->nk = nk;
	e->nkplus1 = nkplus1;
	e->n = n;
	e->k = k;
	return e;
}

int compareEntry(const void *a, const void *b){
	struct Entry *x, *y;
	x = (struct Entry *)a;
	y = (struct Entry *)b;
	if(x->nk != y->nk) return x->nk - y->nk;
	else if(x->nkplus1 != y->nkplus1) return x->nkplus1 - y->nkplus1;
	else return 0;
}

int main(){
	void *root;
	long height, nWorker;
	long nonWorker, stackHeight, tmp;
	int N, k, h, nPlusOne;
	char done;
	struct Entry *e, *match;
	long i, j, n, nk, nkplus1;
	
	root = NULL;
	for(n=2; n*n <= MAX; n++){
		nPlusOne = n + 1;
		nk = n;
		nkplus1 = nPlusOne; 
		for(k=2; nkplus1 <= MAX ;k++){
			nk = nk* n;
			nkplus1 = nkplus1 * nPlusOne;
			
			e = newEntry(nk, nkplus1, n, k);
			tsearch(e, &root, compareEntry);
		}
		
	}
	
	while(2 == scanf("%ld %ld", &height, &nWorker)){
		if((0 == height) && (0 == nWorker)){
			break;
		}
		if(height == 1){
			printf("0 1\n");
			continue;
		}
		if(nWorker == 1){
			nonWorker = -1;
			stackHeight = 0;
			while(height >= 1){
				stackHeight += height;
				nonWorker++;
				height = height >> 1;
			}
			printf("%ld %ld\n",nonWorker, stackHeight);
			continue;
		}
		
		if(height - nWorker > 1){
			e = newEntry(nWorker, height, 0, 0);
			match = tfind(e, &root, compareEntry);
			free(e);
			if(match == NULL) {
				printf("not found\n");
				exit(1);
			}
			match = *(struct Entry **)match;
			N = match->n;
		}
		else{
			N = nWorker;
		}
		
		nonWorker = 0;
		nPlusOne = N + 1;
		height = 1;
		tmp = nWorker;
		stackHeight = 0;
		while(tmp > 0){
			stackHeight += tmp*height;
			height = height*nPlusOne;
			
			tmp = tmp /N;
			nonWorker += tmp ;
		}
		
		
		printf("%ld %ld\n", nonWorker, stackHeight);
	}
	tdestroy(root, free);
	return 0;
}
