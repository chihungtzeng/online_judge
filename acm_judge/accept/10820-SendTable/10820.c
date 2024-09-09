#include <stdio.h>
#include <math.h>
#define MAX 50001
#define DEBUG 0

int ans[MAX];
int prime[5200];
int nPrime;

void buildPrime(){
	int sq, t, i, nextSquare;
	char isPrime;
	
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;

	t = 7;	
	sq = 2;
	nextSquare = 9;
	while(t < MAX){
		isPrime = 1;
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			
			prime[nPrime++] = t;
		}
		
		t+=4;
		if(nextSquare <= t){
			sq++;
			nextSquare = (sq + 1)*(sq + 1);
		}
		
		isPrime = 1;
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 2;
		if(nextSquare <= t){
			sq++;
			nextSquare = (sq + 1)*(sq + 1);
		}
	}
}

int totient(int n){
	int ans = n, sq, k, i;
	sq = sqrt(n);
	for(i=0; (i<nPrime) && (prime[i] <= sq); i++){
		if(n % prime[i] == 0){
			ans = (ans/prime[i])*(prime[i] -1);
			do{
				n = n / prime[i];
			} while(n % prime[i] == 0);
			sq = sqrt(n);
		}
	}
	if(n > 1){
		ans = (ans/n)*(n-1);
	}
	return ans;
}


int main(){
	int i, n, *isPrime;
	
	buildPrime();
	ans[1] = 1;
	

	for(i=2 ; i<MAX; i++){
		ans[i] = totient(i);
		ans[i] += ans[i-1];
	}
	

	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		printf("%d\n",ans[n]*2 - 1);
	}

	return 0;
}