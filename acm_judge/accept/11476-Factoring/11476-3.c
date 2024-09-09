#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000
#define DEBUG 1

struct BigInteger{
	int ele[8];
	short nEle;
};

int prime[MAX] = {2, 3, 5};
int nPrime = 3;
long long bigPrime[1600];
int nBigPrime = 0;
long long primeSq[MAX] = {4,9, 25};

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a% b);
}

long long nextValue(long long x, long long n){
	long long result;
	
	result = x*x;
	if(result < 0) result = -result;
	result = (result + 3) % n;
	return result;

}




long long Pollard(long long n){
	long long x, y, g;
	
	x = 2;
	y = 2;
	
	do{
		x = nextValue(x, n);
		y = nextValue(y, n);
		y = nextValue(y, n);
		g = gcd( llabs(x - y), n);
	}while(g == 1);
	return g;
}
/*
long long Brent(long long n){
	long long y, c, m, g = 1, r = 1, q = 1;
	long long x;
	if(DEBUG){
		printf("calling Brent for %lld\n",n);
	}
	srand(time(NULL));
	x = rand() % (n - 1) + 1;
	c = rand() % (n - 1) + 1;
	
	y = x;
	while((g == 1) && (g != n)){
		x = nextX(x, n, c);
		y = nextX(y, n, c);
		y = nextX(y, n, c);
		g = gcd(llabs(x - y), n);
	}
	return g;
}
*/
void buildPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = (long long) t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = (long long)t * t;
			nPrime++;
		}
		t += 2;
	}
}



int factoring(long long x, long long factor[], int fpow[]){
	int i;
	int nFactor = 0;
	char found = 0;
	for(i=0; (i<nPrime) && (primeSq[i] <= x); i++){
		if(x % prime[i] == 0){
			factor[nFactor] = prime[i];
			fpow[nFactor] = 0;
			do{
				fpow[nFactor]++;
				x = x / prime[i];
			} while(x % prime[i] == 0);
			nFactor++;
		}
		
	}	
	if(x == 1) return nFactor;

	if(x <= primeSq[nPrime - 1]){
		fpow[nFactor] = 1;
		factor[nFactor] = x;
		nFactor++;
		return nFactor;
	}
	/*begin Polard rho function*/
	long long f1, f2;
	
	for(i=0; (i<nBigPrime) && (!found); i++){
		if(x % bigPrime[i] == 0){
			found = 1;
			f1 = bigPrime[i];
		}
	}
	
	f1 = (found)? f1 : Pollard(x);
	
	
	
	if(f1 == x){
		factor[nFactor] = f1;
		fpow[nFactor++] = 1;
		return nFactor;
	}
	else{
		f2 = x / f1;
		if(f1 == f2){
			factor[nFactor] = f1;
			fpow[nFactor++] = 2;
			bigPrime[nBigPrime++] = f1;
			return nFactor;
		}
		bigPrime[nBigPrime++] = f1;
		bigPrime[nBigPrime++] = f2;
		if(f1 > f2){
			f1 = f1 ^f2;
			f2 = f1 ^f2;
			f1 = f1 ^f2;
		}
		/*Now f1 < f2*/
		factor[nFactor] = f1;
		fpow[nFactor++] = 1;
		factor[nFactor] = f2;
		fpow[nFactor++] = 1;
		return nFactor;
	}

	
	
	return nFactor;
}



int main(){
	int i, nTest;
	long long input;
	FILE *fp;
	long long factor[128];
	int fpow[4000], nFactor;

	
	fp = (DEBUG)? fopen("in5.txt","r") : stdin;	
	
	buildPrimeTable();
	
	if(DEBUG){
		for(i=0; i<100; i++){
			printf("%d ",prime[i]);
		}
		printf("\n %d primes last one:%d\n",nPrime, prime[nPrime-1]);
		puts("last prime and prime squares");
		for(i=nPrime - 1; i>= nPrime - 5; i--){
			printf("i=%d prime[i]=%d primeSq[i]=%lld\n",i,prime[i],primeSq[i]);
		}
		printf("prime[167]=%d prime[168]=%d\n",prime[167],prime[168]);
	}
	
	fscanf(fp, "%d", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%lld", &input);
		nFactor = factoring(input, factor, fpow);
		printf("%lld =", input);
		if(fpow[0] == 1){
			printf(" %lld", factor[0]);
		}
		else{
			printf(" %lld^%d", factor[0], fpow[0]);
		}
		
		for(i=1; i<nFactor; i++){
			if(fpow[i] == 1){
				printf(" * %lld", factor[i]);
			}
			else{
				printf(" * %lld^%d", factor[i], fpow[i]);
			}
		}
		printf("\n");
	}
	return 0;
}