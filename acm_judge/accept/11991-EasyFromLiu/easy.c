#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 100001 

struct Element{
	int value;
	int nOccr;
	int *pos;
	int capacity;
};

struct Element *newElement(int v, int pos){
	struct Element *e;
	e = (struct Element *) malloc(sizeof(struct Element));
	e->value = v;
	e->nOccr = 1;
	e->capacity = 4;
	e->pos = (int *) malloc(sizeof(int)*4);
	e->pos[0] = pos;
	return e;
} 

void freeElement(void *ein){
	struct Element *e;
	if(ein == NULL) return;
	e = (struct Element *) ein;
	free(e->pos);
	free(e);
	return ;
}

int compareElement(const void *a, const void *b){
	struct Element *x, *y;
	x = (struct Element *)a;
	y = (struct Element *)b;
	return x->value - y->value;
}

void addElement(void **eRoot,int v, int pos){
	struct Element *e;
	void *match;
	e = newElement(v, pos);
	match = tfind(e, eRoot, compareElement);
	if(match == NULL){
		tsearch(e, eRoot, compareElement);
	} else{
		freeElement(e);
		e = *(struct Element **) match;
		if(e->nOccr == e->capacity){
			e->capacity <<= 1;
			e->pos = realloc(e->pos, sizeof(int)*e->capacity);
		}
		e->pos[e->nOccr] = pos;
		e->nOccr += 1;
	}
}

int findAns(void **eRoot, int value, int idx){
	struct Element e, *target;
	void *match;
	e.value = value;
	match = tfind(&e, eRoot, compareElement);
	if(!match) return 0;
	target = *(struct Element **)match;
	if(idx > target->nOccr) return 0;
	else return target->pos[idx - 1];  
} 

int main(){
	void *eRoot;
	int nValue, nQuery;
	int value, i, idx, ans;
	while(2 == scanf("%d %d", &nValue, &nQuery)){
		eRoot = NULL;
		for(i=1; i<=nValue; i++){
			scanf("%d", &value);
			addElement(&eRoot, value, i);
		}
		for(i=0; i<nQuery; i++){
			scanf("%d %d", &idx, &value);
			/*printf("idx=%d value=%d\n", idx, value);*/
			ans = findAns(&eRoot, value, idx);
			printf("%d\n", ans);
		}
		tdestroy(eRoot, freeElement);
	}
	return 0;
}