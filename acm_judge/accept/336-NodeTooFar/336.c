#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <search.h>
#define MAX 32
#define WHITE 0
#define BLACK 1
#define DEBUG 0
#define INF 0x7fff

struct Node {
	int id;
	int *neighbor;
	int nNeighbor;
	int nNeighborLimit;
	int dist;
	int color;
};


int compareNode(const void *a, const void *b){
	struct Node *x, *y;
	x = (struct Node *)a;
	y = (struct Node *)b;
	return x->id - y->id;
}

struct Node *newNode(int id){
	struct Node *pNode;
	pNode = (struct Node *) malloc(sizeof(struct Node));
	pNode->nNeighborLimit = 8;
	pNode->nNeighbor = 0; 
	pNode->id = id;
	pNode->neighbor = (int *) malloc(sizeof(int)*pNode->nNeighborLimit);
	return pNode;
}

void freeNode(struct Node **ppNode){
	if(*ppNode == NULL) return ;
	free( (*ppNode)->neighbor);
	free(*ppNode);
	*ppNode = NULL;
}

void addNeighbor(struct Node *pNode, int neighborId){
	if(NULL == pNode) return;
	if(pNode->nNeighborLimit == pNode->nNeighbor){
		pNode->nNeighborLimit <<= 1;
		pNode->neighbor = (int *) realloc(pNode->neighbor, sizeof(int)*pNode->nNeighborLimit);
	}
	pNode->neighbor[pNode->nNeighbor] = neighborId;
	pNode->nNeighbor += 1;
}

int nEdge, nNode;
struct Node *nodeArray[MAX];

/*nVisit = BFS(nodeArray, nNode, nodeId[0], ttl);*/
int BFS(void **ppRoot, int nNode, int startNodeId, int ttl){
	int nVisit = 0;
	int head, tail;
	int cur;
	char *color;
	int i, targetId;
	struct Node *targetNode, *queryNode;
	void *match;
	struct Node *queue[10000];
	struct Node *curNode;
	
	
	for(i=0; i<nNode; i++){
		nodeArray[i]->color = WHITE;
		nodeArray[i]->dist = INF;
	}
	
	queryNode = newNode(startNodeId);	
	match = (void *)tfind(queryNode, ppRoot, compareNode);
	
	if(!match) return nNode;
	targetNode = *(struct Node **) match;

	queue[0] = targetNode;
	targetNode->color = BLACK;
	targetNode->dist = 0;
	
	head = 0;
	tail = 1;
	while(head < tail){
		curNode = queue[head++];
		for(i=0; i < curNode->nNeighbor; i++){
			queryNode->id = curNode->neighbor[i];		
			match = (void *) tfind(queryNode, ppRoot, compareNode);
			if(NULL == match){
				continue;
			}
			targetNode = *(struct Node **) match;
			
			if(targetNode->color == WHITE){
				targetNode->color = BLACK;
				targetNode->dist = curNode->dist + 1;
				queue[tail++] = targetNode;
			}
		}
	}

	#if 0
	for(i=0; i<nNode; i++){
		targetId = nodeArray[i]->arrayIndex;
		printf("node %d with dist %d\n", nodeArray[i]->id, dist[targetId]);
	}
	for(i=0; i<nNode; i++){
		printf("node %d has dist=%d\n", nodeArray[i]->id, nodeArray[i]->dist);
	}
	#endif

	nVisit = 0;
	for(i=0; i<nNode; i++){
		if(nodeArray[i]->dist <= ttl){
			nVisit++;
		}
	}
	
	

	return nVisit;
}

int main(){
	int nodeId[2], i, j, ttl, k=1, nVisit;
	void *root, *match;
	FILE *fp;
	struct Node *pNode[2];
	
	root = NULL;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	while(1 == fscanf(fp, "%d", &nEdge)){
		if(nEdge == 0){
			break;
		}
		nNode = 0;
		/*read edges*/
		for(i=0; i<nEdge; i++){
			fscanf(fp, "%d %d", &nodeId[0], &nodeId[1]);

			for(j=0; j<2; j++){
				pNode[j] = newNode(nodeId[j]);
				match = (void *) tsearch(pNode[j], &root, compareNode);
				if(*(struct Node **)match == pNode[j]){
					nodeArray[nNode] = pNode[j];
					nNode++;		
				} else {
					free(pNode[j]);
					pNode[j] = *(struct Node **)match;
				}
			}
			/*add edge*/
			addNeighbor(pNode[0], nodeId[1]);
			addNeighbor(pNode[1], nodeId[0]);
			
		}
		
		#if 0
		printf("***nNode=%d\n", nNode);
		for(i=0; i<nNode; i++){
			printf("node[%d]: id=%d,", i, nodeArray[i]->id);
			for(j=0; j<nodeArray[i]->nNeighbor; j++){
				printf(" %d", nodeArray[i]->neighbor[j]);
			}
			printf("\n");
		}
		#endif
		/*handle queries*/
		while(2 == fscanf(fp, "%d %d", &nodeId[0], &ttl)){
			if( (nodeId[0] == 0) && (ttl == 0)) {
				break;
			}
			
			nVisit = BFS(&root, nNode, nodeId[0], ttl);
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", 
				k++, nNode - nVisit, nodeId[0], ttl); 
		}
		/*root does not need to be freed*/
		
		for(i=0; i<nNode; i++){
			freeNode(&nodeArray[i]);
		}
		root = NULL;
	}
	return 0;
}