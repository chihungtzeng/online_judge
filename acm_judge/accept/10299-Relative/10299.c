#include <stdio.h>
#define MAX 31623

int nPrime = 3;
int prime[MAX] = {2, 3, 5};
int primeSq[MAX] = {4, 9, 25};

void buildPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}

int totient(int n){
	int i;
	int ans;
	ans = n;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		if(n % prime[i] == 0){
			ans = ans / prime[i];
			ans = ans * (prime[i] - 1);
			do{
				n = n / prime[i];
			} while(n % prime[i] == 0);
		}
	}	
	if(n > 1){
		ans = ans / n;
		ans = ans*(n-1);
	}
	
	return ans;
}


int main(){
	int n;
	buildPrimeTable();
	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		
		if(n == 1){
			puts("0");
		}
		else{
			printf("%d\n",totient(n));
		}
	}
	return 0;
}