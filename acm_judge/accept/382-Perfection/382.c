#include <stdio.h>
#include <math.h>
#define PERFECT 1
#define ABUNDANT 2
#define DEFICIENT 3
#define MAX 245

int prime[MAX] = {2, 3, 5};
int nPrime = 3;
int primeSquare[MAX] = {4, 9, 25};

void buildPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (primeSquare[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; (primeSquare[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}

int decideType(int n){
	int factorSum = 1, fac;
	int tmp = n;
	int k, i;
	for(i=0; (i < nPrime) && (primeSquare[i] <= tmp); i++){
		if(tmp % prime[i] == 0){
			k = prime[i];
			fac = 1;
			do{
				fac += k;
				tmp = tmp/prime[i];
				k = k*prime[i];
			} while(tmp % prime[i] == 0);
			
			factorSum = factorSum * fac;
			/*
			if(factorSum - n > n){
				return ABUNDANT;
			}
			*/
		}
	}
	if(tmp > 1){
		factorSum = factorSum*(1 + tmp);
	}
	
	factorSum = factorSum - n;
	/*printf("factorsum(%d) = %d\n", n, factorSum);*/
	if(n == factorSum) return PERFECT;
	else if (n < factorSum) return ABUNDANT;
	else return DEFICIENT;
	
}

int main(){
	int n, result;
	buildPrimeTable();
	
	puts("PERFECTION OUTPUT");
	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		result = decideType(n);
		switch (result){
			case PERFECT:
				printf("%5d  PERFECT\n", n);
				break;
			case ABUNDANT:
				printf("%5d  ABUNDANT\n", n);
				break;
			case DEFICIENT:
				printf("%5d  DEFICIENT\n", n);
				break;
		}
	}
	puts("END OF OUTPUT");
	return 0;	
}