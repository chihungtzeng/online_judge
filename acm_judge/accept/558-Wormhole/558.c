#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX 1001


struct Vertex{
	short degree;
	short neighbor[MAX];
};

struct Vertex *newVertex(){
	struct Vertex *v;
	v = (struct Vertex *) malloc(sizeof(struct Vertex));
	v->degree = 0;
	return v;
}

struct Vertex *V[MAX];
short dist[MAX][MAX];
short nRow, nV, nWormhold;

void addNeighbor(struct Vertex *v, short u){
	assert(v != NULL);
	
	v->neighbor[v->degree++] = u;
}

int hasNegativeCycle(){
	char color[nRow];
	
	short queue[MAX], head, tail;
	int DFSdepth[nRow];
	int i, j, src, target, cur;
	int rTarget, cTarget, rCur, cCur; 
		
	/*for(src=0; src<nRow; src++){*/
		/*DFS, the start must be from 0*/
		
		memset(color, 0, nRow);
		memset(DFSdepth, 0, sizeof(int)*nRow);
		queue[0] = 0;
		DFSdepth[0] = 0;
		color[0] = 1;
		head = 0;
		tail = 1;
		while(head < tail){
			cur = queue[head++];
			for(i=0; i<V[cur]->degree; i++){
				target = V[cur]->neighbor[i];
				if(color[target] == 0){
					color[target] = 1;
					queue[tail++] = target;
					DFSdepth[target] = DFSdepth[cur] + dist[cur][target];
				}
				else{
					if(DFSdepth[cur] - DFSdepth[target] + dist[cur][target] < 0){
					
						return 1;
					}
				}
			}
		} 
	/*}*/
	return 0;
}

int main(){
	short nTest;
	
	short i, j, u, v, t;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;	
		memset(dist, 0, sizeof(short)*MAX*MAX);
		
		scanf("%hd %hd", &nRow, &nWormhold);
		nV = nRow * nRow;
		for(i=nRow - 1; i>=0; i--){
			V[i] = newVertex();
		}
		for(i=0; i<nWormhold; i++){
			scanf("%hd %hd %hd", &u, &v, &t);
			addNeighbor(V[u], v);
			dist[u][v] = t;
		}
		if(hasNegativeCycle()){
			puts("possible");
		}
		else{
			puts("not possible");
		}
		for(i=0; i<nRow; i++){
			free(V[i]);
		}
	}
	return 0;
}