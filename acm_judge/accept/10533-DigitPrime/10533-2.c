#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001
#define LEN 500
#define TRUE 1
#define FALSE 0

int nPrime = 3;
char prime[MAX];
char digitPrime[MAX];
int prefixSumForDigitPrime[MAX];

void buildPrime(){
	int i, j;
	memset(prime, 1, MAX);
	prime[0] = 0;
	prime[1] = 0;
	for(i=2; i<MAX; i++){
		if(prime[i]){
			for(j = i << 1; j < MAX; j += i){
				prime[j] = 0;
			}
		}
	}
}


int digitSum(int n){
	int dSum = 0;
	while(n > 0){
		dSum = dSum + (n % 10);
		n = n / 10;
	}
	return dSum;
}

void buildDigitPrime(){
	int i;
	digitPrime[0] = 0;
	digitPrime[1] = 0;
	for(i=0; i<MAX; i++){
		digitPrime[i] = prime[i] & prime[digitSum(i)];
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