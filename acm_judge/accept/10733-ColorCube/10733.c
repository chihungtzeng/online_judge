#include <stdio.h>
/*Burnside's lemma*/
int main(){
	long long n, n2, n4;
	long long sum;
	while(1 == scanf("%lld",&n)){
		if(n == 0) return 0;
		
		n2 = n*n;
		n4 = n2*n2;
		sum = n4*(n2 + 3) + 12 * n2*n + (n2 << 3);
		sum = sum / 24;
		printf("%lld\n",sum); 
	}
	return 0;
}