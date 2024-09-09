#include <stdio.h>
#define MAX 1000

int prime[200];
int nPrime;

void buildPrimeTable(){
	int i, t;
	char isPrime;
	nPrime = 3;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if (t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if (t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}

int main(){
	int i, n, nFactor, tmp;
	buildPrimeTable();
	/*
	for(i=0; i<100; i++){
		printf("%d ",prime[i]);
	}
	printf("\n%d primes\n", nPrime);
	*/
	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		
		nFactor = 0;
		tmp = n;
		for(i=0; (i < nPrime) && (prime[i]*prime[i] <= tmp); i++){
			if(tmp % prime[i] == 0){
				nFactor++;
				do {
					tmp = tmp / prime[i];
				} while(tmp % prime[i] == 0);
			}
		}
		if(tmp > 1){
			nFactor++;
		}
		printf("%d : %d\n",n, nFactor);
	}
	return 0;
}