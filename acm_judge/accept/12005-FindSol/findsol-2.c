#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 40000000000000LL
#define NPRIME 1270610
#define DEBUG 1

int nPrime;
int maxPrimeNum = 100000;
int *prime;
long long *primeSq;

void buildPrimeTable(){
	char isPrime;
	int i;
	long long t;
	prime = (int *) malloc(sizeof(int)*NPRIME);
	primeSq = (long long *) malloc(sizeof(long long)*NPRIME);
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	for(i=0; i<3; i++){
		primeSq[i] = prime[i]*prime[i];
	}
	t = 7;
	while(primeSq[nPrime - 1] < MAX){
		isPrime = 1;
		for(i=1; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
#if DEBUG
			if(nPrime == maxPrimeNum){
				maxPrimeNum <<= 1;
				prime = (int *) realloc(prime, sizeof(int)*maxPrimeNum);
				primeSq = (long long *) realloc(primeSq, sizeof(long long)*maxPrimeNum);
			}
#endif
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t += 4;
		isPrime = 1;
		for(i=1; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
#if DEBUG
			if(nPrime == maxPrimeNum){
				maxPrimeNum <<= 1;
				prime = (int *) realloc(prime, sizeof(int)*maxPrimeNum);
				primeSq = (long long *) realloc(primeSq, sizeof(long long)*maxPrimeNum);
			}
#endif
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t += 2;
	}
}

long long findAns(long long n){
	long long nFactor = 1;
	long long ans;
	long long sroot;
	int i, k;

	sroot = sqrt(n);
	ans = (sroot * sroot == n)? -1 : 0;	
	
	for(i=1; (primeSq[i] <= n) && (i < nPrime); i++){
		if(n % prime[i] == 0){
			if(DEBUG){
				printf("factor:%d\n", prime[i]);
			}
			k = 1;
			do{
				n = n / prime[i];
				k++;
			} while(n % prime[i] == 0);
			nFactor *= k;
		}
	}
	if(n > 1) nFactor <<= 1;
	
	ans += nFactor;
	return ans;
}

int main(){
	long long n, ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;

	buildPrimeTable();
#if DEBUG
	for(n=0; n<100; ++n){
		printf("%d ", prime[n]);
	}
	printf("\n");
	printf("nPrime = %d\n", nPrime);
	printf("last prime=%d, its square=%lld\n", prime[nPrime-1], primeSq[nPrime - 1]);
#endif 	
	/*
	while(1 == fscanf(fp, "%lld", &n)){
		if(n == 0) break;
		if(n == 1) {
			printf("1 1\n");
			continue;
		}
		ans = findAns((n << 2) - 3);
		printf("%lld %lld\n", n, ans);
	}
	*/
	free(prime);
	free(primeSq);
	return 0;
}