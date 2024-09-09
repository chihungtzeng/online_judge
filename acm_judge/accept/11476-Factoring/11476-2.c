/*TLE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000
#define DEBUG 0


int prime[MAX] = {2, 3, 5};
int nPrime = 3;
long long primeSq[MAX] = {4,9, 25};

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a% b);
}

long long Pollard(long long n){
	long long x, xprime, k, ell, g;
	long double lx;
	x = 5;
	xprime = 2;
	k = 1;
	ell = 1;
	
	while(1){
		g = gcd( llabs(xprime - x), n);
		if(g == 1){
			k--;
			if(k == 0){
				xprime = x;
				ell = ell << 1;
				k = ell;
			}
			lx = x*x + 1;
			lx = lx - floorl(lx/n)*n;
			x = (lx + 1e-8);
		}
		else{
			return g;
		}
	}
}


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
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}



int factoring(long long x, long long factor[], int fpow[]){
	int i;
	int nFactor = 0;
	
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
	f1 = Pollard(x);
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
			return nFactor;
		}
		
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
