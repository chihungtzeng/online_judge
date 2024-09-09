#include <stdio.h>
#include <string.h>
#define LEN 2001

void solve(int n, int len){
	int i;
	long long r;
	for(i=0, r = 0; i<len; i++){
		r = ((r << 3) + (r << 1) + 1) % n;
	}
	printf("%lld\n", r);
}

int main(){
	char prime[LEN];
	int n;
	int nTest;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %s", &n, prime);
		solve(n, strlen(prime));
	}
	return 0;
}