#include <stdio.h>
#define MAX 80000

int prime[MAX] = {2, 3, 5};
int nPrime = 3;
long primeSq[MAX] = {4, 9, 25};

void buildPrimeTable(){
	int t = 7, i, offset=4;
	char isPrime;
	
	while(t < 1000000){
		isPrime = 1;
		for(i=2; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = (long)t*t;
			nPrime++;
		}
		t += offset;
		offset = 6 - offset;
	}
}

int factoring(int input, char fpow[]){
	int i, p;
	long t;
	for(i=0; (i < nPrime) && (prime[i] <= input); i++){
		fpow[i] = 1;
		t = prime[i];
		while(t <= input){
			t = t * prime[i];
			fpow[i]++;
		}
		fpow[i]--;
		/*printf("prime factor:%d, power:%hhd\n", prime[i], fpow[i]);*/
	} 
	return i;
}

int main(){
	int i, j, input, nFpow, ans;
	char fpow[MAX];
	buildPrimeTable();
	/*
	for(i=0; i<100; i++){
		printf("%d ",prime[i]);
	}
	printf("\n %d primes found primeSq[nPrime-1]=%ld\n",nPrime, primeSq[nPrime-1]);
	*/
	while(1 == scanf("%d", &input)){
		if(input == 0) return 0;
		nFpow = factoring(input, fpow);
		if(fpow[2] > fpow[0]) {
			puts("5");
		}
		else{
			ans = 1;
			fpow[0] = fpow[0] - fpow[2];
			fpow[2] = 0;
			for(i=0; i<nFpow; i++){
				for(j=0; j<fpow[i]; j++){
					ans = (ans * prime[i]) % 10;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}