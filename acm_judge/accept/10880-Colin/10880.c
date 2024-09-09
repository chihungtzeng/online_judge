#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 44722
#define LEN 5000


char *isPrime;
int nPrime;
int prime[LEN];
int primeSq[LEN];
int Q, C, G, R;

int compareInt(const void *a, const void *b){
	int x, y;
	x = *(int *)a;
	y = *(int *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

void buildPrimeTable(){
	int i,j;
	isPrime = (char *) malloc(MAX);
	memset(isPrime, 1, MAX);
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			for(j=i << 1; j < MAX; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	nPrime = 0;
	for(i=2; i<MAX; i++){
		if(isPrime[i]) {
			prime[nPrime] = i;
			primeSq[nPrime++] = i*i;
		}
	}
	/*
	while(prime[nPrime - 1] > MAX){
		nPrime--;
	}*/
	free(isPrime);
}

int factoring(int n, int primeFactor[], int primePow[]){
	/*	factorizing n, return value: nPrimeFactor*/
	int nPrimeFactor = 0, i;
	for(i = 0; (i<nPrime) && primeSq[i] <= n; i++){
		if(n % prime[i] == 0){
			primeFactor[nPrimeFactor] = prime[i];
			primePow[nPrimeFactor] = 0;
			do {
				primePow[nPrimeFactor]++;
				n = n / prime[i];
			} while (n % prime[i] == 0);
			nPrimeFactor++;
		}
	}
	if(n > 1){
		primeFactor[nPrimeFactor] = n;
		primePow[nPrimeFactor] = 1;
		nPrimeFactor++;
	}
	return nPrimeFactor;
}

int genAllFactor(int output[], int nPrimeFactor, int primeFactor[], int primePow[]){
	int x, i, j, nEle, pos;
	if(nPrimeFactor <= 0) return 0;
	if(nPrimeFactor == 1) {
		for(x=1, i=0; i <= primePow[0]; i++, x *= primeFactor[0]){
			output[i] = x;
		}
		return primePow[0] + 1;
	} else{
		nEle = genAllFactor(output, nPrimeFactor - 1, primeFactor + 1, primePow + 1);
		x = primeFactor[0];
		pos = nEle;
		for(i=1; i<= primePow[0]; i++){
			for(j=0; j < nEle; j++){
				output[pos++] = output[j] * x; 
			} 
			x = x * primeFactor[0];
		}
		return pos;
	}	
}

void solve(int n){
	/*print all factors of n*/
	int nPrimeFactor, nFactor;
	int primeFactor[64], primePow[64], factor[2048];
	int i;
	if(n == 0){
		printf(" 0\n");
		return ;
	}
	if((n == 1) && (R == 0)){
		printf(" 1\n");
		return;
	}
	
	
	nPrimeFactor = factoring(n, primeFactor, primePow);
	nFactor = genAllFactor(factor, nPrimeFactor, primeFactor, primePow);
	qsort(factor, nFactor, sizeof(int), compareInt);
	
	for(i=0; (i<nFactor); i++){
		if((factor[i] > R)){
			printf(" %d", factor[i]);
		}
	}
	printf("\n");
	return;
}

int main(){
	int i, k = 1, nTest;
	buildPrimeTable();
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d", &C, &R);
		printf("Case #%d:", k++);
		solve(C - R);
	}	
	
	return 0;	
}