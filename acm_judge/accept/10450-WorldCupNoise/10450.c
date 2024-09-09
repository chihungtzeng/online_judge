#include <stdio.h>
#define LEN 51

long long fib[LEN] = {0, 2, 3};

unsigned long long getFib(){
	short i;

	for(i=3; i<LEN; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int main(){
	short k = 1, nTest, n;
	getFib();
	scanf("%hd", &nTest);
	
	while(nTest--){
		scanf("%hd", &n);
		printf("Scenario #%hd:\n%lld\n\n", k++, fib[n]);
	}
	return 0;
}