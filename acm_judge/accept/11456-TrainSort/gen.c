#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#define KASE 5
#define MAX 100000
#define NNUM 2000

int *newInt(int a){
	int *p;
	p = (int *) malloc(sizeof(int));
	*p = a;
	return p;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	void *root;
	int r, count, k, *pInt, i;
	void *match;
	srand(time(NULL));
	
	printf("%d\n", KASE);
	for(k=0; k<KASE; k++){
		printf("%d\n", NNUM);
		i = 0;
		root = NULL;
		while(i < NNUM){
			r = rand() % MAX;
			pInt = newInt(r);
			match = tsearch(pInt, &root, compareInt);
			if(*(int **)match == pInt){
				i++;
				printf("%d\n", *pInt);
			} else{
				free(pInt);
			}
		}
		tdestroy(root, free);
	}
}
