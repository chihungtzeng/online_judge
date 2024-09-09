#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1001

struct Sum{
	int sum, x, y;
};

int nQuery, query[25], nSum;
int input[LEN], nInput;
struct Sum *pSum[501501];

struct Sum* newSum(int x, int y){
	struct Sum *p;
	p = (struct Sum *) malloc(sizeof(struct Sum));
	p->sum = x + y;
	p->x = x;
	p->y = y;
	return p;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}
int compareSum(const void *a, const void *b){
	struct Sum *p, *q;
	p = *(struct Sum **)a;
	q = *(struct Sum **)b;
	return p->sum - q->sum;
}

int mybsearch(int target){
	int left, right, middle;
	
	left = 0;
	right = nSum - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(pSum[middle]->sum == target) return middle;
		else if (pSum[middle]->sum < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)/2;
}

void solve(short kase){
	int i, j;
	int x, y;
	
	/*remove identical numbers*/
	/*
	qsort(input, nInput, sizeof(int), compareInt);
	for(i=1, j = 0; i<nInput; i++){
		if(input[i] != input[j]){
			j += 1;
			input[j] = input[i];
		}
	}
	nInput = j + 1;
	*/
	
	for(i=0, nSum = 0; i<nInput; i++){
		for(j=i+1; j<nInput; j++){
			x = (input[i] < input[j])? input[i] : input[j];
			y = input[i] + input[j] - x;
			pSum[nSum++] = newSum(x, y);
		}
	} 
	qsort(pSum, nSum, sizeof(struct Sum *), compareSum);
	#if 0
	for(i=0; i<nSum; i++){
		printf("%d = %d %d\n", pSum[i]->sum, pSum[i]->x, pSum[i]->y);
	}	
	#endif
	printf("Case %hd:\n", kase);
	for(i=0; i<nQuery; i++){
		j = mybsearch(query[i]);
		
		if(query[i] != pSum[j]->sum){
			if((j < nSum - 1)){
				if(pSum[j+1]->sum - query[i] < query[i] - pSum[j]->sum){
					j = j + 1;
				}
			} 
		}
		printf("Closest sum to %d is %d.\n", query[i], pSum[j]->sum);
	}
	
	for(i=0; i<nSum; i++){
		free(pSum[i]);
	}
}

int main(){
	short i, kase=1;
	FILE *fp = stdin;
	while(1 ==	fscanf(fp, "%d", &nInput)){
		if(nInput == 0) return 0;
		for(i=0; i<nInput; i++){
			fscanf(fp, "%d", input+i);
		}
		fscanf(fp, "%d", &nQuery);
		for(i=0; i<nQuery; i++){
			fscanf(fp, "%d", query + i);
		}
		solve(kase);
		kase += 1;
	}
	return 0;
}
