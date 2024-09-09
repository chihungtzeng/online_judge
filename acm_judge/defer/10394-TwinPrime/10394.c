#include <stdio.h>
#include <stdlib.h>
#define MAX 18409201
#define LEN 100001
#define NPRIME 100000

struct Point{
	int x, y;
};

int nPrime, nPrimeMax;
int *prime;
int *primeSq;

void buildPrimeTable(){
	int t, i;
	char isPrime, step;
	
	nPrimeMax = LEN;
	prime = (int *) malloc(sizeof(int)*nPrimeMax);
	primeSq = (int *) malloc(sizeof(int)*nPrimeMax);
	nPrime = 3;
	prime[0] = 2; 
	prime[1] = 3;
	prime[2] = 5;
	for(t=0; t<3; t++){
		primeSq[t] = prime[t]*prime[t];
	}

	t = 7;
	step = 4;
	while(t < MAX){
		isPrime = 1;
		for(i=0; (i<nPrime) && isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			if(nPrime == nPrimeMax){
				nPrimeMax <<= 1;
				prime = (int *) realloc(prime, sizeof(int)*nPrimeMax);
				primeSq = (int *) realloc(primeSq, sizeof(int)*nPrimeMax);
			}
			prime[nPrime] = t;
			primeSq[nPrime] = t * t;
			nPrime += 1;
		}
		t += step;
		step = 6 - step;
	}	
	
}

int main(){
	int i;
	buildPrimeTable();
	#if 1
		for(i=0; i<100; i++){
			printf("%d ", prime[i]);
		}
		printf("\n #prime=%d\n",nPrime);
	#endif
	return 0;
}