#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define INF 1000000000
#define LEN 51
#define DEBUG 0
#define START_LANG 0
#define END_LANG 1
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) < (b)? (b) : (a))
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)


/************************************************
	Edge Definition
************************************************/
struct Edge {
	int endpoint[2];
	int weight;
	char letter;
};

struct Edge *newEdge(int u, int v, int w, char letter){
	struct Edge *e;
	e = (struct Edge *) malloc(sizeof(struct Edge));
	e->endpoint[0] = MIN(u, v);
	e->endpoint[1] = MAX(u, v);
	e->weight = w;
	e->letter = letter;
	return e;
}

int compareEdge(const void *a, const void *b){
	struct Edge *x, *y;
	x = (struct Edge *) a;
	y = (struct Edge *) b;
	if (x->endpoint[0] != y->endpoint[0]){
		return x->endpoint[0] - y->endpoint[0];
	} else if (x->endpoint[1] != y->endpoint[1]) {
		return x->endpoint[1] - y->endpoint[1];
	}
	else {
		return x->letter - y->letter;
	}
	
}

/************************************************
Graph
************************************************/

/************************************************
Language
************************************************/

struct Neighbor{
	int id;
	int weight;
	char letter;
};

int compareNeighbor(const void *a, const void *b){
	struct Neighbor *x, *y;
	x = *(struct Neighbor **)a;
	y = *(struct Neighbor **)b;
	if(x->id != y->id) return x->id - y->id;
	else return x->weight - y->weight;
}

struct Neighbor * newNeighbor(int id, int weight, char letter){
	struct Neighbor *pObj;
	pObj = (struct Neighbor *) malloc(sizeof(struct Neighbor));
	pObj->id = id;
	pObj->weight = weight;
	pObj->letter = letter;
	return pObj;
}

struct IncomingPath{
	char letter;
	int dist;
};

int compareIncomingPath(const void *a, const void *b){
	struct IncomingPath *x, *y;
	x = (struct IncomingPath *)a;
	y = (struct IncomingPath *)b;
	if(x->dist != y->dist){
		return x->dist - y->dist;
	} else {
		return x->letter - y->letter;
	}
}

const struct IncomingPath defaultIncomingPath = {0x7f, INF};

struct Language {
	char name[LEN];
	int id;
	struct IncomingPath incomingPath[2];
	int degree;
	int maxDegree;
	struct Neighbor **neighbor;
};

void setNeighborArraySize(struct Language *ell, int newMaxDegree){
	assert(NULL != ell);
	ell->maxDegree = newMaxDegree;
	ell->neighbor = (struct Neighbor **) 
		realloc(ell->neighbor, sizeof(struct Neighbor *) * newMaxDegree);
}

void freeLanguage(void *pObj){
	struct Language *ell;
	assert(pObj != NULL);
	ell = (struct Language *) pObj;
	
	int i;
	for(i=0; i<ell->degree; i++){
		free(ell->neighbor[i]);
	}
	free(ell->neighbor);
}

struct Language * newLanguage(){
	struct Language *ell;
	ell = (struct Language *) malloc(sizeof(struct Language));
	ell->incomingPath[0] = defaultIncomingPath;
	ell->incomingPath[1] = defaultIncomingPath;
	ell->degree = 0;
	ell->neighbor = NULL;
	setNeighborArraySize(ell, 16);
	return ell;
}



void addNeighbor(struct Language *ell, struct Edge *edge){
	assert(ell != NULL);
	struct Neighbor *pObj;
	if(ell->degree == ell->maxDegree){
		setNeighborArraySize(ell, ell->maxDegree << 1);
	}
	pObj = newNeighbor(
		edge->endpoint[0] + edge->endpoint[1] - ell->id,
		edge->weight,
		edge->letter 
		);
	ell->neighbor[ell->degree] = pObj;
	ell->degree += 1;
}

int compareLanguage(const void *a, const void *b){
	struct Language *x, *y;
	x = (struct Language *)a;
	y = (struct Language *)b;
	return strcmp(x->name, y->name);
}

int compareLanguageByDist(const void *a, const void *b){
	struct Language *x, *y;
	x = (struct Language *)a;
	y = (struct Language *)b;
	return y->incomingPath[0].dist - x->incomingPath[0].dist;
}

/************************************************
Priority Queue
************************************************/

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
	q->capacity = 512;
	q->qelem = (void **) malloc(sizeof(void *) * q->capacity);
	return q;
}

int queueAdd(void *key, struct PriorityQueue *q, int (*compr)()){
	int parent;
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

int queueHasElement(struct PriorityQueue *q){
	if(q == NULL){
		printf("the priority points to null\n");
		return 0;
	}
	return q->length;
}


/*********************

*********************/

int updateLanguageDist(
	struct Language *src, struct Language *target, struct Neighbor *edge){
	int i;
	struct IncomingPath tmpPath[3];
	int oldDist = target->incomingPath[0].dist;
	int doUpdate = 0;
	
	
	tmpPath[0] = target->incomingPath[0];
	tmpPath[1] = target->incomingPath[1];
	tmpPath[2].dist = INF;
	for(i=0; i<2; i++){
		if(edge->letter == src->incomingPath[i].letter) continue;
		
		tmpPath[2].letter = edge->letter;
		tmpPath[2].dist = src->incomingPath[i].dist + edge->weight;
		qsort(tmpPath, 3, sizeof(struct IncomingPath), compareIncomingPath);
		target->incomingPath[0] = tmpPath[0];
		
		target->incomingPath[1] = (tmpPath[0].letter != tmpPath[1].letter)?
				tmpPath[1] : tmpPath[2];
		 	
		if(oldDist > target->incomingPath[0].dist){
			doUpdate = 1;
		}
	}
	return doUpdate;
}

int shortestPath(int start, int nLang, struct Language *langArray[]){

	struct PriorityQueue *q;
	struct Language *src;
	int i, nId;	
	char inQueue[nLang];
	int doUpdate;	

	memset(inQueue, 0, sizeof(char)*nLang);
	q = newPriorityQueue();	
	langArray[start]->incomingPath[0].dist = 0;
	langArray[start]->incomingPath[1].dist = 0;
	queueAdd(langArray[start], q, compareLanguageByDist);

	while(queueHasElement(q)){
		src = queueExtract(q, compareLanguageByDist);
		inQueue[src->id] = 0;
		for(i=0; i<src->degree; i++){
			nId = src->neighbor[i]->id;
			doUpdate = updateLanguageDist(src, langArray[nId], src->neighbor[i]);
			
			if(doUpdate){
				if(inQueue[nId] == 0){
					inQueue[nId] = 1;
					queueAdd(langArray[nId], q, compareLanguageByDist);
				}
			}   			
		}
	}
		
	
	return EXIT_SUCCESS;
}

int main(){
	FILE *fp;
	int nLanguage, i, j, wordLen;	
	int langQueryId[2], langId[2], lastLangId;
	struct Language *lang[2], *ell;
	struct Language *langArray[4002];
	
	struct Edge *edge, *edgeArray[4002];
	int edgeArraySize;
	int u, v;

	char word[LEN];
	
	void *langNameSet, *edgeSet, *match; 
	int ans;
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%d", &nLanguage)){
		if(0 == nLanguage) return 0;
		#if DEBUG
			puts("--------------------");
		#endif
		
		langNameSet = NULL;
		edgeSet = NULL;
		lastLangId = 0;
		edgeArraySize = 0;
		/*Step 1: read start and end point*/
		for(i=0; i<2; i++){
			ell = newLanguage();
			fscanf(fp, "%s", ell->name);
			match = tsearch(ell, &langNameSet, compareLanguage);
			if( *(struct Language **) match == ell){
				langArray[lastLangId] = ell;
				ell->id = lastLangId;
				langQueryId[i] = lastLangId;
				lastLangId += 1;
			} else {
				free(ell);
				ell = *(struct Language **) match;
				langQueryId[i] = ell->id;
			}
		}
		/*
			Step 2: read words associated to languages 
			and create an edge associated to each word;
			the edge is in the form {langId1, langId2, len, start_letter) 
		*/
		edgeArraySize = 0;
		for(i=0; i<nLanguage; i++){
			lang[0] = newLanguage();
			lang[1] = newLanguage();
			fscanf(fp, "%s %s %s", lang[0]->name, lang[1]->name, word);
			wordLen = strlen(word);
			for(j=0; j<2; j++){
				match = tsearch(lang[j], &langNameSet, compareLanguage);
				if(*(struct Language **) match == lang[j]){
					langArray[lastLangId] = lang[j];
					lang[j]->id = lastLangId++;				
				} else {
					free(lang[j]);
					lang[j] = *(struct Language **) match;					
				}
				langId[j] = lang[j]->id;
			}
			if(lang[0]->id == lang[1]->id){
				continue;
			} 
			/*Create Edge*/
			edge = newEdge(lang[0]->id, lang[1]->id,	wordLen, word[0]);
			match = tsearch(edge, &edgeSet, compareEdge);
			if(*(struct Edge **) match == edge){
				edgeArray[edgeArraySize++] = edge;
			} else {
				/*duplicate edge, update weight if necessary*/
				free(edge);
				edge = *(struct Edge **) match;
				edge->weight = MIN(edge->weight, wordLen);
			}
		}
		/*
			Step 3: creating a (possibly non-simple) graph 
			based on the information on edges
		*/
		#if DEBUG
		for(i=0; i<edgeArraySize; i++){
			edge = edgeArray[i];
			printf("Edge Info: (%s) <-> (%s), weight=%hd, letter=%c\n",
				langArray[edge->endpoint[0]]->name, 
				langArray[edge->endpoint[1]]->name, 
				edge->weight, edge->letter);
		}
		#endif
		
		
		for(i=0; i<edgeArraySize; i++){			
			edge = edgeArray[i];
			u = edge->endpoint[0];
			v = edge->endpoint[1];
			addNeighbor(langArray[u], edge);
			addNeighbor(langArray[v], edge);
		}
		#if DEBUG
		for(i=0; i<lastLangId; i++){
			qsort(langArray[i]->neighbor, langArray[i]->degree,
				sizeof(struct Neighbor *), compareNeighbor);
						
			for(j=0; j<langArray[i]->degree; j++){
				v = langArray[i]->neighbor[j]->id;
				printf("Language: %s -> %s %hd, char=%c\n",
					langArray[i]->name, 
					langArray[v]->name, 
					langArray[i]->neighbor[j]->weight,
					langArray[i]->neighbor[j]->letter);
				
			}
			
		}
		#endif
		/*Find the intest path*/
		
		shortestPath(langQueryId[0], lastLangId, langArray);
		ans = langArray[langQueryId[1]]->incomingPath[0].dist;
		if(ans == INF){
			puts("impossivel");
		} else {
			printf("%d\n", ans);
		}
		/*
		for(i=0; i<lastLangId; i++){
			freeLanguage(langArray[i]);
		}
		for(i=0; i<edgeArraySize; i++){
			free(edgeSet[i]);
		}
		*/
		
		tdestroy(langNameSet, freeLanguage);
		tdestroy(edgeSet, free);
		
	}
	
	return 0;	
}
