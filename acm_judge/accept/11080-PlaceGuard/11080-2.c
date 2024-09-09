#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 201
#define DEBUG 0
#define UNCOLORED 2
#define BLACK 0
#define WHITE 1
#define MIN(a, b) (((a) < (b))? (a) : (b))

const maxSquare = MAX*MAX;

struct Graph{
	short nV, nE, nBlack;	
	unsigned char edge[MAX][MAX];
	unsigned char vDegree[MAX];
	unsigned char vNeighbor[MAX][MAX];
	char vColor[MAX];
};

void initGraph(struct Graph *g){
	short i;
	memset(g->edge, 0, maxSquare);
	memset(g->vDegree, 0, MAX);
	memset(g->vNeighbor, 0, maxSquare);
	for(i=0; i<g->nV; ++i){
		g->vColor[i] = UNCOLORED;
	}
}

void findNeighbor(struct Graph *g){
	short u, v;
	for(u=0; u < g->nV; ++u){
		for(v=0; v<g->nV; ++v){	
			if(g->edge[u][v] > 0){
				g->vNeighbor[u][g->vDegree[u]] = v;
				g->vDegree[u] += 1;
			}
		}
	}
}

short bwColor(struct Graph *g){
	unsigned char queue[MAX];
	unsigned char head = 0, tail = 1;
	unsigned char i, j, cur, target;
	short ans = 0, less, nBlack, nWhite;
	
	
	for(i=0; i<g->nV; ++i){
		if(g->vColor[i] != UNCOLORED) continue;
		
		if(g->vDegree[i] == 0) {
			ans += 1;
			continue;
		}
		
		/*BFS search*/
		head = 0;
		tail = 1;
		queue[0] = i;
		nBlack = 0;
		nWhite = 1;
		g->vColor[i] = WHITE;
		while(head < tail){
			cur = queue[head++];
			for(j=0; j<g->vDegree[cur]; ++j){
				target = g->vNeighbor[cur][j];
				if(
					(g->vColor[target] != UNCOLORED) && 
					(g->vColor[target] == g->vColor[cur])
					){ 
					return -1;
				}
				if(g->vColor[target] == UNCOLORED){
					queue[tail++] = target;
					g->vColor[target] = 1 - g->vColor[cur];
					if(g->vColor[target] == BLACK){
						nBlack += 1;
					} 	else {
						nWhite += 1;
					}
				}
			}
		}
		less = MIN(nBlack, nWhite);
		ans += less;
	}
	return ans;
}

int main(){
	char nCase;
	short u, v, i;
	
	struct Graph g;
	FILE *fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	short ans;
	fscanf(fp, "%hhd", &nCase);
	while(nCase > 0){
	#if DEBUG
		
		printf("Case %hhd\n", nCase);
	#endif 
		--nCase;
		fscanf(fp, "%hd %hd", &g.nV, &g.nE);
		initGraph(&g);
		
		for(i=0; i<g.nE; ++i){
			fscanf(fp, "%hd %hd", &u, &v);
			
			g.edge[u][v] = 1;
			g.edge[v][u] = 1;
			
		}
		findNeighbor(&g);
		ans = bwColor(&g);
		
		printf("%hhd\n", ans);
		
		
	}
	return 0;
}
