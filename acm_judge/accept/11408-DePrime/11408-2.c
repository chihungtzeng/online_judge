#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000001
#define SQMAX 2237



int *primeSum;
int *nDeprime;

void buildPrimeTable(){
	int t, i, bound;
	char isPrime;
	
	memset(primeSum, 0, sizeof(int)*MAX);
	
	primeSum[2] = 2;
	bound = MAX/ 2;
	for(i=bound; i>=2; i--){
		primeSum[i*2] += 2;
	}
	for(t=3; t<MAX; t++){
		if(primeSum[t] != 0){
			/*not prime*/
			continue;
		}
		primeSum[t] = t;
		bound = MAX / t;
		for(i=bound; i>=2; i--){
			primeSum[i*t] += t;
		}
	}
	
	nDeprime[1] = 0;
	nDeprime[2] = 1;	
	for(i=3; i<MAX; i++){
		if(primeSum[primeSum[i]] == primeSum[i]){
			nDeprime[i] = nDeprime[i-1] + 1;
		}
		else{
			nDeprime[i] = nDeprime[i-1];
		}
	}
}



int main(){
	int i, a, b;
	primeSum = (int *) malloc(sizeof(int)*MAX);
	nDeprime = (int *) malloc(sizeof(int)*MAX);
	buildPrimeTable();

	while(1 == scanf("%d",&a)){
		if(0 == a){
			break;
		}
		scanf("%d",&b);
		printf("%d\n", nDeprime[b] - nDeprime[a - 1]);
		
	}
	
	free(primeSum);
	free(nDeprime);	
	return 0;
}
