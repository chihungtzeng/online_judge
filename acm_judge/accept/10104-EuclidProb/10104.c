/**TLE*/
#include <stdio.h>

long gcd(long a, long b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

long coef(long m, long n){
	if(0 == m) return 0;
	if(0 == n) return 1;
	if( m < n){
		return coef(m, n%m) - (n/m)*coef(n%m, m);
	}
	else {
		return coef(m%n, n);
	}
}

int main(){
	long x, y, d, a, b;
	while(2 == scanf("%ld %ld", &a, &b)){
		d = gcd(a, b);
		if( a == b ){
			x = 0;
			y = 1;
		}
		else{
			a= a/d;
			b= b/d;
			x = coef(a, b);
			y = coef(b, a);
		}
		printf("%ld %ld %ld\n",x, y, d);
	}	
	return 0;
}
