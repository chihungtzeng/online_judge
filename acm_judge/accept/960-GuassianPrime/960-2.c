/*AC*/
#include <stdio.h>
#include <math.h>
#define PRIME 1
#define COMPOSITE 0
#define UNDEF -1;
#define DEBUG 0
#define MAX 10000

long gcd(long a, long b){
	if (0 == b) return a;
	else return gcd(b, a%b);
}

int min(int x, int y){
	if( x > y) return y;
	else return x;
}
int max(int x, int y){
	if (x > y) return x;
	else return y;
}

int checkPrimity(int n, int *primeTable, int nPrime){
	int sq, i;
	sq = (int) sqrt(n);
	for(i=0; (i<nPrime) && (primeTable[i] <= sq); i++){
		if(n % primeTable[i] == 0) {
			return COMPOSITE;
		}
	}
	return PRIME;
}

int main(){
	int imagine, real;
	int a, b;
	int nTest;
	int i;
	short state;
	int primeTable[MAX], nPrime;

	primeTable[0] = 2;
	primeTable[1] = 3;
	primeTable[2] = 5;
	nPrime = 3;
	real = 7;
	i = 1;
	
	while(real <= 15000){
		int sq, j;
		short isPrime;
		
		sq = (int) sqrt(real);
		isPrime = 1;
		for(j=0; (j < nPrime) && (primeTable[j] <= sq) && isPrime; j++){
			if(real % primeTable[j] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primeTable[nPrime++] = real;
		}
		
		real += 4; /*real = 6*i + 5*/
		sq = (int) sqrt(real);
		isPrime = 1;
		for(j=0; (j < nPrime) && (primeTable[j] <= sq) && isPrime; j++){
			if(real % primeTable[j] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primeTable[nPrime++] = real;
		}
		real += 2;		
	}
	if(DEBUG){
		printf("nPrime=%d the last prime found:%d\n",nPrime, primeTable[nPrime-1]);
	}
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&real, &imagine);
		a = max(abs(real), abs(imagine));
		b = min(abs(real), abs(imagine));
		if(DEBUG){
			printf("gcd(%d %d) = %ld\n",a, b, gcd(a,b));
		}
		state = UNDEF;
		
		if (a == 0){
			state = ((checkPrimity(b, primeTable, nPrime) == PRIME) && (b % 4 == 3) )? PRIME : COMPOSITE;
		}
		else if (b == 0){
			state = ((checkPrimity(a, primeTable, nPrime) == PRIME) && (a % 4 == 3) )? PRIME : COMPOSITE;
		}
		else if ((gcd(a, b) > 1)){
			state = COMPOSITE;
		}
		else {
			/*now we have a+bi, a>=b, a>0, b>0*/
			state = checkPrimity(a*a + b*b, primeTable, nPrime);
		}
		
		if(state == COMPOSITE){
			printf("C\n");
		}
		else if (state == PRIME){
			printf("P\n");
		}
		else {
			if(DEBUG){
				printf("state is not defined!\n");
			}
			printf("C\n");
		}
	}
	return 0;
}