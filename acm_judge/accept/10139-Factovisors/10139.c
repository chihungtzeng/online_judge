#include <stdio.h>
#include <math.h>
#define DEBUG 1

int gcd(int a, int b){
	if (0 == b) return a;
	else return gcd(b, a%b);
}

int powmod(int a, int m, int n){
	/*return a^m % n*/
	long int d1;
	
	if (1 == m) return (a % n);
	
	d1 = powmod(a, m/2, n);		
	if(m % 2 == 0){
		return (d1*d1) % n;
	}
	else {
		return (d1*d1*a)%n;
	} 
	 
}

int MRtest(int n){
	/*return values:
	0: composite
	1: prime;
	> 1: a non-trival factor
	*/

	/* rewrite n - 1 = 2^k *m*/
	int k,m,a,b,tmp;
	int i;
	long int square;
	
	
	if ( 0 == n % 2) return 2;
	k = 0;
	tmp = n - 1;
	while( 0 == tmp & 1){
		k++;
		tmp = tmp >> 1;
	}
	m = (n - 1)/ (1 << k);
	
	a = 2;
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
	int divisor;
	int fac;
	int temp, n, sq, factor, i;
	short done;
	while(2 == scanf("%d %d", &fac, &divisor)){
		if(divisor == 0){
			printf("%d does not divide %d!\n",divisor, fac);
			continue;
		}
		if ((divisor <= fac)) {
			printf("%d divides %d!\n",divisor, fac);
			continue;
		}
		if( (fac == 0)){
			if(divisor == 1){
				printf("%d divides %d!\n",divisor, fac);			
			}
			else {
				printf("%d does not divide %d!\n",divisor, fac);
			}
			continue;
		}
		done = 0;
		temp = divisor;
		n = fac;
				
		
		if ((fac > 100000) && (divisor > 100000)){
			while (!done){
				factor = MRtest(temp);
				if(DEBUG){
						printf("factor=%d for temp=%d\n", factor, temp);
				}
				if(factor > n){
					printf("%d does not divide %d!\n",divisor, fac);
					done = 1;
				}
				else if (factor == n){
					n--;
					temp = temp / factor;
				}
				else if (factor > 1){
					temp = temp / factor;
				}
				else if ((factor == 1) && (temp <= n)){
					printf("%d divides %d!\n",divisor, fac);
					done = 1;
				}
				else if ((factor == 0) && (temp <= n)){
					printf("%d divides %d!\n",divisor, fac);
					done = 1;
				}
				else {
					printf("%d does not divide %d!\n",divisor, fac);
					done = 1;
				}
			}
		}		
		else {
			for(i=n; (i > 1) && (temp != 1); i--){
				temp = temp / gcd(temp, i);
			}
			
			if(temp == 1){
				printf("%d divides %d!\n",divisor, fac);
			}
			else {
				printf("%d does not divide %d!\n",divisor, fac);
			}
			
		}
		
	}
	
	return 0;
}