#include <stdio.h>
#include <string.h>
#define MAX 32768
#define TRUE 1
#define FALSE 0

char isPrime[MAX];

void buildPrime(){
	int i, j;
	memset(isPrime, TRUE, MAX);
	for(i=3; i<MAX; i+=2){
		if(isPrime[i]){
			for(j=i << 1; j<MAX; j+=i){
				isPrime[j] = 0;
			} 
		}
	} 
}

int isPrimeNum(int n){
	if((n >= 2) && (n & 1)) return isPrime[n];
	else if (n == 2) return TRUE;
	else return FALSE; 
}

int countPair(int n){
	int i, j, bound;
	int result = 0;
	bound = n / 2;
	for(i=3; i<=bound; i += 2){
		if(isPrimeNum(i) && isPrimeNum(n - i)) result++;
	}
	if(isPrimeNum(n - 2)) result++;
	return result;
}

int main(){
	int n, i;
	int count;
	buildPrime();
	#if 0
	for(i=3; i<550; i+=2){
		if(isPrime[i]) printf("%d ", i);
	}
	printf("\n");
	#endif
	while(1 == scanf("%d", &n)){
		if(n == 0) break;
		count = countPair(n);
		printf("%d\n",count);
	}
	return 0;
}