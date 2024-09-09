#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 201
#define DEBUG 1
#define OPEN 0
#define BAR -1
#define GUARD 1

struct Graph{
	short nV, nE;
	unsigned char *vNeighbor[MAX];
	unsigned char vDegree[MAX];
	char vState[MAX];
	char nGuard;
};

void addEdge(struct Graph *g, short u, short v){
	short i;
	typeof(g->vNeighbor[u][0]) *list = g->vNeighbor[u];
	for(i=0; i < g->vDegree[u]; ++i){
		if(list[i] == v){
			#if DEBUG
				printf("vertex %hd already has a neighbor %hd\n", u, v);
			#endif
			return;
		}
	}
	list[g->vDegree[u]++] = v;	
	return ;
}

#if 0
void removeEdge(struct Graph *g, short u, short v){
	/*remove edge from u to v*/
	short i;
	short *list = g->vNeighbor[u];
	for(i=0; i<g->vDegree[u]; ++i){
		if(list[i] == v){
			list[i] = list[g->vDegree[u] - 1];
			g->vDegree[u] -= 1;
			return ;
		}
	}
}
#endif

void *copyGraph(struct Graph *target, struct Graph *src){
	short i;
	
	memcpy(target, src, sizeof(struct Graph));
	for(i=0; i<src->nV; ++i){
		target->vNeighbor[i] = 
			malloc(sizeof(typeof(src->vNeighbor[i][0]))*src->vDegree[i]);
		memcpy(target->vNeighbor, 
			src->vNeighbor, 
			sizeof(typeof(src->vNeighbor[i][0]))*src->vDegree[i]
			);
	} 
}

void freeGraph(struct Graph *g){
	short i;
	for(i=0; i<g->nV; i++){
		free(g->vNeighbor[i]);
	}
}

void findDominatingSet(struct Graph *g){

	short nGuard = 0, i;
	short targetVertex = -1;
	struct Graph *gCopy;

	/*
		find the first vertex u such that u is OPEN 
	*/
	for(i=0; i<g->nV; i++){
		if(g->vState[i] == OPEN){
			targetVertex = i;
			break;
		}
	}
	if(targetVertex == -1) return ;
	/*
		set 
	*/
	gCopy = (struct Graph *) malloc(sizeof(struct Graph));
	
	
	
	
}

int main(){
	char nCase;
	short u, v, i;
	char nGuard;
	struct Graph g;
	size_t msize;
	FILE *fp = stdin;
	fscanf(fp, "%hhd", &nCase);
	while(nCase > 0){
	#if DEBUG
		printf("Case %hhd\n", nCase);
	#endif 
		--nCase;
		fscanf(fp, "%hd %hd", &g.nV, &g.nE);
		msize = sizeof(unsigned char)*g.nV;
		for(i=0; i<g.nV; ++i){
			g.vNeighbor[i] = (unsigned char *) malloc(msize);
			g.vDegree[i] = 0; 
			g.vState[i] = OPEN;
		}
		g.nGuard = 0;
		for(i=0; i<g.nE; ++i){
			fscanf(fp, "%hd %hd", &u, &v);
			addEdge(&g, u, v);
			addEdge(&g, v, u);
		}
		
		findDominatingSet(&g);
		printf("%hhd\n", nGuard);
		
		for(i=0; i<g.nV; ++i){
			free(g.vNeighbor[i]);
		}
	}
	return 0;
}