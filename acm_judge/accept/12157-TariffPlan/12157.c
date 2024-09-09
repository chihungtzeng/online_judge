#include <stdio.h>

enum {
	MILE,
	JUICE,
	PACKAGE_NUM
};

int calcMileCost(int duration){
	int nInterval;
	if(duration <= 0) return 0;
	
	nInterval = (duration / 30);
	nInterval += (duration % 30 == 0)? 0 : 1;
	return nInterval * 10;
}

int calcJuiceCost(int duration){
	int nInterval;
	if(duration <= 0) return 0;
	
	nInterval = (duration / 60);
	nInterval += (duration % 60 == 0)? 0 : 1;
	return nInterval * 15;
}

int main(){
	int cost[PACKAGE_NUM];
	int nTest, duration, nDuration;
	int i, k = 1;	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &nDuration);
		cost[MILE] = 0;
		cost[JUICE] = 0;
		for(i=0; i<nDuration; i++){
			scanf("%d", &duration);
			cost[MILE] += calcMileCost(duration + 1);
			cost[JUICE] += calcJuiceCost(duration + 1);
		}
		if(cost[MILE] < cost[JUICE]){
			printf("Case %d: Mile %d\n", k++, cost[MILE]);
		} else if (cost[MILE] == cost[JUICE]){
			printf("Case %d: Mile Juice %d\n", k++, cost[MILE]);
		} else {
			printf("Case %d: Juice %d\n", k++, cost[JUICE]);
		}
	}
	return 0;
}
