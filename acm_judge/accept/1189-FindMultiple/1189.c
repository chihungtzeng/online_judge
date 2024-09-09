#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101


int calcResidule(int nDigit, int mod){
	/*return 1{nDigit} % mod*/
	int i;
	int r = 0;
	for(i=0; i<nDigit; i++){
		r = ((r << 3) + (r << 1) + 1) % mod;
	}
	return r;
}

void findMultiple(int n){
	int residule;
	int i, nDigit;
	int candidate[2];
	int done = 0;
	int nCandidate = 0;	
	
	
	
	for(residule=0; (residule <= 200) && (nCandidate != 2); residule++){
		for(nDigit=1; (nDigit <= 100) && (nCandidate != 2); nDigit++){
			if(calcResidule(nDigit, n) == residule){
				candidate[nCandidate++] = nDigit;
			}
		}
		if(nCandidate != 2){
			nCandidate = 0;
		}
	}
	printf("%d ", n);
	if(nCandidate == 2){
		for(i = candidate[1] - candidate[0] - 1; i >= 0; i--){
			printf("1");
		} 
		for(i = candidate[0]; i >= 0; i--){
			printf("0");
		}
		printf("\n");
		/*printf(" nDigit = %d\n", candidate[1]);*/
	} else {
		printf("0\n");
	}
}

int main(){
	int n;
	for(n=1; n<=200; n++){
		findMultiple(n);
	}
	return 0;
}