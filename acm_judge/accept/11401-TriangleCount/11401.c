#include <stdio.h>
#define MAX 1000001

int main(){
	unsigned long long sum[MAX];
	int i, n;
	unsigned long long k;
	sum[3] = 0;
	sum[4] = 1;
	sum[5] = 3;
	sum[6] = 7;
	for(i=7; i<MAX; i++){
		if(i & 1){
			k = i >> 1;
			k = k*k- k;
		}
		else{
			k = (i >> 1) - 1;
			k = k*k;
		}
		sum[i] = sum[i-1] + k;
	}
	while(1 == scanf("%d", &n)){
		if(n < 3) break;
		else printf("%llu\n", sum[n]);
	}
	return 0;
}