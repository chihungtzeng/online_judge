#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001
#define NINF -2147483647
#define DEBUG 0


int solve(int nEle, int score[], int pool[]){
	int i;
	int candidate[3], largest = NINF;
	int min = 2147483647, diff;
	
	/*pool[i] is the minimum among score[i .. nEle - 1]*/
	
	
	for(i=nEle - 1; i>=1; i--){
		if(score[i] < min){
			pool[i] = score[i];
			min = pool[i];
		} else {
			pool[i] = min;
		}
	}
	for(i=nEle - 2; i>=0; i--){
		diff = score[i] - pool[i+1];
		if(diff > largest){
			largest = diff;
		}
	}
	return largest;
}

int main(){
	char nTest;
	int i, ans;
	int *score;
	int nEle;
	FILE *fp = stdin;
	int *pool;
	#if DEBUG
		fp = fopen("in2.txt", "r");
	#endif
	fscanf(fp, "%hhd", &nTest);
	score = (int *) malloc(sizeof(int)*MAX);
	pool = (int *) malloc(sizeof(int)*MAX);
	while(nTest > 0){
		nTest--;
		fscanf(fp, "%d", &nEle);
		for(i=0; i<nEle; i++){
			fscanf(fp, "%d", score + i);
		}
		ans = solve(nEle, score, pool);
		printf("%d\n", ans);
	}
	free(score);
	free(pool);
	return 0;
}