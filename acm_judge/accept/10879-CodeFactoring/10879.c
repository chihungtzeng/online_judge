#include <stdio.h>
#include <math.h>
#define MAX 3200

int prime[MAX];
int nPrime;

void buildPrimeTable(){
	int t, i,sq;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	
	t = 7;
	while(t < MAX){
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; (isPrime) && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 4;
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; (isPrime) && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 2;
	}
}

int main(){
	short nTest, k=1, i;
	int A, B, C, D;
	int K;
	char done, first;
	buildPrimeTable();
	/*
	printf("int prim[%d] = {",nPrime);
	for(i=0 ; i<nPrime; i++){
		printf("%d,", prime[i]);
		if(i % 20 == 0){
			printf("\n");
		}
	}
	printf("};\n");
*/
	scanf("%hd", &nTest);
	while(k <= nTest){
		scanf("%d", &K);
		done = 0;
		first = 0;
		for(i=0; (!done) && (i<nPrime); i++){
			if((!first) && (K % prime[i] == 0)){
				A = prime[i];
				B = K / prime[i];
				first = 1;
				if(B % prime[i] == 0){
					C = prime[i] * prime[i];
					D = B / prime[i];
					done = 1;
				}
			}
			else if ((first) && (K % prime[i] == 0)){
				C = prime[i];
				D = K / prime[i];
				done = 1;
			}
			
		}

		printf("Case #%hd: %d = %d * %d = %d * %d\n", k++, K, A, B, C, D);
	}
	
	return 0;
}