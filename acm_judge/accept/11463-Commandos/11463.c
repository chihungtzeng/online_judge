#include <stdio.h>
#define N 101
#define INF 0x7fff




void initDist(char n, short dist[N][N]){
	char i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			dist[i][j] = (i == j)? 0 : INF;
		}
	}
}

void allPairShortestPath(char nCity, short dist[N][N]){
	char x, y, z;
	short backup[N][N];
	for(x = 0; x<nCity; x++){
		for(y=0; y<nCity; y++){
			for(z=0; z<nCity; z++){
				backup[y][z] = dist[y][z];
			}
		}		
		
		for(y=0; y<nCity; y++){
			for(z = 0; z<nCity; z++){
				dist[y][z] = (backup[y][z] < backup[y][x] + backup[x][z])?
					backup[y][z] : backup[y][x] + backup[x][z];
			}
		}
	}
}

int main(){
	short i, j;
	char u, v, src, dest;
	short nTest, k = 1;
	FILE *fp = stdin;
	char nCity;
	short nRoad;
	short dist[N][N];
	int ans, criticalPath;	
	
	fscanf(fp, "%hd", &nTest);
	while(nTest > 0){
		nTest--;
		
		fscanf(fp, "%hhd %hd", &nCity, &nRoad);
		initDist(nCity, dist);
		for(i=0; i<nRoad; i++){
			fscanf(fp, "%hhd %hhd", &u, &v);
			dist[u][v] = 1;
			dist[v][u] = 1;
		}
		fscanf(fp, "%hhd %hhd", &src, &dest);
		allPairShortestPath(nCity, dist);
		ans = 0;
		for(u=0; u<nCity; u++){
			criticalPath = dist[src][u] + dist[u][dest];
			if(criticalPath > ans){
				ans = criticalPath;
			}
		}	
		printf("Case %hd: %d\n", k++, ans);
	}
	return 0;
}