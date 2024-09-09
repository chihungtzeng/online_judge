#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3300

char *isPrime;
int *prime, *primeSq, nPrime, *prefixSum;
int *num;
int nNum;

void buildPrimeTable(){
	int i, j;
	isPrime = (char *) malloc(MAX);
	prime = (int *) malloc(sizeof(int)*MAX);
	primeSq = (int *) malloc(sizeof(int)*MAX);
	memset(isPrime, 1, MAX);
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			for(j=i<<1; j<MAX; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	nPrime = 0;
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			prime[nPrime] = i;
			primeSq[nPrime] = i*i;
			++nPrime;
		}
	}
}

int ifPrime(int n){
	int i;
	if(n < MAX) return isPrime[n];
	else {
		for(i=0; (i<nPrime) && (primeSq[i] <= n); ++i){
			if(n % prime[i] == 0) return 0;
		}
		return 1;
	}
}

int solve(){
	int i, offset, start, end, sum;
	char done;
	/*find prefix sum*/
	for(i=1; i<=nNum; i++){
		prefixSum[i] = num[i] + prefixSum[i-1]; 
	}
	#if 0
	for(i=0; i<=nNum; i++){
		printf("%d ", prefixSum[i]); 
	}
	printf("\n");
	#endif
	done = 0;
	for(offset = 1; (offset < nNum) && (!done); ++offset){
		for(start=1; (start<=nNum) && (start + offset <= nNum) && (!done); ++start){
			sum = prefixSum[start + offset] - prefixSum[start - 1];
			#if 0
				int result;
				result = ifPrime(sum);
				printf("ifPrime(%d) = %d\n", sum, result);
			#endif
			if(ifPrime(sum)){
				/*printf("%d is Prime at pos %d with offset %d\n", sum, start, offset);*/
				done = 1;
				
			}
		}
	}
	
	if(done){
		offset--;
		start--;
		printf("Shortest primed subsequence is length %d:", offset + 1);
		end = start + offset;
		for(i=start; i<=end; i++){
			printf(" %d", num[i]);
		}
		printf("\n");
	} else{
		puts("This sequence is anti-primed.");
	}
	return 0;
}

int main(){
	short nTest;
	int i;
	buildPrimeTable();
	#if 0
		for(i=0; i<100; i++){
			printf("%d ", prime[i]);
		}
		printf("\n %d primes found\n", nPrime);
	#endif
	num = (int *) malloc(sizeof(int)*10002);
	prefixSum = (int *) malloc(sizeof(int)*10002);
	prefixSum[0] = 0;
	scanf("%hd", &nTest);
	
	while(nTest--){
		scanf("%d", &nNum);
		for(i=1; i<=nNum; ++i){
			scanf("%d", num + i);
		}
		solve();
	}
	return 0;	
}