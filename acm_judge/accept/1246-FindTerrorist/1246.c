#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

buildPrimeTable(char *candidate){
	int i, j, k, tmp;
	char *cprime;
	char *nFactor;
	cprime = (char *) malloc(sizeof(char)*MAX);
	nFactor = (char *) malloc(sizeof(char)*MAX);
	memset(cprime, 1, MAX);
	memset(nFactor, 1, MAX);

	/*find prime number*/
	cprime[0] = 0;
	cprime[1] = 0;
	for(i=2; i<MAX; i++){
		if(cprime[i]){
			nFactor[i] = 2;
			for(j = i << 1; j<MAX; j+=i){
				cprime[j] = 0;
				k = 1;
				tmp = j;
				do{
					tmp = tmp / i;
					k++;
				} while(tmp % i == 0);
				nFactor[j] = nFactor[j] * k;
			}
		}
	}
	
	for(i=0; i<MAX; i++){
		candidate[i] = ((nFactor[i] >= 2) && (cprime[nFactor[i]] == 1))? 1 : 0;
	}
	#if 0
	for(i=0; i<10; i++){
		printf("nFactor[%d] = %hhd\n", i, nFactor[i]);
	}
	for(i=0, j=0; i<100; i++){
		if(candidate[i]){
			printf("nFactor[%d] = %hhd, <- candidate\n", i, nFactor[i]);
			j++;
		}
	}
	printf("total %d candidates\n", j);
	#endif
	free(cprime);
	free(nFactor);
}

int findCandidate(short *output, char *candidate, int low, int high){
	int nOutput = 0;
	
	if(low < -1){
		output[nOutput++] = -1;
	}
	
	while(low <= high){
		if(candidate[low]){
			output[nOutput++] = low;
		}
		low++;
	}
	return nOutput;
}

int main(){
	char *candidate;
	short *output; 
	int nOutput;
	int nTest, low, high, i;

	candidate = (char *) malloc(sizeof(char)*MAX);
	output = (short *) malloc(sizeof(shot)*MAX);	
		
	buildPrimeTable(candidate);
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d", &low, &high);
		if(low > high){
			i = low;
			low = high;
			high = i;
		}
		
		nOutput = findCandidate(output, candidate, low, high);
		if(nOutput == 0){
			printf("-1\n");
		} else {
			printf("%hd", output[0]);
			for(i=1; i<nOutput; i++){
				printf(" %hd", output[i]);
			}
			printf("\n");
		}
	}
	free(candidate);
	free(output);
	return 0;
}
