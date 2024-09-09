#include <stdio.h>
#define BOUND 46340
#define LEN 4800

int nPrime = 3;
int prime[LEN] = {2, 3, 5};
int primeSq[LEN] = {4, 9, 25};

void buildPrimeTable(){
	int t = 7, i, step = 4;
	char isPrime;
	while(t < BOUND){
		isPrime = 1;
		for(i=1; primeSq[i] <= t; i++){
			if(t % prime[i] == 0) {
				isPrime = 0;
				break;
			}
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime += 1;
		}
		t += step;
		step = 6 - step;
	}
}

int factoring(int n, int factor[], int pow[]){
	int nFac = 0;
	int i;
	for(i=0; (i < nPrime) && (primeSq[i] <= n); i++){
		if(n % prime[i] == 0){
			factor[nFac] = prime[i];
			pow[nFac] = 0;
			do{	
				pow[nFac] += 1;
				n = n / prime[i];
			} while(n % prime[i] == 0);
			nFac += 1;
		}
	}
	if(n > 1){
		factor[nFac] = n;
		pow[nFac] = 1;
		nFac += 1;
	}
	return nFac;
}

int facFactoring(int n, int factor[], int pow[]){
	int i, d;
	for(i=0; (i < nPrime) && (prime[i] <= n); i++){
		d = prime[i];
		pow[i] = 0;
		factor[i] = prime[i];
		while(d <= n){
			pow[i] += n / d;
			d = d * prime[i];
		}
	}
	return i;
}

long long solve(int n, int D){
	int factorN[26], powN[26]; /*25th prime is 97*/
	int factorD[LEN], powD[LEN];
	int iN, iD;
	long long result = 1;
	short nFactorD, nFactorN;	
	nFactorD = factoring(D, factorD, powD);
	if(factorD[nFactorD - 1] > n){
		return 0;
	}
	#if 0
		int i;
		printf("D is %d\n", D);
		for(i=0; i<nFactorD; i++){
			printf("%d^%d\n", factorD[i], powD[i]);
		}
	#endif
	nFactorN = facFactoring(n, factorN, powN);
	for(iN = nFactorN - 1, iD = nFactorD - 1; iN >= 0; iN--){
		if(factorN[iN] == factorD[iD]){
			if(powN[iN] < powD[iD]) return 0;
			result *= (powN[iN] - powD[iD] + 1);
			iD -= 1;
		}
		else {
			result *= (powN[iN] + 1);
		}
	} 
	return result;
}

int main(){
	int n, D;
	long long ans;
	buildPrimeTable();
	#if 0
	for(n=0; n<100; n++){
		printf("%d ", prime[n]);
	}
	printf("\n nPrime=%d last prime=%d, %d\n", nPrime, prime[nPrime - 1], primeSq[nPrime -1]);
	#endif
	
	while(2 == scanf("%d %d", &n, &D)){
		if((n == 0) && (D == 0)) return 0;
		if(D < 0) D = -D;
		ans = solve(n, D);
		printf("%lld\n", ans);
	}
	
	return 0;
}
