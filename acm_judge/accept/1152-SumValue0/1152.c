#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define LEN 4001
#define LEN2 16000001

struct Num {
	int value;
	int occr;
};

struct Num *newNum(int n){
	struct Num *ptr;
	ptr = (struct Num *) malloc(sizeof(struct Num));
	ptr->value = n;
	ptr->occr = 1;
	return ptr;
}

int compareNum(const void *a, const void *b){
	struct Num *x, *y;
	x = (struct Num *)a;
	y = (struct Num *)b;
	return x->value - y->value;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int mybsearch(int nSize, int *sum, int target){
	int left = 0, right = nSize - 1, middle;
	while(left <= right){
		middle = (left + right) >> 1;
		if(sum[middle] == target) return middle;
		else if (sum[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)/2;
}


int findTargetNum(int nSize, int *sum, int target){
	int result = 1;
	int index, i;
	index = mybsearch(nSize, sum, target);
	if(sum[index] != target) return 0;
	
	
	for(i=index -1; (i>=0) && (sum[i] == target); i--){
		result++;
	}
	for(i=index +1; (i < nSize) && (sum[i] == target); i++){
		result++;
	}
	return result;
}

void solve(int nNum, int A[4][LEN]){
	void *root = NULL;
	struct Num *targetNum, *match;
	int i, j, k = 0;
	int nPair = 0, target;
	int *sum;
	
	sum = (int *) malloc(sizeof(int)*LEN2);

	for(i=0; i<nNum; i++){
		for(j=0; j<nNum; j++){
			sum[k++] = A[0][i] + A[1][j];
		}
	}
	qsort(sum, k, sizeof(int), compareInt);
	
	
	for(i=0; i<nNum; i++){
		for(j=0; j<nNum; j++){
			target = -A[2][i] - A[3][j];
			nPair += findTargetNum(k, sum, target); 
		}
	}
	printf("%d\n", nPair);
	
	free(sum);
}

int main(){
	char first = 1;
	int nTest;
	int A[4][LEN];
	int nNum;
	int i, j;
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &nNum);
		for(i=nNum, j = 0; i>0; i--, j++){
			scanf("%d %d %d %d", &A[0][j], &A[1][j], &A[2][j], &A[3][j]);
		}
		if(first){
			first = 0;
		} else {
			printf("\n");
		}
		solve(nNum, A);
	}
	return 0;
}