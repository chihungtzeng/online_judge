/*AC*/
#include <stdio.h>
#include <math.h>

int main(){
	long long n, ans;
	while(1 == scanf("%lld", &n)){
		n--;
		ans = log2(n);
		ans += n;
		printf("%lld\n", ans);
	}
	return 0;
}