#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 128
#define DEBUG 0

struct PriorityQueue{
	void **qelem;
	int length;
	int capacity;
};

int heapify(struct PriorityQueue *q, int i, int (*compr)()){
	int left, right, largest;
	void *tmp;
	
	if(q == NULL){
		printf("queue is null when calling heapify at %d\n",i);
		return EXIT_FAILURE;
	}
	left = (i << 1) + 1;
	right = (i + 1) << 1;
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
	return 1;
}

struct PriorityQueue *newPriorityQueue(){
	struct PriorityQueue *q;
	q = (struct PriorityQueue *) malloc(sizeof(struct PriorityQueue));
	if( q == NULL){
		printf("cannot new a priority queue!\n");
		return NULL;
	}
	q->length = 0;
	q->capacity = 8;
	q->qelem = (void **) malloc(sizeof(void *) * q->capacity);
	return q;
}

int queueAdd(void *key, struct PriorityQueue *q, int (*compr)()){
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

void *queueExtract(struct PriorityQueue *q, int (*compr)()){
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

void queueDestroy(struct PriorityQueue *q, void (*freefunc)(void *)){
	int i;
	for(i=0; i < q->capacity; i++){
		if(q->qelem[i] != NULL){
			freefunc(q->qelem[i]);
			q->qelem[i] = NULL;
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

struct Edge {
	short u, v;
	double dist;
};

struct Vertex{
	double x, y;
};

struct Edge *newEdge(struct Vertex *u, struct Vertex *v){
	struct Edge *e;
	double xdiff, ydiff;
	e = (struct Edge *) malloc(sizeof(struct Edge));
	xdiff = u->x - v->x;
	ydiff = u->y - v->y;
	e->dist = sqrt(xdiff*xdiff + ydiff*ydiff);
	return e;
}

struct Vertex *newVertex(double x, double y){
	struct Vertex *v;
	v = (struct Vertex *) malloc(sizeof(struct Vertex));
	v->x = x;
	v->y = y;
	return v;
}

int compareEdge(const void *a, const void *b){
	struct Edge *e, *f;
	e = (struct Edge *)a;
	f = (struct Edge *)b;
	if(e->dist < f->dist) return 1;
	else if (e->dist > f->dist) return -1;
	else return 0;
}

double MST(struct Vertex *V[], short nV){
	short i, j, tsize, src, target;
	char *discover;
	double totalWeight = 0;
	struct PriorityQueue *q;
	struct Edge *e, *echeck;
	
	if(nV == 1) return 0;	
	
	discover = (char *) calloc(nV, sizeof(char));
	q = newPriorityQueue();
	
	/*using V[0] as root*/
	discover[0] = 1;
	tsize = 1;
	for(i=1; i<nV; i++){
		e = newEdge(V[0], V[i]);
		e->u = 0;
		e->v = i;
		queueAdd(e, q, compareEdge);
	}
	
	while((tsize < nV) && (queueHasElement(q))){
		echeck = (struct Edge *) queueExtract(q, compareEdge);
		if ((discover[echeck->u] == 1) && (discover[echeck->v] == 1)){
			free(echeck);
			continue;
		}
		/*MST grows*/
		src = (discover[echeck->u] == 0)? echeck->u : echeck->v;
		discover[src] = 1;
		tsize++;
		totalWeight += echeck->dist;
		free(echeck);
		for(j=1; j<nV; j++){
			if(discover[j] == 0){
				e = newEdge(V[src], V[j]);
				e->u = src;
				e->v = j;
				queueAdd(e, q, compareEdge);
			}
		}
		
	}
	while(queueHasElement(q)){
		e = queueExtract(q, compareEdge);
		free(e);
	}
	free(discover);
	free(q);
	return totalWeight;
}

int main(){
	short nTest;
	short nV, i;
	char first = 1;
	double x, y, ans;
	struct Vertex *V[MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	
	fscanf(fp, "%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%hd", &nV);
		for(i=0; i<nV; i++){
			fscanf(fp, "%lf %lf", &x, &y);
			V[i] = newVertex(x, y);
		}
		
		ans = MST(V, nV);
		
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		
		printf("%.2lf\n",ans);
		
		for(i=0; i<nV; i++){
			free(V[i]);
		}
	}
	
	return 0;
}