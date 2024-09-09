#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 0x0f0f0f0f

int dist[MAX][MAX];
int n, m;

void printDist(){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
}

void FloydWarshall(){
	int i, j, k;
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
}

int findAns(){
	int i, j;
	int ans;
	int candidate[MAX], nCandidate=0;
	int src, target;
	int maxDist;
	char equalLength;
	
	for(i=6; i<=n; i++){
		equalLength = 1;
		for(j=1; (j<=4) && equalLength; j++){
			if(dist[i][j] != dist[i][j+1]) equalLength = 0;
		}
		if(equalLength){
			candidate[nCandidate++] = i;
		}
	}
	if(nCandidate == 0){
		return -1;
	}
	
	ans = INF;
	for(i=0; i<nCandidate; i++){
		src = candidate[i];
		maxDist = 0;
		for(j=1; j<=n; j++){
			if(dist[src][j] > maxDist){
				maxDist = dist[src][j];
			}
		}
		if(maxDist < ans){
			ans = maxDist;
		}
	}
	
	if(ans == INF) return -1;
	else return ans;
}

int main(){
	short nTest, k = 1;
	scanf("%hd", &nTest);
	int i, u, v, cost;
	int ans;
	
	while(k <= nTest){
		memset(dist, 0x0f, sizeof(int)*MAX*MAX);
		scanf("%d %d",&n, &m);
		for(i=n; i>=1; i--){
			dist[i][i] = 0;
		}
		for(i=m; i>=1; i--){
			scanf("%d %d %d", &u, &v, &cost);
			if(dist[u][v] > cost){
				dist[u][v] = cost;
				dist[v][u] = cost;
			}
		}
		
		FloydWarshall();
		
		ans = findAns();
		printf("Map %hd: %d\n",k++,ans);
	}
	return 0;
}