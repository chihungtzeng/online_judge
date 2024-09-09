#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int min=100000;

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void walk(const void *p, const VISIT which, const int depth){
	
	
	int x;
	x = **(int **) p;
	printf("%d is travesed at depth %d\n",x,depth);
	if(which == leaf) {
		min = x;
		
	}
		
	return;
}

int main(){
	void *root;
	int i, *value, *match;
	int prime[] = {5, 7, 23, 29, 11, 17, 19, 13};
	int nPrime = sizeof(prime)/sizeof(int);
	
	
	root = NULL;
	for(i=0; i<nPrime; i++){
		value = (int *) malloc(sizeof(int));
		*value = prime[i];
		tsearch(value, &root, compareInt);
	}

	for(i=3; i < 12; i++){
		match = tfind(&i, &root, compareInt);
		if(match == NULL){
			printf("%d is not in the tree\n", i);
		}
		else{
			match = *(int **) match;
			printf("%d is found!\n", *match);
		}
	}
	printf("----------\n");
	twalk(root, walk);
	printf("----------\n");
	printf("min=%d\n",min);
}