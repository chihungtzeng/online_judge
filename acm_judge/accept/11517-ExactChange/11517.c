#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

char count[MAX], flag[MAX];
short money[101];
int ans;
int nCoin;
int price, n;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

void findAns(){
	char dist[MAX];
	int i, j, target;
	memset(dist, 127, MAX);
	dist[0] = 0;
	for(i=0; i<n; i++){
		for(j=MAX-1; j>=0; j--){
			target = j + money[i];
			if(target >= MAX) continue;
			if( (dist[j] != 127) && (dist[j] + 1 < dist[target]) ){
				dist[target] = dist[j] + 1;
			}
		}
	}
	for(j=price; j<MAX; j++){
		if(dist[j] != 127) {
			ans = j;
			nCoin = dist[j];
			return ;
		}
	}
}

int main(){
	
	short nTest;
	int i, target;
	
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&price, &n);
		for(i=0; i<n; i++){
			scanf("%hd", money + i);
		}
		findAns();		
		printf("%d %d\n", ans, nCoin); 
	}
	return 0;
}