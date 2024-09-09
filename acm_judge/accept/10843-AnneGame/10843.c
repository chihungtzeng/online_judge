#include <stdio.h>
#define MOD 2000000011

long powmod(long n, long k){
	long result;
	if(k == 1) return n;
	
	result = powmod(n, k/2);
	result = result*result % MOD;
	if(k & 1) {
		return result*n % MOD;
	} 
	else return result;
}

int main(){
	short nTest, k = 1;
	long n, ans;
	scanf("%hd",&nTest);
	while(k <= nTest){
		scanf("%ld",&n);
		switch (n){
			case 1: ans = 1; break;
			case 2: ans = 1; break;
			default: ans = powmod(n, n-2);
				break;
		}
		printf("Case #%hd: %ld\n",k++, ans);
	}
	return 0;
}