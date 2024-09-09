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
	
	int i, nDigit;
	int candidate[2];
	
	int nCandidate = 0;
	int nOnes, ret;
	char residule[LEN];	
	
	
	memset(residule, 0, LEN);

	for(i=1; i<LEN; i++){
		ret = calcResidule(i, n);
		if(ret >= LEN){
			continue;
		}
		if(ret == 0){
			candidate[1] = i;
			candidate[0] = 0;
			nCandidate = 2;
			break;
		} 
		if(residule[ret] > 0){
			candidate[1] = i;
			candidate[0] = residule[ret];
			nCandidate = 2;
			break;
		}
		residule[ret] = i;		
	}	
	
	
	
	if(nCandidate == 2){	
		#if 1
		printf("ans[%d]=\"", n);
		for(i = candidate[1] - candidate[0] - 1; i >= 0; i--){
			printf("1");
		} 
		for(i = candidate[0]; i > 0; i--){
			printf("0");
		}
		printf("\";\n");
		#endif	 
	} 
	else {
		#if 0
		int nOnes;
		printf("%d ", n);
		for(nOnes = LEN - 1; nOnes > 0 ; nOnes--){
			if ((residule[nOnes] != 0) && (residule[nOnes-1] != 0) && (residule[nOnes] < residule[nOnes-1])){
				int j;
				for(j=residule[nOnes] - 2; j >= 0; j--){
					printf("1");
				}
				printf("0 ");
				for(j=0; j < residule[nOnes-1]; j++){
					printf("1");
				}
				//printf(" residue=%d", nOnes);
				printf("\n");
				break;	
			} 
		}
		/*printf("--- %d %d\n", candidate[0], candidate[1]);*/
		return ;
		#endif
	}
}

int main(){
	int n;
	for(n=1; n<=200; n++){
		findMultiple(n);
	}
	return 0;
}