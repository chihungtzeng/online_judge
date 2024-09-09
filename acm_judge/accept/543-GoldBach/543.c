#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int prime[MAX]={2,3,5};
int nPrime=3;
int primeSquare[MAX]={4,9, 25};

void buildPrimeTable(){
	int t, i, isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (primeSquare[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime++] = t*t;
		}
		t+=4;
		isPrime = 1;
		for(i=2; (primeSquare[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime++] = t*t;
		}
		t+=2;
	}	
}
int compareInt(const void *a,const void *b){
	return *(int *)a - *(int *)b;
}

int primity(int n){
	int i;
	if (n < prime[nPrime - 1]){
		if(bsearch(&n, prime, nPrime, sizeof(int), compareInt) == NULL) {
			return 0;
		} 
		else return 1;
	}
	for(i=0; (i<nPrime) && (primeSquare[i] <= n); i++){
		if(n % prime[i] == 0) return 0;
	}
	return 1;
}

int main(){
	int a, b, n, found, nHalf;
	int i;
	buildPrimeTable();
	while(1 == scanf("%d",&n)){
		if(n == 0) break;
		found = 0;
		for(i= 0; (i<nPrime) && (!found) ; i++){
			a = prime[i];
			b = n - prime[i];
			if( primity(a) && primity(b)){
				found = 1;
			}
		}
		if(!found){
			nHalf = n >> 1;
			for(a = prime[nPrime - 1] + 1; (a <= nHalf)&&(!found); a++){
				b = n - a;
				if( primity(a) && primity(b)){
				found = 1;
				}
			}
		}
		if(!found){
			puts("Goldbach's conjecture is wrong.");
		}
		else{
			printf("%d = %d + %d\n", n, a, b);
		}
	}
	return 0;
}