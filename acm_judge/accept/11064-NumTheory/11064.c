#include <stdio.h>
#define MAX 46342

int prime[10000];
int nPrime;

void findPrime() {
	int i, t, sq, nextSqSquare;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	
	t = 7;
	sq = 2;
	nextSqSquare = (sq + 1)*(sq + 1);
	while(t < MAX){	
		isPrime = 1;
		if (nextSqSquare <= t){
			sq++;
			nextSqSquare = (sq + 1)*(sq+1);
		}
		for(i=2; isPrime && prime[i] <= sq; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		
		t += 4;		
		isPrime = 1;
		if (nextSqSquare <= t){
			sq++;
			nextSqSquare = (sq + 1)*(sq+1);
		}
		for(i=2; isPrime && prime[i] <= sq; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}


int findAns(int n){
	int i, div = 1, k, sum = n, m = n;
	for(i=0; (i < nPrime) && (prime[i]*prime[i] <= n); i++){
		if(n % prime[i] == 0){
			k = 0;
			sum = sum - sum/prime[i];
			while(n % prime[i] == 0){
				n = n / prime[i];
				k++;
			}
			div = div * (k+1);
		}
	}
	if(n > 1) {
		div = div << 1;
		sum = sum - sum/n;
	}
	return m - sum - div + 1;
}


int main() {
	int n;
	findPrime();
	while(1 == scanf("%d",&n)){
		printf("%d\n",findAns(n));
	}
	return 0;
}