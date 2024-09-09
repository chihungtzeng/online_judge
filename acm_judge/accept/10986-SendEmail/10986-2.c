#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINT 2000000000
#define MAXN 20001
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


struct PriorityQueue{
	void **qelem;
	int length;
	int capacity;
};

void heapify(struct PriorityQueue *q, int i, int (*compr)(const void *, const void *)){
	int left, right, largest;
	void *tmp;
	
	if(q == NULL){
		printf("queue is null when calling heapify at %d\n",i);
		return ;
	}
	left = i*2 + 1;
	right = (i + 1)*2;
	if ((left < q->length) && (compr(q->qelem[left], q->qelem[i]) > 0)){
		largest = left;
	} 
	else {
		largest = i;
	}
	if ((right < q->length) && (compr(q->qelem[right], q->qelem[largest]) > 0)){
		largest = right;
	}
	if (largest != i){
		tmp = q->qelem[i];
		q->qelem[i] = q->qelem[largest];
		q->qelem[largest] = tmp;
		heapify(q, largest, compr);
	}
	return ;
}

struct PriorityQueue *newPriorityQueue(){
	struct PriorityQueue *pq;
	
	pq = NULL;
	pq = (struct PriorityQueue *) malloc(sizeof(struct PriorityQueue));
	if(pq == NULL){
		printf("cannot new a priority queue!\n");
		return NULL;
	}
	pq->length = 0;
	pq->capacity = 8;
	pq->qelem = (void **) malloc(sizeof(void *) * pq->capacity);
	return pq;
}

int queueAdd(void *key, struct PriorityQueue *q, int (*compr)(const void *, const void *)){
	int parent, left, right;
	int cur;
	if((key == NULL) || (q == NULL)){
		printf("either queue or key is null\n");
		return EXIT_FAILURE;
	}
	if(q->length == q->capacity){
		int newCapacity;
		void **backupPointer;
		if(q->capacity > 10000){
			newCapacity = q->capacity + 10000;
		}
		else{
			newCapacity = q->capacity << 1;
		}
		backupPointer = q->qelem;
		q->qelem = (void **) realloc(q->qelem, sizeof(void *) * newCapacity);
		if(q->qelem == NULL){
			printf("request for alloc priority queue failed\n");
			q->qelem = backupPointer;
			return EXIT_FAILURE;
		}
		else{
			q->capacity = newCapacity;
		}
	}
	cur = q->length;
	parent = (cur - 1)/2;
	while((cur > 0) && (compr(q->qelem[parent], key) < 0)){
		q->qelem[cur] = q->qelem[parent];
		cur = parent;
		parent = (cur - 1)/2;
	}
	q->qelem[cur] = key;
	q->length += 1;
	return EXIT_SUCCESS;
}

void *queueExtract(struct PriorityQueue *q, int (*compr)(const void *, const void *)){
	void *extreme;
	if(q->length == 0){
		printf("priority queue underflow\n");
		return NULL;
	}
	extreme = q->qelem[0];
	q->length -= 1;
	q->qelem[0] = q->qelem[q->length];
	q->qelem[q->length]  = NULL;
	heapify(q, 0, compr);
	return extreme;
}

void queueDestroy(struct PriorityQueue *q){
	int i;
	for(i=0; i < q->length; i++){
		if(q->qelem[i] != NULL){
			free(q->qelem[i]);
		}
	}
	free(q->qelem);
	free(q);
}

int queueHasElement(struct PriorityQueue *q){
	if(q == NULL){
		printf("the priority points to null\n");
		return 0;
	}
	return q->length;
}

int compareVertex(const void *a, const void *b){
	struct vertex *u, *v;
	u = (struct vertex *)a;
	v = (struct vertex *)b;
	if(v->dist != u->dist) return v->dist - u->dist;
	else return  v->id - u->id;
}


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

void printVertex(struct vertex *V[], int nV){
	int i,j;
	int u, v;
	for(i=0; i<nV; i++){
		printf("vertex %d: degree: %d, neighbors:", i, V[i]->degree);
		for(j = 0; j<V[i]->degree; j++){
			printf("%d(%d) ", V[i]->edgeSet[j].vid, V[i]->edgeSet[j].weight);
		}
		printf("dist: %d\n",V[i]->dist);
	}
}


int findDist(struct vertex *V[], int nV, int start, int end){
	int src, target, weight, i;
	struct PriorityQueue *q;
	struct vertex *u, *v;

	
	q = newPriorityQueue();
	V[start]->dist = 0;
	queueAdd((void *) V[start], q, compareVertex);
	
	while(queueHasElement(q)){
		u = (struct vertex *) queueExtract(q, compareVertex);
		for(i=0; i < u->degree; i++){
			target = u->edgeSet[i].vid;
			weight = u->edgeSet[i].weight;
			if(u->dist + weight < V[target]->dist){
				
				V[target]->dist = u->dist + weight;
				queueAdd((void *) V[target], q, compareVertex);
			}
		}
	}
	queueDestroy(q);
	return V[end]->dist;
}

int main(){
	struct vertex *V[MAXN];
	int start, end;
	int nV, nE, i;
	int u, v, weight;
	int nTest, k = 1;
	int ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in4.txt","r") : stdin;	
	
	fscanf(fp, "%d", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%d %d %d %d", &nV, &nE, &start, &end);
		for(i=0; i<nV; i++){
			V[i] = newVertex(i);
		}
		for(i=0; i<nE; i++){
			fscanf(fp, "%d %d %d", &u, &v, &weight);
			if(DEBUG){
				printf("read edge (%d, %d) = %d\n", u, v, weight);
			}
			addNeighbor(V[u], v, weight);
			addNeighbor(V[v], u, weight);
		}
		if(DEBUG){
			printVertex(V, nV);
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