#include <stdio.h>

unsigned long int pow2mod(unsigned long int b, unsigned long int m){
	unsigned long int r;
	r = b % m;
	r = (r * r) % m;
	return r; 
} 

unsigned long int powmod(unsigned long int b, unsigned long int p, unsigned long int m){
	unsigned long r;
	unsigned long half;
	if(p == 0) return 1;
	else if (p == 1) return (b % m);
 
	half = powmod(b, p >> 1, m);
	r = (half * half) % m;
	if( p & 1){ /*p is odd*/
		return (r * b) % m;
	}
	else{
		return r;
	}
}

int main(){
	unsigned long int b, p, m;
	while(3 == scanf("%ld %ld %ld",&b, &p, &m)){
		printf("%ld\n",powmod(b, p, m));
	}
	return 0;
}