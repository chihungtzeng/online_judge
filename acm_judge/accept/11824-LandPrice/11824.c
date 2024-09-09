#include <stdio.h>
#include <stdlib.h>
#define MAX 5000000

int compareInt(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

long long mpow(int n, int k){
	long long result;
	if(k == 0) return 1;
	
	result = mpow(n, k/2);
	result = result*result;
	if(k % 2 == 0) return result;
	else return result*n;
}

int main(){
	short nTest;
	long long cost;
	int price[40], nLand, i;
	char done;
	scanf("%hd", &nTest);
	
	while(nTest >= 1){
		nTest--;
		nLand = 0;
		cost = 0;
		done = 0;
		while(!done){
			scanf("%d", &price[nLand]);
			if(price[nLand] == 0){
				done = 1;
			}
			nLand++;				
		}
		qsort(price, nLand, sizeof(int), compareInt);
		
		done = 0;
		for(i=0; (i<nLand)&&(!done); i++){
			cost += mpow(price[i], i+1) << 1;
			if(cost > MAX){
				done = 1;
			}
		}		
		
		if(cost > MAX){
			printf("Too expensive\n");
		}
		else{
			printf("%lld\n",cost);
		}
		
	}
	return 0;
}