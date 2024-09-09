#include <stdio.h>
#include <stdlib.h>
#define MAX 3000

int main(){
	int k, nTest, ans;
	long long *nBottle;
	long long range[64];
	
	for(k=0; k<64;++k){
		range[k] = 1LL << k;
	}
	scanf("%d", &nTest);
	nBottle = (long long *) malloc(sizeof(long long)*nTest);

	for(k=0; k<nTest; k++){
		scanf("%lld", nBottle + k);
	}
	
	
	for(k=0; k<nTest; k++){
		ans = 0;
		while(nBottle[k] >= range[ans]){
			ans++;
		}
		printf("Case %d: %d\n", k + 1, ans);
	}
	return 0;
}