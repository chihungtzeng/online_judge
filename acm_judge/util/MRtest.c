#include <stdio.h>
#include <math.h>
#define DEBUG 1

long gcd(long a, long b){
	if (0 == b) return a;
	else return gcd(b, a%b);
}

long powmod(long a, long m, long n){
	/*return a^m % n*/
	long long d1;
	
	if (1 == m) return (a % n);
	
	d1 = powmod(a, m/2, n);		
	if(m % 2 == 0){
		return (d1*d1) % n;
	}
	else {
		return (d1*d1*a)%n;
	} 
	 
}

long MRtest(long n, long a){
	/*return values:
	0: composite
	1: prime;
	> 1: a non-trival factor
	*/

	/* rewrite n - 1 = 2^k *m*/
	long k,m,b,tmp;
	long i;
	long long square;
	
	
	if ( 0 == n % 2) return 2;
	k = 0;
	tmp = n - 1;
	while( 0 == tmp & 1){
		k++;
		tmp = tmp >> 1;
	}
	m = (n - 1)/ (1 << k);
	
	
	b = powmod(a,m,n);
	if (( b == 1) || ( b == n - 1)){
		return 1;
	} 
	for(i=i;i<k-1;i++){
		tmp = b;
		b = powmod(b, 2, n);
		if ( b == 1 ){
			/*a non-trivial factor of n is found*/
			return gcd(tmp -1, n);
		}
		if ( b == n - 1){
			return 1;
		}
	}
	tmp = b;
	b = powmod(b,2,n);
	if ( b != n-1) return gcd(tmp - 1, n);
	else return 1;
}

int main(){
	long divisor;
	long fac;
	long temp, factor, i, sq;
	short done;
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
		
		temp = divisor;
		
		
		
		if ((fac > 10000) && (temp > 10000)){
				long prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
				long nPrime = 8;
				long test[8];
				long result;
				long max = -1;
				short isPrime;
				
				
				for(i=0; (i < nPrime); i++){
					test[i] = MRtest(temp, prime[i]);
					if(test[i] > max){
						max = test[i];
					}
				}
				isPrime = 1;
				for(i=0; i < nPrime; i++){
					if(test[i] != 1){
						isPrime = 0;
					}
				}
				if (isPrime){
					printf("%ld does not divide %ld!\n",divisor, fac);
					continue;
				} 
				if(DEBUG){
						printf("max factor %ld found for temp=%ld\n", max, temp);
				}
				
				temp = temp / max;
				if(DEBUG){
					printf("new temp=%ld\n", temp);
				}
				
				
		}		
		
		
		for(i=fac; (i > 1) && (temp != 1); i--){
			int shit;
			shit = gcd(temp, i);
			if(shit > 1){
				temp = temp / shit;
			}
		}
		
		if(temp == 1){
			printf("%ld divides %ld!\n",divisor, fac);
		}
		else {
			printf("%ld does not divide %ld!\n",divisor, fac);
		}
		
	}
	
	return 0;
}