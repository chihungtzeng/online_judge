#include <stdio.h>
#include <math.h>
#define MAX 1000000

int prime[MAX];
int nPrime;

void initPrimeTable(){
	int sq, t, i;
	char isPrime;
	nPrime = 3;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	
	t = 7;
	while(t < MAX){
		sq = sqrt(t);
		isPrime = 1;
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		sq = sqrt(t);
		isPrime = 1;
		for(i=2; isPrime && (prime[i] <= sq); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}

int mybsearch(int target){
	int left, right, middle;
	left = 0;
	right = nPrime - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(prime[middle] == target) return middle;
		else if(prime[middle] < target) left = middle + 1;
		else right = middle - 1; 
	}
	return (left + right) >> 1;
}

long findAns(int n){
	int i, index, ub;
	long ans = 0;
	if ( n == 1) return 0;
	else if (n == 2) return 0;
	
	ub = n >> 1;
	for(i=0; (i<nPrime) && (prime[i] <= ub); i++){
		index = mybsearch(n - prime[i]);
		if(index > i){
			ans = ans + (index - i);
		}
	}
	return ans;
}

int main(){
	int i;
	short k=1;
	long ans;
	int n;
	initPrimeTable();
	/*
	for(i=0; i<nPrime; i++){
		printf("%d ",prime[i]);
	}
	printf("\n");
	*/
	while(1 == scanf("%d", &n)){
		if(n == 0) break;

		ans = findAns(n);

		printf("Case %hd: %ld\n", k++, ans);
	}
	
	return 0;		
}