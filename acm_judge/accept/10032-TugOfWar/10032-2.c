#include <stdio.h>
#include <string.h>
#define MAX 22501
#define PEOPLE 101

int dp[PEOPLE][MAX];
short weight[PEOPLE];
short nPeople;
int sum, capacity;

int fillTable(int i, int capacity){
	int j, k;
	int max = 0;
	if(i == -1) return 0; 
	
	if(dp(i-1, capacity - 
	
}

int main(){
	short nTest;
	int i, j;
	int ans;
	char first = 1;
		
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		memset(dp, 0xff, sizeof(int)*PEOPLE*MAX);
		scanf("%hd", &nPeople);
		sum = 0;
		for(i=0; i<nPeople; i++){
			scanf("%hd", weight + i);
			sum += weight[i];
		}

		capacity = sum / 2;
		ans = fillTable(nPeople - 1, capacity);
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
