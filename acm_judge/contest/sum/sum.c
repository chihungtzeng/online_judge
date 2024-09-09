#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 751
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b);

#define COMPARE >
#define TYPE int
#define DEBUG 0

struct PriorityQueue{
	TYPE *qelem;
	int length;
	int capacity;
};

void PriorityQueueInit(struct PriorityQueue *q){
	q->length = 0;
	q->capacity = 16;
	q->qelem = (TYPE *) malloc(sizeof(TYPE) * q->capacity);
} 

int heapify(struct PriorityQueue *q, int i){
	int left, right, largest;
	if(q == NULL){
		printf("queue is null when calling heapify at %d\n",i);
		return EXIT_FAILURE;
	}
	left = (i << 1) + 1;
	right = (i + 1) << 1;
	if ((left < q->length) && (q->qelem[left] < q->qelem[i])){
		largest = left;
	} 
	else {
		largest = i;
	}
	if ((right < q->length) && (q->qelem[right] < q->qelem[largest])){
		largest = right;
	}
	if (largest != i){
		SWAP(q->qelem[i], q->qelem[largest]);
		heapify(q, largest);
	}
	return 1;
}


int queueAdd(TYPE key, struct PriorityQueue *q){
	int parent, left, right;
	int cur;

	if(q->length == q->capacity){
		q->capacity <<= 1;
		q->qelem = realloc(q->qelem, sizeof(TYPE)*q->capacity); 
	}
	cur = q->length;
	parent = (cur - 1)/2;
	while((cur > 0) && (q->qelem[parent] > key) ){
		q->qelem[cur] = q->qelem[parent];
		cur = parent;
		parent = (cur - 1)/2;
	}
	q->qelem[cur] = key;
	q->length += 1;
	return EXIT_SUCCESS;
}

TYPE queueExtract(struct PriorityQueue *q){
	TYPE extreme;
	
	extreme = q->qelem[0];
	q->length -= 1;
	q->qelem[0] = q->qelem[q->length];
	heapify(q, 0);
	return extreme;
}

void queueClear(struct PriorityQueue *q){
	q->length = 0;
}

int compareTYPE(const void *a, const void *b){
	return *(TYPE *)a - *(TYPE *)b;
}

int queueHasElement(struct PriorityQueue *q){
	return q->length;
}

short decidePopArrayIndex(TYPE matrix[MAX][MAX], short curPos[MAX], short nArray){
	short i, j, ans=-1;
	
	int minDiff = 1000000000, curDiff;
	int minpop = 1000000000;
	for(i=0; i<nArray; i++){
		j = curPos[i];
		curDiff = matrix[i][j + 1] - matrix[i][j];
		if(minDiff > curDiff){
			minDiff = curDiff;
			ans = i;
			minpop = matrix[i][j];
		}
		else if(minDiff == curDiff){
			if(matrix[i][j] > minpop){
				minpop = matrix[i][j];
				ans = i;
			}
		}
	}
	
	return ans;
}

int main(){
	TYPE matrix[MAX][MAX];
	short curPos[MAX], nArray, i, j;
	struct PriorityQueue q;
	FILE *fp;	
	int sum;
	int diff[MAX];
	int k = 0;
	fp = (DEBUG)? fopen("ksample.in","r") : stdin;
	PriorityQueueInit(&q);
	
	
	while(1 == fscanf(fp, "%hd", &nArray)){
		k++;		
		for(i=0; i<nArray; i++){
			for(j=0; j<nArray; j++){
				fscanf(fp, "%d", &matrix[i][j]);
			}
			curPos[i] = 0;
			diff[i] = 0;
		}
		
		for(i=0; i<nArray; i++){
			qsort(matrix[i], nArray, sizeof(TYPE), compareTYPE);
		}
		/*
		if(k == 947){
			for(i=0; i<nArray; i++){
				for(j=0; j<nArray; j++){
					printf("%d ", matrix[i][j]);
				}
				printf("\n");
			}
		}
		*/
		sum = 0;
		for(i=0; i<nArray; i++){
			sum += matrix[i][0];			
		}
		printf("%d", sum);
		for(i=0; i<nArray; i++){
			queueAdd(sum - matrix[i][0] + matrix[i][1], &q);
		}
		for(i=1; i<nArray; i++){
			j = decidePopArrayIndex(matrix, curPos, nArray);
			curPos[j] += 1;
			sum = queueExtract(&q);
			printf(" %d", sum);
			for(j=0; j<nArray; j++){
				if(curPos[j] != nArray){
					queueAdd(sum + matrix[j][curPos[j] + 1] - matrix[j][curPos[j]], &q);
				}
			}
		}
		printf("\n");
		queueClear(&q);
		
	}

	return 0;
}