#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 262144
#define LEN 18
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)
#define DEBUG 1

int set[MAX];
char hasOne[LEN], hasZero[LEN];
int nEle;
int largestIndex, smallestIndex;

int completeSet(){
	int i, j, nBit, ans;
	int start = 0, end = nEle - 1, tmp;
	
	if(set[smallestIndex] == 0){
		SWAP(set[smallestIndex], set[0]);
		start = 1;
		if(0 == largestIndex){
			largestIndex = smallestIndex;
		} 
	}
	tmp = set[largestIndex] + 1;
	if((tmp ^ (tmp - 1)) == 0){
		SWAP(set[largestIndex], set[end]);
		end -= 1;
	}
	
	for(i=0; i<= end; i++){
		for(j=0; j<LEN; j++){
			if((set[i] >> j) & 1){
				hasOne[j] = 1;
			} else {
				hasZero[j] = 1;
			}
		}
	}
	nBit = 0;
	for(i=0;i<LEN; i++){
		if(hasOne[i] + hasZero[i] == 2){
			if(DEBUG) {
				printf("bit %d has 0 and 1\n",i);
			}
			nBit += 1;
		}
	}
	ans = (1 << nBit) - nEle;
	
	return ans;
}

int main(){
	short nTest, k = 1;
	int i, ans, j, tmp;
	 
	scanf("%hd", &nTest);
	
	while(nTest > 0){
		--nTest;
		scanf("%d", &nEle);
		memset(hasZero, 0, LEN);
		memset(hasOne, 0, LEN);
		largestIndex = 0;
		smallestIndex = 0;
		for(i=0; i<nEle; i++){
			scanf("%d", set + i);
			if(set[i] > set[largestIndex]){
				largestIndex = i;
			}
			if(set[i] < set[smallestIndex]){
				smallestIndex = i;
			}
		}
		if(DEBUG){
			for(i=0; i<nEle; i++){
				printf("%d ", set[i]);
			}
			printf("\n");
		}
		ans = completeSet();
		printf("Case #%hd: %d\n", k++, ans);
	}
	return 0;
}
