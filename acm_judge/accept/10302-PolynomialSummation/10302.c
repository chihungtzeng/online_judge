#include <stdio.h>
#define LEN 50001


int main(){
	unsigned long long sum[LEN];
	unsigned long long i;
	sum[0] = 0;
	for(i=1; i<LEN; i++){
		sum[i] += sum[i-1] + i*i*i;
	}
	while(1 == scanf("%llu", &i)){
		printf("%llu\n", sum[i]);
	}
	return 0;
}