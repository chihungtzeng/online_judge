#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define INF 0x7fffffff
#define LEN 51
#define DEBUG 0

struct Language{
	char *name;
	short id;
	int dist;
	char isInQueue; 
	char inChar[100];
	short nInChar;
	short *neighbor;
	char *initialCaptal;
	short *weight;
	short nNeighbor;
	short maxNeighbor;
};

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

void freeLanguage(struct Language *target){
	if(target == NULL) return ;
	if(target->name) free(target->name);
	if(target->neighbor) free(target->neighbor);
	if(target->weight) free(target->weight);
}

void renewNeighborArray(struct Language *pObj, short size){
	pObj->maxNeighbor = size;
	pObj->neighbor = (short *) realloc(NULL, sizeof(short)* pObj->maxNeighbor);
	pObj->weight = (short *) realloc(NULL, sizeof(short)* pObj->maxNeighbor);
	pObj->initialCaptal = (char *) realloc(NULL, pObj->maxNeighbor);
	return ;
}

struct Language *newLanguage(char *name){
	struct Language *pObj;
	pObj = (struct Language *) malloc(sizeof(struct Language));
	pObj->name = strdup(name);
	pObj->isInQueue = 0;
	pObj->id = 0;
	pObj->dist = INF;
	pObj->nInChar = 0;
	pObj->maxNeighbor = 8;
	pObj->nNeighbor = 0;
	renewNeighborArray(pObj, pObj->maxNeighbor);
	return pObj;
} 

int hasInChar(struct Language *ell, char c){
	short i;
	for(i=0; i<ell->nInChar; i++){
		if(ell->inChar[i] == c) return 1;
	}
	return 0;
}

void addInChar(struct Language *ell, char c){
	if(!hasInChar(ell, c)){
		ell->inChar[ell->nInChar] = c;
		ell->nInChar += 1;
	}
}

void addEdge(struct Language *languageInst, short target, size_t len, char letter){
	/*points to target, with weight len*/
	short i;
	for(i=0; i < languageInst->nNeighbor; i++){
		if(languageInst->neighbor[i] == target){
			if( (languageInst->initialCaptal[i] == letter)){
				if (languageInst->weight[i] > len){
					languageInst->weight[i] = len;
				}
				return ;
			}
		}
	} 
	if(languageInst->maxNeighbor == languageInst->nNeighbor){
		renewNeighborArray(languageInst, languageInst->maxNeighbor << 1);
	}
	languageInst->neighbor[languageInst->nNeighbor] = target;
	languageInst->weight[languageInst->nNeighbor] = len;
	languageInst->initialCaptal[languageInst->nNeighbor] = letter;
	languageInst->nNeighbor += 1;
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
	return y->dist - x->dist;
}

char updateDistance(struct Language *src, struct Language *dest, int dId){
	/*return 1 if dest's dist is updated, 0 otherwise*/
	short neighborId;
	short i, j;
	char shorter = 0, ch;
	int newDist;
	
	newDist = src->dist + src->weight[dId];	
	if(newDist > dest->dist) return shorter;
		
	ch = src->initialCaptal[dId];
	if(hasInChar(src, ch) && (src->nInChar == 1)) return shorter;
		
		
	if(newDist == dest->dist){
		addInChar(dest, ch);
	} else if (newDist < dest->dist){
		dest->inChar[0] = ch;
		dest->nInChar = 1;
		dest->dist = newDist;
		shorter = 1;
	}
	return shorter;
}

void shortestPath(short nNode, struct Language *languageSet[]){
	struct PriorityQueue *q;
	struct Language *key, *target;
	short i, j;
	char isShorter;
	int newDist;
	q = newPriorityQueue();	
	languageSet[0]->dist = 0;
	languageSet[0]->nInChar = 1;
	languageSet[0]->inChar[0] = 0;
	queueAdd(languageSet[0], q, compareLanguageByDist);
	while(queueHasElement(q)){
		key = (struct Language *) queueExtract(q, compareLanguageByDist);
		key->isInQueue = 0;
		for(i=0; i<key->nNeighbor; i++){
			target = languageSet[key->neighbor[i]];
			isShorter = updateDistance(key, target, i);
			if(isShorter){
				if(!target->isInQueue){
					queueAdd(target, q, compareLanguageByDist);
					target->isInQueue = 1;
				}
			}
		}
	}
	free(q->qelem);
}

int main(){
	short nLanguage, i, j, curLanguageIndex, destId;
	short langId[2];
	char *startLanguage, *endLanguage;
	char word[LEN], *lang[2];
	void *root, *match[2];
	size_t len;
	struct Language *languageSet[2000];
	FILE *fp;
	int ans;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	startLanguage = (char *) malloc(LEN);
	endLanguage = (char *) malloc(LEN);
	lang[0] = (char *) malloc(LEN);
	lang[1] = (char *) malloc(LEN);

	while(1 == fscanf(fp, "%hd", &nLanguage)){
		if(0 == nLanguage) return 0;
		#if DEBUG
			puts("--------------------");
		#endif
		for(i=0; i<nLanguage; i++){
			languageSet[i] = NULL;
		}	
		root = NULL;
		curLanguageIndex = 0;
		
		fscanf(fp, "%s %s", startLanguage, endLanguage);
		
		languageSet[curLanguageIndex] = newLanguage(startLanguage);
		languageSet[curLanguageIndex]->id = curLanguageIndex;
		tsearch(languageSet[curLanguageIndex], &root, compareLanguage);
		curLanguageIndex += 1;
		
		languageSet[curLanguageIndex] = newLanguage(endLanguage);
		languageSet[curLanguageIndex]->id = curLanguageIndex;
		
		match[0] = tsearch(languageSet[curLanguageIndex], &root, compareLanguage);
		if(*(struct Language **)match[0] == languageSet[curLanguageIndex]){
			
			curLanguageIndex += 1;
			destId = 1;
		}
		else{
			free(languageSet[curLanguageIndex]);			
			destId = 0;
		}
		
		for(i=0; i<nLanguage; i++){
			fscanf(fp, "%s %s %s", lang[0], lang[1], word);
			len = strlen(word);
			for(j=0; j<2; j++){
				languageSet[curLanguageIndex] = newLanguage(lang[j]);
				match[j] = tsearch(languageSet[curLanguageIndex], &root, compareLanguage);
				if(*(struct Language **) match[j] == languageSet[curLanguageIndex]){
					languageSet[curLanguageIndex]->id = curLanguageIndex;
					langId[j] = curLanguageIndex;
					curLanguageIndex += 1;
				} else {
					freeLanguage(languageSet[curLanguageIndex]);
					languageSet[curLanguageIndex] = *(struct Language **) match[j];
					langId[j] = languageSet[curLanguageIndex]->id;
				}
			}
			for(j=0; j<2; j++){
				addEdge(languageSet[langId[j]], langId[1 - j], len, word[0]);
			}
		}
		#if DEBUG
			int src, target;
			for(i=0; i<curLanguageIndex; i++){
				for(j=0; j<languageSet[i]->nNeighbor; j++){
					target = languageSet[i]->neighbor[j];
					printf("%s %s %d\n", languageSet[i]->name, 
						languageSet[target]->name, 
						languageSet[i]->weight[j]);
				}
			}
		#endif
		shortestPath(curLanguageIndex, languageSet);
		ans = languageSet[destId]->dist;
		if(ans == INF){
			puts("impossivel");
		} else {
			printf("%d\n", ans);
		}
		for(i=0; i<curLanguageIndex; i++){
			freeLanguage(languageSet[i]);
		}
		root = NULL;
	}
	
	free(startLanguage);
	free(endLanguage);
	free(lang[0]);
	free(lang[1]);
	return 0;	
}
