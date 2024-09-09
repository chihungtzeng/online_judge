#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
#define LEN 45000
#define PRIME_NUM 4700
#define TYPE int

int buildPrimeTable(TYPE *prime, TYPE *primeSq){
	int i, j;
	char *bPrime;
	int nPrime;
	
	bPrime = (char *) malloc(LEN);
	memset(bPrime, 1, LEN);
	for(i=2; i<LEN; i++){
		if(bPrime[i]){
			for(j=i<<1; j<LEN; j+=i){
				bPrime[j] = 0;
			}
		}
	}
	nPrime = 0;
	for(i=2; i<LEN; i++){
		if(bPrime[i]){
			prime[nPrime] = i;
			primeSq[nPrime] = i * i;
			nPrime++;			
		}
	}
	#if 1
	for(i=0; i<10; i++){
		printf("%d %d\n", prime[i], primeSq[i]);
	}
	printf("\n");
	printf("nPrime =%d\n", nPrime);
	for(i=nPrime - 1, j=0; j<10; j++, i--){
		printf("prime[%d]=%d %d\n", i, prime[i], primeSq[i]);
	}  
	
	#endif
	
	free(bPrime);
	return nPrime;
}

long long solve(int n, int nPrime, TYPE *prime, TYPE *primeSq){
	long long result = 0;
	int nMultiple;
	int i;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		nMultiple = n / prime[i] - 1;
		if(primeSq[i] == n) nMultiple--;
		
		result += nMultiple * prime[i];
	}
	
	
	return result;
}

int main(){
	TYPE *prime, *primeSquare;
	int n;
	int nPrime;
	int k=1;
	long long ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	prime = (TYPE *) malloc(sizeof(TYPE)*PRIME_NUM);
	primeSquare = (TYPE *) malloc(sizeof(TYPE)*PRIME_NUM);
	nPrime = buildPrimeTable(prime, primeSquare);
	
	while(1 == fscanf(fp, "%d", &n)){
		if(n == 0) break;
		ans = solve(n, nPrime, prime, primeSquare);
		printf("Case %d: %lld\n", k++, ans);
	}
	
	free(prime);
	free(primeSquare);
	return 0;		
}