#include <stdio.h>
#define LEN 1001

long long powmod(long long base, long long e, long long m){
	/*return base^e % m*/
	long long result = 0;
	if(e == 0) return 1;
	result = powmod(base, e >> 1, m);
	result = (result * result) % m;
	if(e & 1){
		result = (result * base) % m;
	}
	return result;
}

int main(){
	long long n, K, MOD, i, num;
	int nTest;
	int caseno = 0;
	long long sum, coef, ans;
	
	
	scanf("%d", &nTest);
	while(nTest--){
		sum = 0;
		scanf("%lld %lld %lld", &n, &K, &MOD);
		for(i=0; i<n; i++){
			scanf("%lld", &num);
			sum += num;
		}
		coef = (K * powmod(n, K - 1, MOD)) % MOD;
		ans = (sum * coef) % MOD;
		printf("Case %d: %lld\n", ++caseno, ans);
	}
	
	return 0;
}