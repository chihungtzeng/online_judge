#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int compareLL(const void *a, const void *b){
	return (long long *)a - (long long *)b;
}

int main(){
	int nPeople;
	unsigned long long avg, residule;
	unsigned long long *coin; 
	int i;
	unsigned long long ans;

	coin = (unsigned long long *) malloc(sizeof(unsigned long long)*MAX);

	while(1 == scanf("%d", &nPeople)){
		ans = 0;
		avg = 0;
		residule = 0;
		for(i=0;i<nPeople; i++){
			scanf("%llu", coin+i);
			residule += coin[i];
			avg += residule / nPeople;
			residule = residule % nPeople;
		}
		for(i=0; i<nPeople; i++){
			ans += llabs(avg - coin[i]);
		}
		printf("%llu\n", ans);
	}	
	free(coin);
	return 0;
}