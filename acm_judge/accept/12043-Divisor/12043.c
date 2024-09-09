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

long long powerSum(int b, int p){
	/*return 1 + b + b^2 + ... + b^p*/
	long long result = 1;
	long long tmp;
	int i;
	for(i=1, tmp=b; i<=p; i++){
		result += tmp;
		tmp = tmp * b;
	}
	return result;
}


void buildTable(long long *nDivisor, long long *sumDivisor){
	char *bPrime;
	int i, j;
	int nPow;
	long long sSum;
	bPrime = (char *) malloc(MAX);
	
	for(i=0; i<MAX; i++){
		bPrime[i] = 1;
		nDivisor[i] = 1;
		sumDivisor[i] = 1;
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
				nDivisor[j] *= (nPow + 1);
				sumDivisor[j] *= sSum;
			}
		} 
	}
	for(i=MAX_SQ; i<MAX; i++){
		if(bPrime[i]){
			sumDivisor[i] += i;
			nDivisor[i]++;
		}
	}
	#if 1
	for(i=0, j=0; (j<100) && (i<MAX); i++){
		if(bPrime[i]){
			printf("%d ",i);
			j++;
		}
	}
	printf("\n");
	for(i=1; i<=17; i++){
		printf("%d: nDivisor = %lld, sumDivisor = %lld\n", i, nDivisor[i], sumDivisor[i]);
	}
	for(i=MAX-1; i>=MAX-20; i--){
		printf("%d: nDivisor = %lld, sumDivisor = %lld\n", i, nDivisor[i], sumDivisor[i]);
	}
	#endif
	free(bPrime);
}

long long calcAns(long long *iArray, int a, int b, int k){
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
	long long *nDivisor;
	long long *sumDivisor;
	int i, a, b, k, kase;
	long long gAns, hAns;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") :stdin;
	nDivisor = (long long *) malloc(sizeof(long long)*MAX);
	sumDivisor = (long long *) malloc(sizeof(long long)*MAX);
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