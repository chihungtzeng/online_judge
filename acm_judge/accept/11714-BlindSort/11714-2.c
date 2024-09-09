#include <stdio.h>
int main(){
	long long n, ans;
	while(1 == scanf("%lld", &n)){
		n--;
		ans = n - 1;
		while(n > 0){			
			n = n >> 1;
			ans++;
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}