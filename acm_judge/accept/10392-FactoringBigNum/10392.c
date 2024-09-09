#include <stdio.h>
#include <string.h>
#define MAX 1000001
#define LEN 80000

char isPrime[MAX];
int nPrime;
int prime[LEN];
long long primeSq[LEN];

void buildPrimeTable(){
	int i, j;
	memset(isPrime, 1, MAX);
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			for(j=i << 1; j<MAX; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	nPrime = 0;
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			prime[nPrime] = i;
			primeSq[nPrime] = i*i;
			++nPrime;
		}
	}
}

int factoring(long long n){
	int i;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		while(n % prime[i] == 0){
			printf("    %d\n", prime[i]);
			n = n / prime[i];
		}
	}
	if(n > 1){
		printf("    %lld\n", n);
	}
	return 0;
}

int main(){
	long long i;
	buildPrimeTable();
	#if 0
	for(i=0; i<100; i++){
		printf("%d ", prime[i]);
	}
	printf("\n %d prime found\n", nPrime);
	#endif	
	while(1 == scanf("%lld", &i)){
		if(i < 0) break;
		factoring(i);
		puts("");
	}	
	
	return 0;
}
