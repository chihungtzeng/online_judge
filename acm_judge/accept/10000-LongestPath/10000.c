#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

struct vertex{
	int id;
	int nNeighbor;
	int neighbor[MAX];
};

int nV, start, end;
struct vertex *V;

int findLongestPath(){
	short indegree[MAX], length[MAX];
	short color[MAX];
	short i, j;
	short queue[MAX], head, tail;
	short src, target;
	short curlength;
	
	memset(indegree, 0, sizeof(short)*MAX);
	memset(color, 0, sizeof(short)*MAX);
	memset(length, 0, sizeof(short)*MAX);
	
	queue[0] = start;
	head = 0;
	tail = 1;	
	
	while(head < tail){
		src = queue[head++];
		for(j=0; j<V[src].nNeighbor; j++){
			target = V[src].neighbor[j];
			indegree[target] += 1;
			if(color[target] == 0){
				color[target] = 1;
				queue[tail++] = target;
			}
		}
	}
	
	
	queue[0] = start;
	head = 0;
	tail = 1;	
	
	while(head < tail){
		src = queue[head++];
		for(j=0; j<V[src].nNeighbor; j++){
			target = V[src].neighbor[j];
			indegree[target] -= 1;
			if(indegree[target] == 0){
				length[target] = length[src] + 1;
				queue[tail++] = target; 
			}
		}
	}
	
	curlength = 0;
	for(i=1; i<=nV; i++){
		if(length[i] > curlength){
			curlength = length[i];
			end = i;
		}
	}	
	
	return curlength;
}

int main(){
	int i, lp, kcase=1;

	
	V = (struct vertex *) malloc(sizeof(struct vertex)*MAX);
	for(i=0; i<	MAX; i++){
		V[i].id = i;
	}
	
	while(1){
		int u, v;
		scanf("%d", &nV);
		if(0 == nV){
			break;
		}
		for(i=0; i<nV; i++){
			V[i].nNeighbor = 0;
		}
		scanf("%d", &start);
		u = 1;
		while( !((u == 0) && (v == 0))){
			scanf("%d %d", &u, &v);
			V[u].neighbor[V[u].nNeighbor++] = v;
		}
		lp = findLongestPath();
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",kcase, start, lp, end);
		kcase++;
	}
	free(V);
	return 0;	
}