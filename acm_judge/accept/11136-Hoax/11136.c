#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1


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


void queueRemoveElement(void *key, struct PriorityQueue *q, int (*compr)()){
	int i;
	for(i = q->length - 1; i >= 0; i--){
		if(!compr(key, q->qelem[i])){
			q->length -= 1;
			q->qelem[i] = q->qelem[q->length];
			heapify(q, i, compr);
			return ;
		}
	}
}


void queueClear(struct PriorityQueue *q, void (*freefunc)(void *)){
	int i;
	for(i=0; i < q->length; i++){
		freefunc(q->qelem[i]);
	}
	q->length = 0;
}

void queueDestroy(struct PriorityQueue *q){
	free(q->qelem);
}


int compareIntInc(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int compareIntDec(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main(){
	
	int nDay, nBill, i, j, *bill, *bill2;
	long long sum;
	struct PriorityQueue *maxq, *minq;
	int billArray[10001], half;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%d", &nDay)){
		if(0 == nDay) return 0;
		
		maxq = newPriorityQueue();
		minq = newPriorityQueue();
		sum = 0;
		for(i=0; i<nDay; i++){
			fscanf(fp, "%d", &nBill);
			for(j=0; j<nBill; j++){
				fscanf(fp, "%d", billArray + j);
			}
			qsort(billArray, nBill, sizeof(int), compareIntInc);
			
			if(DEBUG){
				printf("inputs for a day:");
				for(j=0; j<nBill; j++) printf("%d ", billArray[j]);
				printf("\n");
			}
			
			half = nBill >> 1;
			for(j=0; j < half; j++){
				bill = (int *) malloc(sizeof(int));
				*bill = billArray[j];
				queueAdd(bill, minq, compareIntDec);
			}
			for(j=half; j<nBill; j++){
				bill = (int *) malloc(sizeof(int));
				*bill = billArray[j];
				queueAdd(bill, maxq, compareIntInc);
			}			
			while(maxq->length - minq->length > 1){
				bill = (int *) queueExtract(maxq, compareIntInc);
				queueAdd(bill, minq, compareIntDec);
			} 
			while(minq->length - maxq->length > 1){
				bill = (int *) queueExtract(minq, compareIntDec);
				queueAdd(bill, maxq, compareIntInc);
			} 
			
			bill = (int *) queueExtract(maxq, compareIntInc);
			bill2 = (int *) queueExtract(minq, compareIntDec);
			
			
			sum += abs(*bill - *bill2);
			if(DEBUG){
				printf("%d %d\n", *bill, *bill2);
			}
		}
		
		printf("%lld\n", sum);
		queueClear(maxq, free);
		queueClear(minq, free);
		queueDestroy(maxq);
		queueDestroy(minq);
	}
	
	return 0;
}