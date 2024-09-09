#include <stdio.h>

int gcd4(long long n){
	if (n % 4 == 0) return 4;
	else if (n % 2 == 0) return 2;
	else return 1;
}

int main(){
	short nTest, k=1;
	long long n, up, down, g;

	scanf("%hd", &nTest);	
	while(nTest){
		nTest--;
		scanf("%lld", &n);
		n = n*n - n;
		g = gcd4(n);
		if(g > 1){
			up = n / g;
			down = 4 / g;
		}
		if(down > 1){
			printf("Case %hd: %lld/%lld\n", k++, up, down);
		} else{
			printf("Case %hd: %lld\n", k++, up);
		}
	}
	
	return 0;
}