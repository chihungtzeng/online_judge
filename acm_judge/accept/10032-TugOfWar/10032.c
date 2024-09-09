#include <stdio.h>
#include <string.h>
#define MAX 22501
#define PEOPLE 101

int dp[PEOPLE][MAX];
short weight[PEOPLE];
short nPeople;
int sum, target, bestAns;
int groupSize[2];
int prefixSum[PEOPLE];
char evenGroup;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int knapsack(short pos, int team1, int curWeight){
	int t1, t2;
	int potential;
	int team2;
	int nRemain;
	

	
	
	if(team1 == groupSize[0]){
		if(evenGroup){
			if(curWeight > bestAns) bestAns = curWeight;
			return curWeight;
		}
		else{
			curWeight = (curWeight + weight <= target)? curWeight + weight : curWeight;
			if(curWeight > bestAns) bestAns = curWeight;
			return curWeight;
		}
	}
	
	if((pos == nPeople) && ((team1 == groupSize[0]) || (team1 == groupSize[1]) )){
		if(curWeight > bestAns){
			bestAns = curWeight;
		}
		return curWeight;
	}
	
	if(weight[pos] + curWeight > target){
		if( (team1 == groupSize[0]) || (team1 == groupSize[1])){  
			if(curWeight > bestAns) bestAns = curWeight;
			return curWeight;
		}
		else return 0;
	}
	
	team2 = nPeople - team1;
	nRemain = nPeople - pos;
	if(team1 + nRemain < groupSize[0]) return 0;
	if(team2 + nRemain < groupSize[0]) return 0;
	
	potential = (pos == 0)? sum : sum - prefixSum[pos-1];
	
	if(curWeight + potential <= bestAns) return curWeight;
	
	t2 = knapsack(pos + 1, team1 + 1, curWeight + weight[pos]);
	
	t1 = knapsack(pos + 1, team1, curWeight);
	
	if(t1 < t2) return t2;
	else return t1;
}

int main(){
	short nTest;
	short i, j;
	int ans;
	char first = 1;
		
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd", &nPeople);
		sum = 0;
		bestAns = 0;
		for(i=0; i<nPeople; i++){
			scanf("%hd", weight + i);
			sum += weight[i];
		}
		qsort(weight, nPeople, sizeof(short), compareShort);
		prefixSum[0] = weight[0];
		for(i=1; i<nPeople; i++){
			prefixSum[i] = prefixSum[i-1] + weight[i];
		}
		target = sum / 2;
		groupSize[0] = nPeople / 2;
		groupSize[1] = nPeople - groupSize[0];
		evenGroup = (groupSize[0] == groupSize[1])? 1 : 0;
		ans = knapsack(0, 0, 0);
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		printf("%d %d\n", ans, sum - ans);
	}
	return 0;
}
