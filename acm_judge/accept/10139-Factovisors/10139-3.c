#include <stdio.h>
#include <math.h>
#include <string.h>
#define DEBUG 0
#define MAX 20000

long primeList[MAX];
long nPrime;

void genPrimeList(){
	long n, i;
	long sq;
	short ifPrime = 1; 
	primeList[0] = 2;
	primeList[1] = 3;
	primeList[2] = 5;
	primeList[3] = 7;
	nPrime = 4;
	n = 11;
	
	while( n <= 65533 ){
		sq = (long) sqrt(n);
		ifPrime = 1;
		for(i=0; (i < nPrime) && (primeList[i] <= sq) && (ifPrime); i++){
			if(n % primeList[i] == 0){
				ifPrime = 0;
			}
		}
		if(ifPrime){
			primeList[nPrime++] = n;
		}
		n += 2;
	}
	if(DEBUG){
		printf("nPrime=%ld last prime found:%ld\n",nPrime, primeList[nPrime-1]);
	}
}

int nFactorForFac(long n, long p){
/*determine how many prime factors p that n! has*/
	int result = 0;
	long d;
	d = p;
	while(d <= n){
		result += n / d;
		d = d*p;

	}
	return result;
}

int main(){
	long divisor,temp;
	long fac;
	int ffactor[MAX], dfactor[MAX];
	int i;
	short ifDivisible, ifPrime;
	genPrimeList();
	
	while(~scanf("%ld %ld", &fac, &divisor)){
		if(divisor == 0){
			printf("%ld does not divide %ld!\n",divisor, fac);
			continue;
		}
		if ((divisor <= fac)) {
			printf("%ld divides %ld!\n",divisor, fac);
			continue;
		}
		if( (fac == 0)){
			if(divisor == 1){
				printf("%ld divides %ld!\n",divisor, fac);			
			}
			else {
				printf("%ld does not divide %ld!\n",divisor, fac);
			}
			continue;
		}
		memset(ffactor, 0, sizeof(int)*MAX);
		memset(dfactor, 0, sizeof(int)*MAX);
		
		temp = divisor;
		for(i=0; (i<nPrime) && (temp > 1); i++){
			while( temp % primeList[i] == 0){
				dfactor[i] += 1;
				temp = temp / primeList[i];
			}
		}
		if(temp > fac){
			printf("%ld does not divide %ld!\n",divisor, fac);
			continue;
		}

		if(DEBUG){
			printf("%ld = ", divisor);
			for(i=0; i<nPrime; i++){
				if(dfactor[i] > 0){
					printf("%ld(%d) ", primeList[i], dfactor[i]);
				} 
			}
			printf("\n");
		}
		
		ifPrime = 1;
		for(i=0; (i < nPrime) && (ifPrime); i++){
			if(dfactor[i] > 0){
				ifPrime = 0;
			}
		}
		
		if(ifPrime){
			printf("%ld does not divide %ld!\n",divisor, fac);
			continue;
		}
		
		ifDivisible = 1;
		for(i=0; (i<nPrime) && (ifDivisible); i++){
			if ((dfactor[i] > 0) && (nFactorForFac(fac, primeList[i]) < dfactor[i])){
				if(DEBUG){ printf("%ld(%d) ", primeList[i], nFactorForFac(fac, primeList[i]));}
				ifDivisible = 0;
			}
		}

			

		if(ifDivisible){
			printf("%ld divides %ld!\n",divisor, fac);	
		}
		else{
			printf("%ld does not divide %ld!\n",divisor, fac);
		}
	}	
	
	
	return 0;
}