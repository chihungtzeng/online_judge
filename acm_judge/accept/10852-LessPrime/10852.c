#include <stdio.h>
#include <math.h>
#define MAX 5000

short prime[MAX];
short nPrime;

void initPrimeTable(){
	int i, t, sq;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	t = 7;
	nPrime = 3;
	while(t < MAX){
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 4;
		isPrime = 1;
		sq = sqrt(t);
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime++] = t;
		}
		t += 2;
	}
}

int mybsearch(int target){
	int left, right, middle;
	left = 0;
	right = nPrime - 1;
	while(left <= right){
		middle = (left + right) >>1;
		if(prime[middle] == target) return middle;
		else if (prime[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)>>1;
}

int main(){
	int nTest;
	int n, index;
	initPrimeTable();

	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d", &n);
		index = mybsearch(n >> 1) + 1;
		printf("%d\n",prime[index]);
	}	
	
	return 0;
}