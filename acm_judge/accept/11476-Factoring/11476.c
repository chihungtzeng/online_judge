#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
#define DEBUG 0


int *prime ;
int nPrime = 3;
long long *primeSq;

void buildPrimeTable(){
	int t, i;
	char isPrime;
	int s = 78500;
	prime = malloc(sizeof(int)*s);
	primeSq = malloc(sizeof(long long)*s);
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	primeSq[0] = 4;
	primeSq[1] = 9;
	primeSq[2] = 25;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}


int factoring(long long x, long long factor[], int fpow[]){
	int i;
	int nFactor = 0;
	char done = 0;
	
	for(i=0; (i<nPrime) && (primeSq[i] <= x); i++){
		if(x % prime[i] == 0){
			factor[nFactor] = prime[i];
			fpow[nFactor] = 0;
			do{
				fpow[nFactor]++;
				x = x / prime[i];
			} while(x % prime[i] == 0);
			nFactor++;
		}
		
	}	
	
	if((x > 1) ){
			factor[nFactor] = x;
			fpow[nFactor] = 1;
			nFactor++;
	}
	return nFactor;
}



int main(){
	int i, nTest;
	long long input;
	FILE *fp;
	long long factor[4000];
	int fpow[4000], nFactor;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;	
	
	buildPrimeTable();
	if(DEBUG){
		for(i=0; i<100; i++){
			printf("%d ",prime[i]);
		}
		printf("\n %d primes last one:%d\n",nPrime, prime[nPrime-1]);
	}
	
	fscanf(fp, "%d", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%lld", &input);
		nFactor = factoring(input, factor, fpow);
		printf("%lld =", input);
		if(fpow[0] == 1){
			printf(" %lld", factor[0]);
		}
		else{
			printf(" %lld^%d", factor[0], fpow[0]);
		}
		
		for(i=1; i<nFactor; i++){
			if(fpow[i] == 1){
				printf(" * %lld", factor[i]);
			}
			else{
				printf(" * %lld^%d", factor[i], fpow[i]);
			}
		}
		printf("\n");
	}
	free(prime);
	free(primeSq);
	return 0;
}