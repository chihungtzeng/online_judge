#include <stdio.h>
#define MAX 100

short prime[MAX]={2,3,5};
short nPrime = 3;

void buildPrimeTable(){
	short t, i;
	char isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; prime[i]*prime[i] <= t; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] =t;
		}
		t += 4;
		isPrime = 1;
		for(i=2; prime[i]*prime[i] <= t; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] =t;
		}
		t += 2;
	}
}

short findPow(short n, short fpow[]){
	short i, nPow=0;
	short tmp;
	char done = 0;
	
	for(nPow=0; (nPow < nPrime) && (!done); nPow++){
		if(prime[nPow] > n){
			done = 1;
			continue;
		}
		fpow[nPow] = 0;
		tmp = prime[nPow];
		while(tmp <= n){
			fpow[nPow] += n / tmp;
			tmp = tmp * prime[nPow];
		}
	}
	return nPow - 1;
}

int main(){
	short i;
	short fpow[MAX];
	short nPow;
	short n;
	
	buildPrimeTable();
	while(1 == scanf("%hd",&n)){
		if(n == 0) return 0;
		nPow = findPow(n, fpow);
		printf("%3hd! =", n);
		
		
		for(i=0; i<nPow; i++){
			printf(" %2hd", fpow[i]);
			
			if((i == 14) && (i != nPow - 1)){
				printf("\n      ");
			}
		}
		printf("\n");
		
	}
	
	return 0;
} 