#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50002
#define NEIGHBOR_NUM 8
#define WHITE 0
#define BLACK 1

struct Vertex {
	int nNeighbor;
	int maxNeighbor;
	int *neighbor;
	int color;
};

void addNeighbor(struct Vertex *vertex, int u, int v){
	if(vertex[u].nNeighbor == vertex[u].maxNeighbor){
		vertex[u].maxNeighbor <<= 1;
		vertex[u].neighbor = (int *) realloc(vertex[u].neighbor, sizeof(int)*vertex[u].maxNeighbor);
	}
	vertex[u].neighbor[vertex[u].nNeighbor] = v;
	vertex[u].nNeighbor++;
}

void BFS(struct Vertex *vertex, int n, int root){
	int head, tail, target, cur;
	int *queue;
	char *isInQueue;
	int i;
	
	target = n + 1;
	queue = (int *) malloc(sizeof(int)*target);
	isInQueue = (char *) malloc(target);
	memset(isInQueue, 0, target);
	
	head = 0;
	tail = 1;
	queue[0] = root;
	isInQueue[root] = 1;
	
	while(head < tail){
		cur = queue[head++];
		vertex[cur].color = BLACK;
		for(i=0; i<vertex[cur].nNeighbor; i++){
			target = vertex[cur].neighbor[i];
			if(isInQueue[target] == 0){
				isInQueue[target] = 1;
				queue[tail++] = target;
			}
		}
	}
	
	
	free(queue);
	free(isInQueue);
}

int solve(struct Vertex *vertex, int n){
	int result = 0;
	int i;
	for(i=1; i<=n; i++){
		if(vertex[i].color == WHITE){
			result++;
			BFS(vertex, n, i);
		}
	}
	return result;
}

int main(){
	struct Vertex *vertex;
	int n, m, i, ans, k=1;
	int u, v;
	FILE *fp = stdin;
	
	vertex = (struct Vertex *) malloc(sizeof(struct Vertex)*MAX);
	while(2 == fscanf(fp, "%d %d", &n, &m)){
		if((n == 0) && (m == 0)) break;

		for(i=1; i<=n; i++){
			vertex[i].maxNeighbor = NEIGHBOR_NUM;
			vertex[i].nNeighbor = 0;
			vertex[i].color = WHITE;
			vertex[i].neighbor = (int *) malloc(sizeof(int)*NEIGHBOR_NUM);
		}
		
		for(i=1; i<=m; i++){
			fscanf(fp, "%d %d", &u, &v);
			addNeighbor(vertex, u, v);
			addNeighbor(vertex, v, u);
		}

		ans = solve(vertex, n);
		printf("Case %d: %d\n", k++, ans);
		
		for(i=1; i<=n; i++){
			free(vertex[i].neighbor);
		}
	}
	
	free(vertex);
	return 0;
}