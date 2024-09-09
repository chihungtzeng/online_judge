#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001
#define NINF -2147483647
#define DEBUG 0


int solve(int nEle, int score[]){
	int i, j, half, pos;
	int candidate[3], largest = NINF;
	int *pool;
	/*modified merge sort*/	
	if(nEle <= 1) return NINF;
	/*if(nEle == 2) return score[0] - score[1];*/

	half = nEle >> 1;
	candidate[0] = solve(half, score);
	candidate[1] = solve(nEle - half, score + half);
	/* now the two subarrays are sorted*/
	candidate[2] = score[half - 1] - score[half];
	/*begin merge sort*/
	i = 0;
	j = half;
	pos = 0;
	pool = (int *) malloc(sizeof(int)*nEle);
	while((i < half) && (j < nEle)){
		if(score[i] <= score[j]){
			pool[pos++] = score[i++];
		} else {
			pool[pos++] = score[j++];
		}
	}
	while(i < half) pool[pos++] = score[i++];
	while(j < nEle) pool[pos++] = score[j++];

	#if DEBUG
		for(i=0; i<nEle; i++){
			printf("%d ", pool[i]);
		}
		printf("\n");
	#endif	
	
	memcpy(score, pool, sizeof(int)*nEle);
	free(pool);
	for(i=0; i<3; i++){
		if(candidate[i] > largest) largest = candidate[i];
	}
	return largest;
}

int main(){
	char nTest;
	int i, ans;
	int *score;
	int nEle;
	FILE *fp = stdin;
	#if DEBUG
		fp = fopen("in2.txt", "r");
	#endif
	fscanf(fp, "%hhd", &nTest);
	score = (int *) malloc(sizeof(int)*MAX);
	
	while(nTest > 0){
		nTest--;
		fscanf(fp, "%d", &nEle);
		for(i=0; i<nEle; i++){
			fscanf(fp, "%d", score + i);
		}
		ans = solve(nEle, score);
		printf("%d\n", ans);
	}
	free(score);
	
	return 0;
}