#include <stdio.h>
#define MODULE 1000000007
					
long long powmod(long long n){
	/*return 2^n % MODULE*/
	long long d;
	if(n == 1) return 2;
	else if (n == 0) return 1;
	d = powmod(n/2);
	d = (d*d) % MODULE;
	
	if(n % 2 == 0){
		return d;
	}
	else {
		return (d << 1) % MODULE;
	}
}

long long findAns(long long n){
	long long d;
	if(n == 1) return 1;
	d = powmod(n-1);
	return (n*d) % MODULE;
}

int main(){
	long long ans, n;
	short k = 1, nTest;
	scanf("%hd", &nTest);
	
	while(k <= nTest){
		scanf("%lld", &n);
		ans = findAns(n);
		printf("Case #%d: %lld\n",k++, ans);
	}
	return 0;
}