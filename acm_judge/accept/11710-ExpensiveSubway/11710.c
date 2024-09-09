#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define CITY_NAME_LEN 11
#define MAX_CITY_NUM 401
#define INF 1000000000
#define DEBUG 0
#define QUEUE_SIZE 30000

struct Node {
	
	short neighbor[MAX_CITY_NUM];
	short nNeighbor;
	short parent;
};

int **dist;

void solve(struct Node node[MAX_CITY_NUM], int nNode, int startId){
	short i, cur, target;
	short *queue, head, tail;
	int max, sum;
	char *bInQueue;
	bInQueue = (char *) malloc(nNode);
	memset(bInQueue, 0, nNode);

	for(i=0; i<nNode; i++){
		dist[i][i] = INF;	
	}	
	dist[startId][startId] = 0;
	queue = (short *) malloc(sizeof(short)*QUEUE_SIZE);
	head = 0;
	tail = 1;
	sum = 0;
	queue[0] = startId;
	while(head != tail){
		cur = queue[head++];
		
		bInQueue[cur] = 0;
		for(i=0; i<node[cur].nNeighbor; i++){
			target = node[cur].neighbor[i];
			if(dist[cur][target] < dist[target][node[target].parent]){
				node[target].parent = cur;
				if(!bInQueue[target]){
					queue[tail++] = target;
					bInQueue[target] = 1;
				}
			}
		}
		
	}
	
	#if 0
	for(i=0; i<nNode; i++){
		printf("node %d: parent=%d, tree edge=%d\n", i, node[i].parent, dist[i][node[i].parent]);
	}
	#endif
	max = 0;
	sum = 0;
	for(i=0; i<nNode; i++){
		if((node[i].parent == i) && (i != startId)){
			max = INF;
		}
		sum += dist[i][node[i].parent];
	}
	
	if(max == INF){
		printf("Impossible\n");
	} else {
		printf("%d\n", sum);
	}
	free(bInQueue);
	free(queue);	
}



int main(){
	int nNode, nEdge, cost;
	int i, j, len, u, v;
	FILE *fp;
	struct Node node[MAX_CITY_NUM];
	ENTRY src, dest;
	ENTRY *cityEntry[MAX_CITY_NUM];
	ENTRY *retEntry;	
	
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	dist = (int **) malloc(sizeof(int *)*MAX_CITY_NUM);
	for(i=0; i<MAX_CITY_NUM; i++){
		dist[i] = (int *) malloc(sizeof(int) * MAX_CITY_NUM);
	}
	src.key = (char *) malloc(CITY_NAME_LEN);
	dest.key = (char *) malloc(CITY_NAME_LEN);

	while(2 == fscanf(fp, "%d %d", &nNode, &nEdge)){
		if( (nNode == 0) && (nEdge == 0) ) {
			break;
		}
		
		
		hcreate(MAX_CITY_NUM << 1);
		
		for(i=0; i<nNode; i++){
			cityEntry[i] = (ENTRY *) malloc(sizeof(ENTRY));
			cityEntry[i]->key = (char *) malloc(CITY_NAME_LEN);
			cityEntry[i]->data = (void *) i;
			node[i].nNeighbor = 0;
			node[i].parent = i; 
			fscanf(fp, "%s", cityEntry[i]->key);
			retEntry = hsearch(*cityEntry[i], ENTER);
			memset(dist[i], 0, nNode); 
			#if 0
			assert(retEntry != NULL);
			#endif
		}
		
		for(i=0; i<nEdge; i++){
			fscanf(fp, "%s %s %d", src.key, dest.key, &cost);
			retEntry = hsearch(src, FIND);
			u = (int) retEntry->data;
			retEntry = hsearch(dest, FIND);
			v = (int) retEntry->data;
			#if 0
			printf("%s(%d) -> %s(%d), cost= %d\n", src.key, u, dest.key, v, cost);
			#endif
			dist[u][v] = cost;
			dist[v][u] = cost;			
			node[u].neighbor[node[u].nNeighbor++] = v;
			node[v].neighbor[node[v].nNeighbor++] = u; 
		}
		fscanf(fp, "%s", src.key);
		solve(node, nNode, (int)src.data);

		#if 0		
		printf("start porint: %s (%d)\n", src.key, (int) src.data);
		#endif
		
		/*release memory*/
		for(i=0; i<nNode; i++){
			free(cityEntry[i]->key);
			free(cityEntry[i]);
		}
		hdestroy();
	}
	free(src.key);
	free(dest.key);
	for(i=0; i<MAX_CITY_NUM; i++){
		free(dist[i]);
	}
	free(dist);
	
	return 0;
}