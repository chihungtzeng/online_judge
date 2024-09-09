#include <stdio.h>
#include <stdlib.h>
#define MAX 93000
#define MAXN 46342

long long *prime;
int nPrime;

void buildPrimeTable(){
	long long t, i;
	char isPrime; 
	nPrime = 3;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t+=4;
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t+=2;
	}
}

long long findAns(long long n){
	long long divisor, tmp;
	int i, nFactor = 0;
	long long ans = 0;	
	
	if(1 == n){
		return 2;
	}
	
	tmp = n;
	for(i=0; (i < nPrime) && (prime[i]*prime[i] <= tmp); i++){
		if(tmp % prime[i] == 0){
			nFactor++;
			divisor = 1;
			do {
				divisor = divisor * prime[i];
				tmp = tmp / prime[i]; 
			} while( tmp % prime[i] == 0);
			ans += divisor;
		}
	}  
	if(tmp > 1){
		nFactor += 1;
	}
	
	if (nFactor <= 1){
		return n + 1;
	}
	if (tmp > 1){
		ans += tmp;
	}
	return ans;
}

int main(){
	unsigned int kTest = 1;
	long long input;
	long long ans;
	prime = (long long *) malloc(sizeof(long long)*10000);
	buildPrimeTable();
	
	while(1 == scanf("%lld",&input)){		
		if(input == 0){
			break;
		}
		ans = findAns(input);
		printf("Case %d: %lld\n",kTest++, ans);
	}
	free(prime);
	return 0;
}