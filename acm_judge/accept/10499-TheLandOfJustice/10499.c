#include <stdio.h>

int main(){
	long long n;
	while(1 == scanf("%lld", &n)){
		if(n < 0) return 0;
		n = (n == 1)? 0 : ((n << 4) + (n << 3) + n);
		printf("%lld%%\n",n);
	}
	return 0;
}