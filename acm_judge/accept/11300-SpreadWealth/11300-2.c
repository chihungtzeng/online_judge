#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001


unsigned long long avg, residule;
unsigned long long *coin; 
long long *flow, median;
unsigned long long ans;
int nPeople;

int compareLL(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
}

void solve(){
	int i, j;
	flow[0] = 0;
	for(i=1; i<nPeople; i++){
		j = i - 1;
		flow[i] = flow[j] + coin[j] - avg; 
	}
#ifdef DEBUG
	printf("nPeople=%d\n",nPeople);
	printf("unsorted flow:");
	for(i=0; i<nPeople; i++){
		printf("%lld ", flow[i]);
	}
	printf("\n");
#endif

	qsort(flow, nPeople, sizeof(long long), compareLL);

#ifdef DEBUG
	printf("sorted flow:");
	for(i=0; i<nPeople; i++){
		printf("%lld ", flow[i]);
	}
	printf("\n");
	printf("median=%lld\n", median);
#endif
	median = -flow[nPeople/2];
	
	ans = 0;
	for(i=0; i<nPeople; i++){
		ans += llabs(flow[i] + median);
	}
	printf("%llu\n", ans);
}

int main(){

	int i;
	

	coin = (unsigned long long *) malloc(sizeof(unsigned long long)*MAX);
	flow = (long long *) malloc(sizeof(long long)*MAX);

	while(1 == scanf("%d", &nPeople)){
		ans = 0;
		avg = 0;
		residule = 0;
		for(i=0;i<nPeople; i++){
			scanf("%llu", coin+i);
			avg += coin[i];
		}
		avg = avg / nPeople;
		solve();
	}	
	free(coin);
	free(flow);
	return 0;
}