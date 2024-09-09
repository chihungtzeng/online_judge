#include <stdio.h>
#include <math.h>
#define MAX 1000000

int primeTable[MAX];
int nPrime;

inline int testPrimity(int n){
	int i, sq;
	sq = sqrt(n);
	for(i=2; primeTable[i] <= sq; i++){
		if(n % primeTable[i] == 0){
			return 0;
		}
	}
	return 1;
}



inline void initPrimeTable(){
	int i;
	primeTable[0] = 2;
	primeTable[1] = 3;
	primeTable[2] = 5;
	nPrime = 3;
	i = 7;
	while(i < MAX){
		if(testPrimity(i)){
			primeTable[nPrime++] = i;
		}
		i += 4;
		if(testPrimity(i)){
			primeTable[nPrime++] = i;
		}
		i += 2;
	}
}

inline int nFactor(int x, int p){
	long long divisor;
	int result;
	divisor = p;
	result = 0;
	while(divisor <= x){
		result += (x / divisor);
		divisor = divisor * p; 
	}
	
	return result;
}

inline int findLeastPrimeIndex(int n){
	int left, right, middle;
	left = 0;
	right = nPrime - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(primeTable[middle] == n){
			return middle;
		}
		else if (primeTable[middle] < n){
			left = middle + 1;
		}
		else{
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int input, i, count, skipStart, skipEnd;
	int sq, weight;
	initPrimeTable();
	
	/*
	printf("%d primes found, last one: %d\n", nPrime, primeTable[nPrime - 1]);
	for(i=0; i< 100; i++){
		printf("%d ", primeTable[i]);
	}
	*/
	
	while(1 == scanf("%d", &input)){
		count = 0;
		sq = sqrt(input);
		skipEnd = findLeastPrimeIndex(input);
		weight = 1;
		for(i = 2; i < sq; i++){
			skipStart = findLeastPrimeIndex(input / i);
			count = count + weight*(skipEnd - skipStart);
			skipEnd = skipStart;
			weight++;
		}		
		for(i = 0; (i <= skipEnd); i++){
			count += nFactor(input, primeTable[i]);
		} 
		printf("%d\n", count);
	}
	
	
	return 0;
}