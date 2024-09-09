#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

struct Num {
	int value;
	int occr;
};

struct Node {
	int value;
	int index;
};

int compareNode(const void *a, const void *b){
	struct Node *x, *y;
	x = (struct Node *)a;
	y = (struct Node *)b; 
	return x->value - y->value;
}



int main(){
	int nNum;
	struct Num *num;
	int input, i;
	struct Node *pNode;
	void *root = NULL;
	void *match;

	num = (struct Num *) malloc(sizeof(struct Num)*MAX);
	memset(num, 0, sizeof(int)*MAX);
	nNum = 0;
	
	while(1 == scanf("%d", &input)){
		pNode = (struct Node *) malloc(sizeof(struct Node));
		pNode->value = input;
		match = tsearch(pNode, &root, compareNode);
		if(*(struct Node **)match == pNode){
			pNode->index = nNum;
			num[nNum].value = input;
			num[nNum].occr = 1;
			nNum++;
		} else{
			free(pNode);
			pNode = *(struct Node **)match;
			num[pNode->index].occr += 1;
		}
	}
	for(i=0; i<nNum; i++){
		printf("%d %d\n", num[i].value, num[i].occr);
	}
	tdestroy(root, free);
	free(num);	
	
	return 0;
}