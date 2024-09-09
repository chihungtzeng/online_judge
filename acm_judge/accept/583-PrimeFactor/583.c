#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 46341

int prime[MAX];
int nPrime;

void buildPrimeTable(){
	int t, i,sq;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	
	t = 7;
	while(t < MAX){
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; (isPrime) && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 4;
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; (isPrime) && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 2;
	}
}

int compareInt(const void *a, const void *b){
	int x, y;
	x = *(int *)a;
	y = *(int *)b;
	if (x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int main(){
	int input, absi;
	buildPrimeTable();
	
	int factor[MAX], nFactor, sq, i;
	
	/*
	for(i=0; i<100; i++){
		printf("%d ", prime[i]);
	}
	printf("\n");
	printf("nPrime=%d\n", nPrime);
	*/
	
	while(1 == scanf("%d", &input)){
		if(0 == input) {
			break;
		}
		
		absi = abs(input);
		nFactor = 0;
		sq = sqrt(absi);
		/*
		i = 0;
		while((i < nPrime) && (absi > 1)){
			while(absi % prime[i] == 0){
				factor[nFactor++] = prime[i];
				absi = absi/prime[i];
			}
			i++;
		}
		*/
		for(i=0; (prime[i] <= sq) && (i<nPrime); i++){
			if(absi % prime[i] == 0){
				factor[nFactor++] = prime[i];
				absi = absi / prime[i];
				sq = sqrt(absi);
				i--;
			}
		}
		if((absi > 1) && (nFactor > 0)){
			factor[nFactor++] = absi;
		}
		if(nFactor == 0){
			nFactor = 1;
			factor[0] = absi;
		}
		if(input < 0){
			factor[nFactor++] = -1;
		}
		qsort(factor, nFactor, sizeof(int), compareInt);
		printf("%d = %d", input, factor[0]);
		for(i=1; i<nFactor; i++){
			printf(" x %d", factor[i]);
		}
		printf("\n");
	}
	
	return 0;
}

