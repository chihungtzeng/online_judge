#include <stdio.h>
#define MAX 1000

int prime[MAX]={1,2,3,5};
int nPrime=4;


void buildPrimeTable(){
	int i, t;
	char isPrime;
	t = 7;
	while(t <= MAX){
		isPrime = 1;
		for(i=3; isPrime && (prime[i] * prime[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=3; isPrime && (prime[i] * prime[i] <= t); i++){
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
		else if (prime[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)/2;
}

int main(){
	int N, C;
	int middle, right;
	int i,j;
	int start, end, skip, nelem;
	
	buildPrimeTable();
	while(2 == scanf("%d %d", &N, &C)){
		right = mybsearch(N);
		
		
		nelem = right + 1;
		
		
		if(nelem % 2 == 1){
			skip = (nelem - (C + C - 1)) / 2;
			if(skip < 0) skip = 0;
			start = skip;
			end = right - skip; 
		}
		else{
			skip = (nelem - C - C)/2;
			if(skip < 0) skip = 0;
			start = skip;
			end = right-skip;
		}
		
 		printf("%d %d: ",N, C);
 		printf("%d",prime[start]);
 		for(i=start + 1; i<=end; i++){
 			printf(" %d",prime[i]);
 		}  
 		printf("\n\n");
	}
	return 0;
}
