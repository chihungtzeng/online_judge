#include <stdio.h>
#include <stdlib.h>
#define MAX 5000001
#define SQMAX 2237


int *prime;
int nPrime;
int *nDeprime;

void buildPrimeTable(){
	int t, i;
	char isPrime;
	
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	
	t = 7;
	while(t <= SQMAX){
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int isPrime(int n){
	int *match, i;
	if (n <= SQMAX){
		match = bsearch(&n, prime, nPrime, sizeof(int), compareInt);
		if(match) return 1;
		else return 0;
	}

	for(i=0; (i<nPrime) && (prime[i] * prime[i] <= n); i++){
		if(n % prime[i] == 0) return 0; 
	}
	
	return 1;
}

int isDeprime(int n){
	int i, sum=0;
	/*if(isPrime(n)) return 1;*/
	
	for(i=0; (i < nPrime) && (prime[i]*prime[i] <= n); i++){
		if(n % prime[i] == 0){
			sum += prime[i];
			do{
				n = n / prime[i];
			} while(n % prime[i] == 0);
		}
	}
	if(n > 1){
		sum += n;
	}
	if(isPrime(sum)) return 1;
	else return 0;
}

int main(){
	int i, a, b;
	prime = (int *) malloc(sizeof(int)*MAX);
	nDeprime = (int *) malloc(sizeof(int)*MAX);
	buildPrimeTable();
	/*
	for(i=0; i<100; i++){
		printf("%d ", prime[i]);
	}
	printf("\n%d primes, last one:%d\n",nPrime, prime[nPrime - 1]);
	*/
	nDeprime[0] = 0;
	nDeprime[1] = 0;
	nDeprime[2] = 1;
	
	for(i=3; i<MAX; i++){
		if(isDeprime(i)){
			nDeprime[i] = nDeprime[i-1] + 1;
		}
		else{
			nDeprime[i] = nDeprime[i-1];
		}
	}

	while(1){
		scanf("%d", &a);
		if(0 == a){
			break;
		}
		scanf("%d",&b);
		
		printf("%d\n", nDeprime[b] - nDeprime[a - 1]);
		
	}
	
	free(prime);
	free(nDeprime);	
	return 0;
}
