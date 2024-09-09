#include <stdio.h>
#define MAX 100001

int main(){
	long long demandSupply[MAX];
	int i, nDemandSupply;
	long long ans;
	long long mask;
	short nBit;
	
	nBit = sizeof(long long)*8 - 1;	
	while(1 == scanf("%d", &nDemandSupply)){
		if(0 == nDemandSupply){ break; }
		for(i= nDemandSupply - 1; i>=0; i--){
			scanf("%lld", demandSupply + i);
		}
		mask = demandSupply[nDemandSupply - 1] >> nBit;
		ans = (demandSupply[nDemandSupply - 1] + mask) ^ mask;
		for(i = nDemandSupply - 2; i >= 0; i--){
			demandSupply[i] = demandSupply[i+1] + demandSupply[i];
			mask = demandSupply[i] >> nBit;
			ans += (demandSupply[i] + mask) ^ mask;
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}