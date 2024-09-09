#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UB 2000001
#define MAX 1420

struct record{
	int value;
	unsigned short nFactor;
};

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

int compareRecord(const void *a, const void *b){
	struct record *x, *y;
	x = (struct record *)a;
	y = (struct record *)b;
	if(x->nFactor < y->nFactor) return -1;
	else if (x->nFactor > y->nFactor) return 1;
	else if (x->value < y->value) return -1;
	else if (x->value > y->value) return 1;
	else return 0;
}

int main(){
	buildPrimeTable();
	struct record *R;
	int i, j, k=1, sq, factor;
	char isPrime;
	
	R = (struct record *) malloc(sizeof(struct record)*UB);
	R[1].value = 1;
	R[1].nFactor = 1;

	for(i=2; i<UB; i++){
		R[i].value = i;
		sq = sqrt(i);
		isPrime = 1;
		for(j=0; (isPrime) && (j<nPrime) && (prime[j] <= sq); j++){
			if(i % prime[j] == 0){
				isPrime = 0;
				factor = prime[j];
			}
		}
		if(isPrime){
			R[i].nFactor = 1;
		}
		else if (factor != 0){
			R[i].nFactor = 1 + R[i / factor].nFactor;
		}		
		else {
			printf("wrong factor %d\n",factor);
		}
	}
	qsort(R+1, UB - 1, sizeof(struct record), compareRecord);
	
	
	while(1){
		int query;
		scanf("%d", &query);
		if(query == 0){
			break;
		}
		printf("Case %d: %d\n",k++, R[query].value);
	}
	free(R);
	/*printf("%d primes found\n",nPrime);*/
	return 0;
}