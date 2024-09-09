#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000001

int main(){
	int nTest;
	int i;
	double *nDigit;
	nDigit = (double *) malloc(sizeof(double)*MAX);
	nDigit[1] = 0;
	for(i=2; i<MAX; i++){
		nDigit[i] = nDigit[i-1] + log10(i);
	}
	#if 0
	for(i=1; i<=20; i++){
		printf("%2d! = %lf\n", i, nDigit[i]);
	}
	for(i=MAX-10; i<MAX; i++){
		printf("%d! = %lf\n", i, nDigit[i]);
	}
	#endif
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &i);
		printf("%d\n", ((int)nDigit[i]) + 1);
	}
	free(nDigit);	
	return 0;
}