#include <stdio.h>

long long findAns(long long n, long long k){
	long long ans = n;
	
	while(n >= k){
		ans += n / k;
		n = (n / k) + (n % k);
	}
	return ans;
}

int main(){
	long long n, k;
	while(2 == scanf("%lld %lld", &n, &k)){
		printf("%lld\n", findAns(n, k));
	}
	return 0;
}