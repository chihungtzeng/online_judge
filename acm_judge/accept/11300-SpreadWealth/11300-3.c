#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001


unsigned long long avg, residule;
unsigned long long *coin; 
long long *flow, median;
unsigned long long ans;
int nPeople;



int partition(long long pivot, long long *arr, int nelem){
	int i, j;
	i = 0;
	j = nelem - 1;

	while (i < j){
		while((i < nelem) && (arr[i] <= pivot)){ i++;}
		while((j > 0) && (arr[j] > pivot)) { j--;}
		if(i < j){
			arr[i] = arr[i] ^ arr[j];
			arr[j] = arr[i] ^ arr[j];
			arr[i] = arr[i] ^ arr[j];
		}
	}
	return i;
}

long long find_kth(long long *base, int nelem, int k){
	long long rsep,lsep,pivot;

	if ( nelem == 1){
		return base[0];
	}

	pivot = base[0];
	rsep = partition(pivot, base, nelem);
	lsep = partition(pivot - 1, base, rsep);

	
	
	/*base[0..lsep-1] <pivot, 
		base[lsep..rsep-1]==pivot
		base[rsep..nelem-1] > pivot
		*/
	if ( k < lsep ){
		return find_kth(base, lsep, k);
	}
	else if ((k >= lsep) &&(k < rsep)){
		return pivot; 
		
	}
	else{
		return find_kth(base + rsep, nelem - rsep , k - rsep );
	}
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

	/*
	qsort(flow, nPeople, sizeof(long long), compareLL);
	median = -flow[nPeople/2];
	*/
	median = -find_kth(flow, nPeople, nPeople >> 1);

#ifdef DEBUG
	printf("sorted flow:");
	for(i=0; i<nPeople; i++){
		printf("%lld ", flow[i]);
	}
	printf("\n");
	printf("median=%lld\n", median);
#endif
	
	
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