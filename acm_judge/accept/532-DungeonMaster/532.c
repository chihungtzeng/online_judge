#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#define INF 0x7f7f7f7f
#define DEBUG 0

char map[MAX][MAX][MAX];
char L, R, C;
char neighbor[6][3] = {
	{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}
};

int findRoute(){
	int dist[MAX][MAX][MAX];
	char visit[MAX][MAX][MAX];
	short queue[L*R*C];
	short qhead, qtail;
	short src, target;
	char lSrc, rSrc, cSrc, rTarget, cTarget, lTarget;
	short i,j,k;
	short start, end;
	
	memset(dist, 0x7f, sizeof(int)*MAX*MAX*MAX);
	memset(visit, 0, sizeof(char)*MAX*MAX*MAX);
	
	for(i=0; i<L; i++){
		for(j=0; j<R; j++){
			for(k=0; k<C; k++){
				if(map[i][j][k] == 'S'){
					start = (i << 10) + (j<<5) + k;
					visit[i][j][k] = 1; 
					dist[i][j][k] = 0;
				}
				else if(map[i][j][k] == 'E'){
					end = (i << 10) + (j<<5) + k; 
				}
			}
		}
	}
	
	
	qhead = 0;
	queue[0] = start;
	qtail = 1;
	while(qhead < qtail){
		src = queue[qhead++];
		lSrc = src >> 10;
		rSrc = (src >> 5) & 0x1f;
		cSrc = src & 0x1f; 
		for(i=0; i<=6; i++){
			lTarget = lSrc + neighbor[i][0];
			rTarget = rSrc + neighbor[i][1];
			cTarget = cSrc + neighbor[i][2];
			if( (lTarget < 0) || (lTarget >= L) || 
				(rTarget < 0) || (rTarget >= R) || 
				(cTarget < 0) || (cTarget >= C)){
				continue;
			}
			if((visit[lTarget][rTarget][cTarget] == 0) && 
				(map[lTarget][rTarget][cTarget] != '#') &&
				(dist[lTarget][rTarget][cTarget] > dist[lSrc][rSrc][cSrc] + 1)
				){
				target = (lTarget << 10) + (rTarget << 5) + cTarget;
				visit[lTarget][rTarget][cTarget] = 1;
				queue[qtail++] = target;
				dist[lTarget][rTarget][cTarget] = dist[lSrc][rSrc][cSrc] + 1;
			}
		}
	} 
	i = end >> 10;
	j = (end >> 5) & 0x1f;
	k = end & 0x1f;
	return dist[i][j][k];
}

int main(){
	char line[MAX];
	char i, j, k;
	int ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	while(3 == fscanf(fp, "%hhd %hhd %hhd", &L, &R, &C)){
		if( (L == 0) && (R == 0) && (C == 0)) return 0;
		for(i=0; i<L; i++){
			for(j=0; j<R; j++){
				fscanf(fp, "%s",map[i][j]);
			}
		}
		ans = findRoute();
		if(ans != INF){
			printf("Escaped in %d minute(s).\n",ans);
		}
		else{
			puts("Trapped!");
		}
	}
	return 0;
}
