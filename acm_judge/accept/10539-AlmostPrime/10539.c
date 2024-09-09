#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0


int nPrime;
int *prime;
long long *primeSq;

void buildPrimeTable(){
	int i,j;
	char *cprime;
	cprime = (char *) malloc(MAX);
	memset(cprime, 1, MAX);
	cprime[0] = 0;
	cprime[1] = 0;
	for(i=3; i<MAX; i+=2){
		if(cprime[i]){
			for(j=i<<1; j<MAX; j+=i){
				cprime[j] = 0;
			}
		}
	}
	prime = (int *) malloc(sizeof(int)*80000);
	primeSq = (long long *) malloc(sizeof(long long)*80000);
	nPrime = 1;
	prime[0] = 2;
	primeSq[0] = 4;
	for(i=3; i<MAX; i+=2){
		if(cprime[i]){
			prime[nPrime]= i;
			primeSq[nPrime] = (long long)i * i;
			nPrime++;
		}
	}
}

int getNum(int p, long long low, long long high){
	/*return how many x such that low <= p^x <= high for x >= 2*/
		
	long long count = 0;
	long long cur = p;
	
	cur = cur * p;
	while(cur < low) {
		cur = cur * p;
	}
	while(cur <= high){	
		count++;
		cur = cur * p;
	} 
	return count;
}

void solve(long long low, long long high){
	int i;
	int ans = 0;
	
	i = 0;
	
	while((primeSq[i] <= high) && (i < nPrime)){
		ans += getNum(prime[i], low, high);
		i++;
	}
	printf("%d\n", ans);
}

int main(){
	int nTest;
	long long low, high;
	buildPrimeTable();
	#if 0
	int n;
	for(n=0; n<100; n++){	
		printf("%d ", prime[n]);
	}
	printf("\n nPrime=%d %lld\n", nPrime, primeSq[nPrime-1]);
	#endif
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%lld %lld", &low, &high);
		solve(low, high);
	}
	
	free(prime);
	free(primeSq);
	return 0;	
}
