#include <stdio.h>
#include <math.h>

int main(){
	short nTest;
	unsigned long long n, k;
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%llu", &n);
		k = (-1 + sqrt(1 + (n << 3)))/2;
		printf("%llu\n",k);
	}
	return 0;
}