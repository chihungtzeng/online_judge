#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001
#define MAX_SQ 317
#define DEBUG 0

int nPower(int n, int k){
	/*find the max p such that n is multiple of k^p */
	int p=0, base = k;
	while(n % base == 0){
		p++;
		base *= k;
	}
	return p;
}

int powerSum(int b, int p){
	/*return 1 + b + b^2 + ... + b^p*/
	int result = 1;
	int tmp;
	int i;
	for(i=1, tmp=b; i<=p; i++){
		result += tmp;
		tmp = tmp * b;
	}
	return result;
}

int mypow(int b, int k){
	int result = 1;
	while(k--){
		result = result * b;
	}
	return result;
}

void buildTable(int *nDivisor, int *sumDivisor){
	char *bPrime;
	int i, j;
	int nPow;
	int sSum;
	int *remain;
	bPrime = (char *) malloc(MAX);
	remain = (int *) malloc(sizeof(int)*MAX);
	
	for(i=0; i<MAX; i++){
		bPrime[i] = 1;
		nDivisor[i] = 1;
		sumDivisor[i] = 1;
		remain[i] = i;
	}
	nDivisor[1] = 1;
	
	bPrime[0] = 0;
	bPrime[1] = 0;
	for(i=2; i<MAX_SQ; i++){
		if(bPrime[i]){
			sumDivisor[i] += i;
			nDivisor[i]++;
			for(j=i<< 1; j<MAX; j += i){
				bPrime[j] = 0;
				nPow = nPower(j, i);
				sSum = powerSum(i, nPow);
				
				remain[j] = remain[j] / mypow(i, nPow);				
				nDivisor[j] *= (nPow + 1);
				sumDivisor[j] *= sSum;
			}
		} 
	}
	for(i=MAX_SQ; i<MAX; i++){
		if(bPrime[i]){
			sumDivisor[i] += i;
			nDivisor[i]++;
		} else {
			if(remain[i] > 1){
				sumDivisor[i] *= ( 1 + remain[i]);
				nDivisor[i] <<= 1;
			}
		}
	}
	#if 0
	for(i=0, j=0; (j<100) && (i<MAX); i++){
		if(bPrime[i]){
			printf("%d ",i);
			j++;
		}
	}
	printf("\n");
	for(i=1; i<=17; i++){
		printf("%d: nDivisor = %d, sumDivisor = %d\n", i, nDivisor[i], sumDivisor[i]);
	}
	for(i=MAX-1; i>=MAX-20; i--){
		printf("%d: nDivisor = %d, sumDivisor = %d\n", i, nDivisor[i], sumDivisor[i]);
	}
	#endif
	free(bPrime);
	free(remain);
}

long long calcAns(int *iArray, int a, int b, int k){
	int i, start;
	long long result = 0;
	start = a / k;
	i = (start * k == a)? start : start + 1;
	i = i * k;
	while(i <= b){
		result += iArray[i];
		i+=k;
	}
	return result;
}


int main(){
	int *nDivisor;
	int *sumDivisor;
	int i, a, b, k, kase;
	long long gAns, hAns;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") :stdin;
	nDivisor = (int *) malloc(sizeof(int)*MAX);
	sumDivisor = (int *) malloc(sizeof(int)*MAX);
	buildTable(nDivisor, sumDivisor);
	fscanf(fp, "%d", &kase);
	while(kase--){
		fscanf(fp, "%d %d %d", &a, &b, &k);
		gAns = calcAns(nDivisor, a, b, k);
		hAns = calcAns(sumDivisor, a, b, k);
		printf("%lld %lld\n", gAns, hAns);
	}
	
	free(nDivisor);
	free(sumDivisor);
	return 0;
}