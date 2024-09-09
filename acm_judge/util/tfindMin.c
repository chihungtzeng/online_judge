#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <setjmp.h>
#define MAX 1000

int count;
int min;
jmp_buf buf;

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void twalkAction(const void *rootp, const VISIT which, int depth){
	count++;
	if(which == leaf){
		min = **(int **) rootp;
	}
}

void twalkActionForMin(const void *rootp, const VISIT which, int depth){
	count++;
	if(which == leaf){
		min = **(int **) rootp;
		longjmp(buf, 1);
	}
}

void tfindmin(void *root){
	if(setjmp(buf)){
	}
	else{
		twalk(root, twalkActionForMin);
	}
}

int main(){
	
	void *root;
	int *x, i;
	
	min = -1;
	root = NULL;
	for(i=1; i<=65536; i++){
		x = (int *) malloc(sizeof(int));
		*x = 2*i;
		tsearch(x, &root, compareInt);
	}
	count = 0;
	twalk(root, twalkAction);
	printf("original count=%d min=%d\n", count, min);
	count = 0;
	tfindmin(root);
	printf("original count=%d min=%d\n", count, min);
	
}