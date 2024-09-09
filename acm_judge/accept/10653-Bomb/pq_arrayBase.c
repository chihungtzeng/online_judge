#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINT 1000000000

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

void queueDestroy(struct PriorityQueue *q){
	int i;
	for(i=0; i < q->capacity; i++){
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

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	struct PriorityQueue *qhead;
	int *key;
	int i, j;
	int count=0;
	qhead = newPriorityQueue();
	srand(time(NULL));
	
	
	for(i=0; i<1; i++){
		for(j=0; j< 5000; j++){
			key = (int *) malloc(sizeof(int));
			*key = rand() % 100;
			printf("%d ", *key);
			queueAdd(key, qhead, compareInt);
		}

		while(queueHasElement(qhead)){
			key = (int *) queueExtract(qhead, compareInt);
			printf("%d ",*key);
			free(key);
			count++;
		}
	}

	printf("\n total %d numbers\n",count);
	printf("qsize: %ld q element size:%d\n", sizeof(qhead), qhead->capacity);
	return 0;
}
