#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 1000000

long long myPow(long long base, long long e){
	long long y = base, result = 1;
	
	while(e){
		y = y % MOD;
		if(e & 1){
			result = (result * y) % MOD;
		}
		e = e >> 1;
		y = y*y;
	}
	return result;
}



int main(){
	short nTest;
	long long base, expn;
	long long prefix, suffix;
	double leading, tmp;
	scanf("%hd", &nTest);
	while(nTest){
		nTest--;
		scanf("%lld %lld", &base, &expn);
		suffix = myPow(base, expn) % 1000;
		tmp = expn * log10(base);
		tmp = tmp - floor(tmp);
		leading = exp10(tmp);
		prefix = leading * 100;
		
		printf("%lld...%03lld\n", prefix, suffix);
	}
	return 0;
}