#include <stdio.h>
#include <math.h>
#define MAX 1300
#define MAXLEN 21
#define VERBOSE 0

int primeTable[MAX];
int nPrime;

void genPrime(){
	short t, isPrime;
	primeTable[0] = 1;
	primeTable[1] = 2;
	primeTable[2] = 3;
	primeTable[3] = 5;
	nPrime = 4;
	t = 7;
	while(t < MAX){
		int sq, i;
		sq = sqrt(t);
		isPrime = 1;
		for(i=1; (primeTable[i] <= sq) && (isPrime); i++){
			if (t % primeTable[i] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primeTable[nPrime++] = t;
		}
		t += 4;
		isPrime = 1;
		for(i=1; (primeTable[i] <= sq) && (isPrime); i++){
			if (t % primeTable[i] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primeTable[nPrime++] = t;
		}
		t += 2;
	}
}

int testPrimity(int n){
	short left, right, middle;
	left = 0;
	right = nPrime - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(primeTable[middle] == n){
			return 1;
		}
		else if (primeTable[middle] < n){
			left = middle + 1;
		}
		else {
			right = middle -1;
		}
	}
	return 0;
}

int satoi(char *s){
	char *c;
	int sum=0;
	c = s;
	while(*c != '\0'){
		if( (*c >= 'a') && (*c <= 'z')){
			sum += *c - 'a' + 1;
		} 
		else if ( (*c >= 'A') && (*c <= 'Z' )){
			sum += *c - 'A' + 27;
		}
		c++;
	}
	return sum;
}

int main(){
	char input[MAXLEN];
	short isPrime;
	int num;


	genPrime();	
	if(VERBOSE){
		int i;
		printf("%d prime found\n",nPrime);
		for(i=0; i<nPrime; i++){
			printf("%d ", primeTable[i]);
		}
		printf("\n");
	}
	
	while(1 == scanf("%s", input)){
		num = satoi(input);
		if(VERBOSE){
			printf("input=%s num = %d\n",input, num);
		}
		if(testPrimity(num)){
			printf("It is a prime word.\n");
		}
		else {
			printf("It is not a prime word.\n");
		}
	}	
	return 0;	
}