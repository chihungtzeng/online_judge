#include <stdio.h>
#include <search.h>
#include <stdlib.h>

struct Num{
	int x;
	int occr;
	int nSmall;
};

struct Num *newNum(int x){
	struct Num *n;
	n = (struct Num *) malloc(sizeof(struct Num));
	n->x = x;
	n->occr = 1;
	n->nSmall = 0;
	return n; 
}

int compareNum(const void *a, const void *b){
	struct Num *p, *q;
	p = (struct Num *)a;
	q = (struct Num *)b;
	return p->x - q->x;
}

int compareNumForInsertion(const void *a, const void *b){
	struct Num *p, *q;
	p = (struct Num *)a;
	q = (struct Num *)b;
	printf("p->x = %d q->x = %d *** ",p->x, q->x);
	if(p->x == q->x) {
		printf("%d occr: %d->%d\n",q->x, q->occr, q->occr+1);
		q->occr += 1;
		return 0;
	}
	else if(p->x < q->x){
		printf("%d nSmall: %d->%d, go left\n",q->x, q->nSmall, q->nSmall+1);
		q->nSmall += 1;
		return -1;
	}
	printf("%d nSmall %d->%d, go right\n", p->x, p->nSmall, q->nSmall + q->occr);
	p->nSmall = q->nSmall + q->occr;
	
	return 1;
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct Num *n;
	if( (which == leaf) || (which == postorder)){
		n = *(struct Num **) rootp;
		printf("%d(occr = %d, nSmall = %d)\n",n->x, n->occr, n->nSmall);
	}
}

void *mytsearch(void *e, void **root, int (*compare)()){
	void *match;
	struct Num *n;
	match = tsearch(e, root, compareNumForInsertion);
	/*
	match = tfind(e, root, compare);
	if(match == NULL) {
		tsearch(e, root, compare);
		return e;
	}
	else{
		n = *(struct Num **) match;
		n->occr += 1;
		return n;
	}
	*/
}

int main(){
	void *root = NULL;
	struct Num *n, *match;
	int i, j;	
	for(i=1; i<5; i++){
		
		j = 2*i;
		printf("***generate i=%d and j=%d****\n",i, j);
		n = newNum(i);
		mytsearch(n, &root, compareNum);
		
		n = newNum(j);
		match = mytsearch(n, &root, compareNum);
		
	}
	twalk(root, twalkAction);
	printf("\n");
	tdestroy(root, free);
}