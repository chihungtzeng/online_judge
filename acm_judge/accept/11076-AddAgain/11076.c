#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 13

long long fac[MAX];
long long coef[MAX];
char nDigit[10];

void buildTable(){
	int i;
	fac[0] = 1;
	for(i=1; i<MAX; i++){
		fac[i] = fac[i-1] * i;
	}
	coef[0] = 0;
	coef[1] = 1;
	for(i=2; i<MAX; i++){
		coef[i] = coef[i-1]*10 + 1;
	}
}

long long possibleCombination(char totalDigit, char nDigit[]){
	char i;
	long long ans = fac[totalDigit];
	for(i=0; i<10; i++){
		ans = ans / fac[nDigit[i]];
	}
	return ans;
}

long long findAns(char totalDigit, char nDigit[]){
	char i, j, tmp;
	long long nCombination, ans = 0;
	for(i=0; i<10; i++){
		if(nDigit[i] > 0){
			nDigit[i] -= 1;
			nCombination = possibleCombination(totalDigit - 1, nDigit);
			ans += nCombination * i * coef[totalDigit];
			nDigit[i] += 1;
		}
	}
	return ans;
}

int main(){
	char i, totalDigit, ch;
	buildTable();
	while(1 == scanf("%hhd", &totalDigit)){
		if(totalDigit == 0) return 0;
		for(i=0; i<10; i++){
			nDigit[i] = 0;
		}
		for(i=0; i<totalDigit; i++){
			scanf("%hhd", &ch);
			nDigit[ch] += 1;
		}
		#if 0
		for(i=0; i<10; i++){
			printf("%hhd ", nDigit[i]);
		}
		printf("\n");
		#endif
		printf("%lld\n", findAns(totalDigit, nDigit));
	}
	
	
	return 0;
}