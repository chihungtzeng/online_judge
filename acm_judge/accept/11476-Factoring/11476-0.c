#include <stdio.h>
#define MAX 100000000
#define DEBUG 0


int prime[MAX] = {2, 3, 5};
int nPrime = 3;
long long primeSq[MAX] = {4,9, 25};


void buildPrimeTable(){
	int t, i;
	char isPrime;
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
	if(x > 1){
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
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	
	buildPrimeTable();
	
	for(i=0; i<100; i++){
		printf("%d ",prime[i]);
	}
	printf("\n %d primes last one:%d\n",nPrime, prime[nPrime-1]);
	
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
	return 0;
}