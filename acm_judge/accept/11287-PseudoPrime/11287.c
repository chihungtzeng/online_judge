#include <stdio.h>
#include <stdlib.h>
#define MAX 3500


long long prime[MAX];
long long primeSq[MAX];
int nPrime = 0;

void buildPrimeTable(){
	char isPrime;
	long long t, i;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	for(i=0; i<3; i++) primeSq[i] = prime[i]*prime[i];
	
	t = 7;
	while(t < 31700){
		isPrime = 1;
		for(i=0; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t += 4;
		isPrime = 1;
		for(i=0; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t += 2;
	}	
}

long long powmod(long long a, long long p, long long m){
	long long x;
	if(p == 0) return 1;
	if(p == 1) return a % m;
	
	x = powmod(a, p >> 1, m);
	
	x = (x * x) % m;
	if(p % 2 == 1) x = (x*a) % m;
	
	/*printf("%lld^%lld mod %lld = %lld\n", a, p, p, x);*/
	return x;
}
int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int ifPrime(long long n){
	int i;
	
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		if(n % prime[i] == 0) return 0;
	}
	return 1;
}

int main(){
	long long r;
	long long a, p, m;
	buildPrimeTable();
	/*
	for(r=0; r<100; r++){
		printf("%d ", prime[r]);
	}
	printf("\nnPrime=%d, last prime=%d\n", nPrime, prime[nPrime-1]);
	*/
	
	
	
	while(2 == scanf("%lld %lld", &p, &a)){
		if((0 == a) && (0 == p)) return 0;
		
		
		r = powmod(a, p, p);
		
		
		if(a == r){
			if(ifPrime(p)){
				puts("no");			
			}
			else{
				puts("yes");
			}
		}
		else{
			puts("no");
		}
	}
	
	return 0;
}