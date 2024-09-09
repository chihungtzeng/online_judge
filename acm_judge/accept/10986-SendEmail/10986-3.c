#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINT 2000000000
#define MAXN 30001
#define QSIZE 500000
#define DEBUG 0

struct edge{
	int vid;
	int weight;
};

struct vertex{
	int id;
	int degree;
	struct edge *edgeSet;
	int nEdgeLimit;
	int dist;
};

struct vertex *newVertex(int id){
	struct vertex *v;
	v = (struct vertex *) malloc(sizeof(struct vertex));
	v->id = id;
	v->degree = 0;
	v->nEdgeLimit = 10;
	v->edgeSet = (struct edge *) malloc(sizeof(struct edge)*10);
	v->dist = MAXINT;
	return v;
}

int addNeighbor(struct vertex *v, int nbr, int edgeWeight){
	struct edge *backup, *newaddr;
	struct edge *vneighbor;
	if(v->degree == v->nEdgeLimit){
		v->nEdgeLimit = v->nEdgeLimit * 2;
		backup = v->edgeSet;
		v->edgeSet = (struct edge *) realloc(v->edgeSet, sizeof(struct edge)*v->nEdgeLimit);
		if (v->edgeSet == backup){
			if(DEBUG){
				printf("realloc memeory failed when adding an edge (%d, %d) with weight %d\n", v->id, nbr, edgeWeight);
			}
			return EXIT_FAILURE;
		}
	}
	vneighbor = v->edgeSet;
	vneighbor[v->degree].vid = nbr;
	vneighbor[v->degree].weight = edgeWeight;
	v->degree += 1;
	return EXIT_SUCCESS;
} 

int findDist(struct vertex *V[], int nV, int start, int end){
	int src, target, weight;
	int i, j;
	int queue[QSIZE], head, tail;
	char flag[MAXN];
	
	memset(flag, 0, sizeof(char)*MAXN);
	V[start]->dist = 0;
	flag[start] = 1;
	queue[0] = start;
	head = 0;
	tail = 1;
	
	while(head < tail){
		src = queue[head];
		head++;
		flag[src] = 0;
		for(i=0; i<V[src]->degree; i++){
			target = V[src]->edgeSet[i].vid;
			weight = V[src]->edgeSet[i].weight;
			if(V[src]->dist + weight < V[target]->dist){
				V[target]->dist = V[src]->dist + weight;
				if(flag[target] == 0){
					flag[target] = 1;
					queue[tail] = target;
					tail++;
				}
			}
		}
	}
	
	return V[end]->dist;
}

int main(){
	struct vertex *V[MAXN];
	int start, end;
	int nV, nE, i;
	int u, v, weight;
	int nTest, k = 1;
	int ans;
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d %d %d", &nV, &nE, &start, &end);
		for(i=0; i<nV; i++){
			V[i] = newVertex(i);
		}
		for(i=0; i<nE; i++){
			scanf("%d %d %d", &u, &v, &weight);
			if(DEBUG){
				printf("read edge (%d, %d) = %hd\n", u, v, weight);
			}
			addNeighbor(V[u], v, weight);
			addNeighbor(V[v], u, weight);
		}

		if(start != end){
			ans = findDist(V, nV, start, end);
		}
		else {
			ans = 0;
		}
		
		if(ans == MAXINT){
			printf("Case #%d: unreachable\n",k);
		}
		else {
			printf("Case #%d: %d\n",k, ans);
		}
		k++;
		for(i=0; i<nV; i++){
			free(V[i]->edgeSet);
			free(V[i]);
		}
	}
	return 0;
}