#include <stdio.h>
#define MAX 10000
#define LEN 1240
#define DEBUG 0

int prime[LEN] = {2, 3, 5};
int primeSq[LEN] = {4, 9, 25};
int nPrime = 3;

void buildPrimeTable(){
	int t = 7;
	int i;
	char isPrime, step = 4;
	while(t < MAX){
		isPrime = 1;
		for(i=1; primeSq[i] <= t; i++){
			if(t % prime[i] == 0){
				isPrime = 0;
				break;
			}
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime += 1;
		}
		t += step;
		step = 6 - step; 
	}
}

int isPrime(int n){
	int i;
	if(n == 1) return 0;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		if(n % prime[i] == 0) return 0;
	}
	return 1;
}

void solve(int n){
	int cur ;
	
	/*n is odd*/
	if(n <= 3){
		printf("%d is not the sum of two primes!\n", n);
		return ;
	}
	
	if (n & 1){
		if(isPrime(n-2)){
			printf("%d is the sum of %d and %d.\n", n, 2, n-2 );
		} else {
			printf("%d is not the sum of two primes!\n", n);
		}
		return ;
	} 
	
	/*n is even*/
	cur = n >> 1;
	if(!(cur & 1)) cur++;
	
	if(n - cur == cur){
		cur += 2;
	}
	do{		
		if(isPrime(cur) && isPrime(n -cur)){
			printf("%d is the sum of %d and %d.\n", n, n -cur, cur);
			return ;
		} else {
			cur += 2;
		}
	} while(cur < n);
	printf("%d is not the sum of two primes!\n", n);
}

int main(){
	int i;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	buildPrimeTable();
	#if 0
	for(i=0; i<100; i++){
		printf("%d ", prime[i]);
	}
	printf("\n nPrime=%d\n", nPrime);
	#endif
	while(1 == fscanf(fp, "%d", &i)){
		solve(i);
	}

	return 0;
}