#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100000
#define INF 0x7fff

int mybsearch(int nNum, long long *prefixSum, long long target){
	int left, right, middle;
	left = 0;
	right = nNum - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(prefixSum[middle] == target) return middle;
		else if (prefixSum[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)/2;
}

void solve(int nNum, short *num, long long *prefixSum, int bound){
	int i, j;
	prefixSum[0] = num[0];
	int min = INF;
	for(i=1; i<nNum; i++){
		prefixSum[i] = prefixSum[i-1] + num[i];
	}
	if(prefixSum[nNum - 1] < bound){
		printf("0\n");
		return ;
	}
	#if 0
	for(i=0; i<nNum; i++){
		printf("%lld ", prefixSum[i]);
	}
	printf("\n");
	#endif
	for(i=0; i<nNum; i++){
		j = mybsearch(nNum, prefixSum, prefixSum[i] + bound);
		#if 0
		printf("[%d %d]\n", i, j);
		#endif
		if((j == nNum - 1) && (prefixSum[j] - prefixSum[i] + num[j] < bound)){
			break;
		} 
		if(j - i < min){
			min = j - i;
		}
	}
	if(min == INF){
		printf("0\n");
	} else {
		printf("%d\n", min + 1);
	}
}

int main(){
	int nNum; 
	short *num;
	long long *prefixSum;
	int bound;
	int i;
	num = (short *) malloc(sizeof(short)*LEN);
	prefixSum = (long long *) malloc(sizeof(long long)*LEN);

	while(2 == scanf("%d %d", &nNum, &bound)){
		for(i=0; i<nNum; i++){
			scanf("%hd", num + i);
		}
		solve(nNum, num, prefixSum, bound);
	}	
	
	free(num);
	free(prefixSum);
	return 0;
}