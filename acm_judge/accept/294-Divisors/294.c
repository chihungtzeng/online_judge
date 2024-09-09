#include <stdio.h>
#define MAX 31622

int prime[MAX]={2,3,5};
int primeSquare[MAX] ={4, 9, 25};
int nPrime = 3;

void buildPrimeTable(){
	int i, t;
	char isPrime;
	t = 7;
	nPrime=3;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (isPrime) && (primeSquare[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; (isPrime) && (primeSquare[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSquare[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}

int nDivisor(int n){
	int result=1;
	int i, k;
	for(i=0; (i < nPrime) && (primeSquare[i] <= n); i++){
		if(n % prime[i] == 0){
			k = 1;
			do{
				k++;
				n = n / prime[i];
			} while(n % prime[i] == 0);
			result = result * k;
		} 
	}
	if(n > 1){
		result = result*2;
	}
	return result;
}

int main(){
	int nDiv, n, ans;
	int left, right, tmp;
	int nTest, i;
	buildPrimeTable();
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&left, &right);
		ans = nDivisor(left);
		n = left;
		for(i=left + 1; i <= right; i++){
			nDiv = nDivisor(i);
			if(nDiv > ans){
				ans = nDiv;
				n = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",left,right,n,ans);
	}
	return 0;
}