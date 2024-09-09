#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

int prime[MAX];
int *prefixSum;
short nPrime;

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void buildPrimeTable(){
	int i, j;
	char cPrime[MAX];
	memset(cPrime, 1, MAX);
	nPrime=0;
	for(i=2; i<MAX; i++){
		if(cPrime[i]){
			prime[nPrime++] = i;
			for(j=i<<1; j<MAX; j+=i){
				cPrime[j] = 0;
			}
		}
	}
	
	prefixSum = (int *) malloc(sizeof(int)*nPrime);
	prefixSum[0] = prime[0];
	for(i=1; i<nPrime; i++){
		prefixSum[i] = prefixSum[i-1] + prime[i];
	}
	#if 0
	for(i=0; i<100; i++){
		printf("%hd ", prime[i]);
	}
	for(i=nPrime - 20; i<nPrime; i++){
		printf("%hd ", prime[i]);
	}
	printf("\n");
	for(i=nPrime - 20; i<nPrime; i++){
		printf("%d ", prefixSum[i]);
	}
	printf("\n");
	printf("nPrime=%d\n", nPrime);
	#endif
}

int mybsearch(int target){
	int left = 0;
	int right = nPrime - 1;
	int middle;
	while(left <= right){
		middle = (left + right) >> 1;
		if(prefixSum[middle] == target){
			return middle;
		} else if (prefixSum[middle] < target){
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}
	return (left + right) / 2;
}

void solve(int n){
	int count = 0;
	int i, j;
	for(i=0; i<nPrime; i++){
		j = mybsearch(n + prefixSum[i]);
		if(prefixSum[j] - prefixSum[i] + prime[i] == n){
			#if 0
			int k;
			printf("%d = ", n);
			for(k=i; k<=j; k++){
				printf("%d ", prime[k]);
			}
			printf("\n");
			#endif
			count++;
		}		
	}
	printf("%d\n", count);
}

int main(){
	int n;
	buildPrimeTable();
	while(1 == scanf("%d", &n)){
		if(n == 0) break;
		else solve(n);
	}
	free(prefixSum);
	return 0;
}