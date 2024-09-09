#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024


int nRow, nCol;
int rStart, cStart, rEnd, cEnd;
int dist[MAX][MAX];
char mine[MAX][MAX];


int findAns(){
	char inQueue[nRow][nCol];
	int *queue, qSize=1024;
	int head, tail;
	int src, r, c, nr, nc;
	int i, j;
	memset(inQueue, 0, nRow*nCol);
	memset(dist, 0x7f, sizeof(int)*MAX*MAX);
	
	queue = (int *) malloc(sizeof(int)*qSize);
	
	src = rStart*MAX + cStart;
	dist[rStart][cStart] = 0;
	queue[0] = src;
	head = 0;
	tail = 1; 
	
	while(head < tail){
		src = queue[head++];
		r = src / MAX;
		c = src % MAX;
		inQueue[r][c] = 0;
		for(i=-1; i<=1; i++){
			for(j=-1; j<=1; j++){
				if (abs(i+j) != 1) continue;
				
				nr = r + i;
				nc = c + j;
				if((nr < 0) || (nr >= nRow) || (nc < 0) || (nc >= nCol) || (mine[nr][nc] == 1)){
					continue;
				} 
				
				if(dist[r][c] + 1 < dist[nr][nc]){
					dist[nr][nc] = dist[r][c] + 1;
					if(inQueue[nr][nc] == 0){
						queue[tail++] = nr*MAX + nc;
						inQueue[nr][nc] = 1;
						if(tail == qSize){
							qSize = qSize*2;
							queue = (int *) realloc(queue, sizeof(int)*qSize);
						}
					}					
				}
			}
		}
	}
	free(queue);
	return dist[rEnd][cEnd];
}

int main(){
	int i, j, nMineRow, nMine, row, col;
	int ans;
	while(2 == scanf("%d %d",&nRow, &nCol)){
		if( (0 == nRow) && (0 == nCol)) break;
		scanf("%d",&nMineRow);
		memset(mine, 0, MAX*MAX);
		for(i=0; i<nMineRow; i++){
			scanf("%d %d", &row, &nMine);
			for(j=0; j<nMine; j++){
				scanf("%d", &col);
				mine[row][col] = 1;
			}
		}
		scanf("%d %d",&rStart, &cStart);
		scanf("%d %d",&rEnd, &cEnd);
		ans = findAns();
		printf("%d\n",ans);
	}
	return 0;
}