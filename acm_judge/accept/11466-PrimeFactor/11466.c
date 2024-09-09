#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
#define VERBOSE 0

long  prime[80000];
int nPrime;

void buildPrimeTable(){
	int t, i;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	t = 7;
	while(t <= MAX){
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t)&& isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0; 
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t)&& isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0; 
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}

int compareLong(const void *a, const void *b){
	return *(long *)a - *(long *)b;
}

int main(){
	int i;
	long input, ans, nFactor;;
	buildPrimeTable();
	/*
	for(i=0; i<100; i++){
		printf("%d ",prime[i]);
	}
	printf("\n %d primes\n",nPrime);
	*/
	while(1 == scanf("%ld", &input)){
		if(0 == input) break;
		
		input = labs(input);
		if(1 == input) {
			printf("-1\n");
			continue;
		}
		if(NULL != bsearch(&input, prime, nPrime, sizeof(long), compareLong)){
			printf("-1\n");
			continue;
		}
		nFactor = 0;
		for(i=0; (i<nPrime) && (prime[i]*prime[i] <= input); i++){
			if(input % prime[i] == 0){
				if(VERBOSE){
					printf("prime factor for input %ld: %ld\n",input, prime[i]);
				}
				nFactor++;
				ans = prime[i];
				do{
					input = input / prime[i];
				} while(input % prime[i] == 0);
			}
		}
		if(input > 1){
			nFactor++;
			ans = input;
		}
		if(nFactor > 1){
			printf("%ld\n", ans);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}