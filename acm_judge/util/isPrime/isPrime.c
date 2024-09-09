#include <stdio.h>
#define COMPOSITE 1
#define PRIME 0

/*
return b^e % m
*/
long long powMod(long long b, long long e, long long m){
	long long result;
	if(e == 1) return b % m;
	result = powMod(b, e >> 1, m);
	result = (result * result) % m;
	if(e & 1){
		result = (result * b) % m;
	}
	return result;
}

int checkPrimalityByWitness(long long n, int w){
	long long j, y, q, tmp, k;
	char done;
	if(n < w) return PRIME;

	q = n - 1;
	k = 0;
	/* 
		n = 1 + 2^k * q 
	*/
	while(!(q & 1)){
		q >>= 1;
		++k; 
	}
	if(n != 1 + (1 << k)*q){
		puts("shit!");
	}	
	
	j = 0;
	y = powMod(w, q, n);
	while(1){
		if((j == 0) && (y == 1)) return PRIME;
		if(y == n - 1) return PRIME;
		if((j > 0) && (y == 1)) return COMPOSITE;
		++j;
		if(j < k){
			y = (y*y) % n;
		} else {
			return COMPOSITE;
		}
	} 
}

/*
return PRIME if n is prime
otherwise if n is composite
*/
int isPrime(long long n){
	int nWitness = 5, i;
	int witness[] = {2, 3, 5, 7, 11};
	for(i=0; i<nWitness; i++){
		if(n == witness[i]) return PRIME;
	}
	for(i=0; i<nWitness; ++i){
		if(checkPrimalityByWitness(n, witness[i]) == COMPOSITE){
			return COMPOSITE;
		} 
	}
	return PRIME;
}

int main(){
	long long b, e, m = 1000;
	int count;
	for(b = 2, count=0; count < 100; b++){
		if(isPrime(b) == PRIME){
			count++;
			printf("%lld ", b);
		}
	} 
	return 0;
}