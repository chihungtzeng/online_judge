#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int main(){
	long long demandSupply[MAX];
	int i, nDemandSupply;
	long long ans;
	
	while(1 == scanf("%d", &nDemandSupply)){
		if(0 == nDemandSupply){ break; }
		for(i= nDemandSupply - 1; i>=0; i--){
			scanf("%lld", demandSupply + i);
		}
		ans = abs(demandSupply[nDemandSupply - 1]);
		for(i = nDemandSupply - 2; i >= 0; i--){
			demandSupply[i] = demandSupply[i+1] + demandSupply[i];
			ans += abs(demandSupply[i]);
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}