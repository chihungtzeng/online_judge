#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define INF 0x7fffffff
#define LEN 51
#define DEBUG 1
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) < (b)? (b) : (a))

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}


/************************************************
	Edge Definition
************************************************/
struct Edge {
	short endpoint[2];
	short weight;
	char letter;
};

struct Edge *newEdge(short u, short v, short w, char letter){
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
	} else {
		return x->letter - y->letter;
	}
}

/************************************************
Graph
************************************************/

/************************************************
Language
************************************************/

struct Language {
	char name[LEN];
	short id;
	char inChar;
	int dist;
};


struct Language * newLanguage(){
	struct Language *ell;
	
	ell = (struct Language *) malloc(sizeof(struct Language));
	ell->inChar = 0;
	ell->dist = INF;
	return ell;
}

int compareLanguage(const void *a, const void *b){
	struct Language *x, *y;
	x = (struct Language *)a;
	y = (struct Language *)b;
	return strcmp(x->name, y->name);
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

int queueHasElement(struct PriorityQueue *q){
	if(q == NULL){
		printf("the priority points to null\n");
		return 0;
	}
	return q->length;
}


/*********************
*********************/

int main(){
	FILE *fp;
	short nLanguage, i, j, wordLen;
	
	struct Language startLang, endLang;	
	short langQueryId[2], langId[2], lastLangId;
	struct Language *lang[2], *ell;
	struct Language *langArray[2001];
	
	struct Edge *edge, *edgeArray[2001];
	short edgeArraySize;

	char word[LEN];
	
	void *langNameSet, *edgeSet, *match; 
	int ans;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%hd", &nLanguage)){
		if(0 == nLanguage) return 0;
		#if DEBUG
			puts("--------------------");
		#endif
		
		langNameSet = NULL;
		edgeSet = NULL;
		lastLangId = 0;
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
			
			/*Create Edge*/
			edge = newEdge(lang[0]->id, lang[1]->id, wordLen, word[0]);
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
//		shortestPath(curLanguageIndex, languageSet);
		ans = INF;
		if(ans == INF){
			puts("impossivel");
		} else {
			printf("%d\n", ans);
		}
		tdestroy(langNameSet, free);
		tdestroy(edgeSet, free);
	}
	
	return 0;	
}
