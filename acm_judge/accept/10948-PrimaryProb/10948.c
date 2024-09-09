#include <stdio.h>
#include <math.h>
#define MAX 1000000
#define VERBOSE 0

int primeTable[78500];
int nPrime;

int testPrimity(int t){
	int sq, i;
	char isPrime = 1;
	sq = sqrt(t);
	for(i=0; (i<nPrime) && (primeTable[i] <= sq) && (isPrime); i++){
		if(t % primeTable[i] == 0){
			isPrime = 0;
		}
	}
	return isPrime;
}

void initPrimeTable(){
	int t, sq;
	char isPrime;
	primeTable[0] = 2;
	primeTable[1] = 3;
	primeTable[2] = 5;
	nPrime = 3;
	t = 7;
	while(t < MAX){
		if(testPrimity(t)){
			primeTable[nPrime++] = t;
		}
		t += 4;
		if(testPrimity(t)){
			primeTable[nPrime++] = t;
		}
		t += 2;
	}
}

int closestPrimeIndex(int n){
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
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int rightIndex, leftIndex, target;
	int input, p1, p2;
	char done;
	nPrime = 0;
	initPrimeTable();
	if(VERBOSE){
		printf("%d primes found, largest one:%d\n",nPrime, primeTable[nPrime-1]);
	}
	while(1){
		scanf("%d", &input);
		if(0 == input){
			break;
		}
		rightIndex = closestPrimeIndex(input);
		if(primeTable[rightIndex] == input){
			rightIndex--;
		}
		
		leftIndex = 0;
		done = 0;
		while((leftIndex <= rightIndex) && (!done)){
			target = input - primeTable[rightIndex];
			leftIndex = closestPrimeIndex(target);
			if(primeTable[leftIndex] == target){
				done = 1;
				printf("%d:\n",input);
				printf("%d+%d\n",primeTable[leftIndex], primeTable[rightIndex]);
			}
			else{
				rightIndex--;
			}
		}
		if(!done){
			printf("%d:\nNO WAY!\n",input);
		}
	}

	return 0;
}