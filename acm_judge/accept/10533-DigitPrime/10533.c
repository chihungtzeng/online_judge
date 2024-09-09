#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001
#define LEN 500
#define TRUE 1
#define FALSE 0

int nPrime = 3;
int prime[LEN] = {2, 3, 5};
int primeSq[LEN] = {4, 9, 25};
char digitPrime[MAX];
int prefixSumForDigitPrime[MAX];

void buildPrime(){
	int step = 4, t = 7, i;
	char isPrime, notDone = 1;
	while(notDone){
		isPrime = 1;
		for(i=1; primeSq[i] <= t; i++){
			if(t % prime[i] == 0){
				isPrime = 0;
				break;
			}
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		if(primeSq[nPrime - 1] > MAX){
			notDone = 0;
		}
		t += step;
		step = 6 - step;
	}
}

int isPrime(int n){
	int i;
	if(n <= 1) return FALSE;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		if(n % prime[i] == 0) return FALSE;
	}
	return TRUE;
}

int isDigitPrime(int n){
	int dSum = 0;
	if(isPrime(n) == FALSE) return FALSE;
	while(n > 0){
		dSum = dSum + (n % 10);
		n = n / 10;
	}
	return isPrime(dSum);
}

void buildDigitPrime(){
	int i;
	digitPrime[0] = 0;
	digitPrime[1] = 0;
	for(i=0; i<MAX; i++){
		digitPrime[i] = isDigitPrime(i)? 1 : 0;
	} 
	for(i=1; i<MAX; i++){
		prefixSumForDigitPrime[i] = prefixSumForDigitPrime[i - 1] + digitPrime[i]; 
	}
}

int main(){
	int i;
	int nTest, t1, t2;	
	buildPrime();
	buildDigitPrime();
	#if 0
	for(i=0; i<100; i++){
		printf("%d ", prime[i]);
	}
	printf("\n %d primes found\n",nPrime);
	#endif
	scanf("%d", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", prefixSumForDigitPrime[t2] - prefixSumForDigitPrime[t1 - 1]);
	}
	
	return 0;
}