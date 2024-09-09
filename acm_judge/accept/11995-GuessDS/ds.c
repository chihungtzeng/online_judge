#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
#define PUSH 1
#define POP 2
#define QUEUE 0
#define STACK 1
#define PRIORITY_QUEUE 2
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b); 

struct PriorityQueue{
	char *qelem;
	int length;
	int capacity;
};

struct Stack{
	int top;
	int capacity;
	char *data;
};

struct Queue{
	int head, tail;
	int capacity;
	char *data;
};


void PriorityQueueInit(struct PriorityQueue *q){
	q->length = 0;
	q->capacity = MAX;
	q->qelem = (char *) malloc(sizeof(char) * q->capacity);
}

int heapify(struct PriorityQueue *q, int i){
	int left, right, largest;
	if(q == NULL){
		printf("queue is null when calling heapify at %d\n",i);
		return EXIT_FAILURE;
	}
	left = (i << 1) + 1;
	right = (i + 1) << 1;
	if ((left < q->length) && (q->qelem[left] > q->qelem[i])){
		largest = left;
	} 
	else {
		largest = i;
	}
	if ((right < q->length) && (q->qelem[right] > q->qelem[largest])){
		largest = right;
	}
	if (largest != i){
		SWAP(q->qelem[i], q->qelem[largest]);
		heapify(q, largest);
	}
	return 1;
}


int queueAdd(char key, struct PriorityQueue *q){
	int parent, left, right;
	int cur;

	if(q->length == q->capacity){
		q->capacity <<= 1;
		q->qelem = realloc(q->qelem, sizeof(char)*q->capacity); 
	}
	cur = q->length;
	parent = (cur - 1)/2;
	while((cur > 0) && (q->qelem[parent] < key) ){
		q->qelem[cur] = q->qelem[parent];
		cur = parent;
		parent = (cur - 1)/2;
	}
	q->qelem[cur] = key;
	q->length += 1;
	return EXIT_SUCCESS;
}

char queueExtract(struct PriorityQueue *q){
	char extreme;
	
	extreme = q->qelem[0];
	q->length -= 1;
	q->qelem[0] = q->qelem[q->length];
	heapify(q, 0);
	return extreme;
}

void queueClear(struct PriorityQueue *q){
	int i;
	q->length = 0;
}

int queueHasElement(struct PriorityQueue *q){
	return q->length;
}


void stackInit(struct Stack *s){
	s->capacity = MAX;
	s->data = (char *) malloc(sizeof(char)*MAX);
}

void queueInit(struct Queue *q){
	q->capacity = MAX;
	q->data = (char *) malloc(sizeof(char)*MAX);
}

void stackPush(struct Stack *s, char v){
	if(s->capacity == s->top){
		s->capacity <<= 1;
		s->data = (char *) realloc(s->data, sizeof(char)*s->capacity);
	}
	s->data[s->top] = v;
	s->top += 1;
}

char stackPop(struct Stack *s){
	s->top -= 1;
	return s->data[s->top];
}

void queuePush(struct Queue *q, char v){
	if(q->capacity == q->tail){
		q->capacity <<= 1;
		q->data = (char *) realloc(q->data, sizeof(char)*q->capacity);
	}
	q->data[q->tail] = v;
	q->tail += 1;
}

char queuePop(struct Queue *q){
	char result = q->data[q->head];
	q->head += 1;
	return result;
}

char *newKey(char k){
	char *key;
	key = (char *) malloc(sizeof(char));
	*key = k;
	return key;
}

int compare(const void *a, const void *b){
	return  (int)(*(char *)a - *(char *)b);
}

void solve(char ds[]){
	char nPossible = 0;
	char i;
	for(i=0; i<3; i++){
		if(ds[i] == 1) nPossible++;
	}
	if(nPossible == 0){
		puts("impossible");
	} else if(nPossible > 1) {
		puts("not sure");
	} else{
		if(ds[STACK]) puts("stack");
		else if (ds[QUEUE]) puts("queue");
		else puts("priority queue");
	}
}

int main(){
	struct PriorityQueue qhead;
	struct Stack stack;
	struct Queue queue;
	short nCommand, i;
	char command;
	char value, *key;
	char ds[3];
	FILE *fp = stdin;
	
	stackInit(&stack);
	queueInit(&queue);
	PriorityQueueInit(&qhead);
	
	while(1 == fscanf(fp, "%hd", &nCommand)){
		stack.top = 0;
		queue.tail = 0;
		queue.head = 0;
		
		for(i=0; i<3; i++){
			ds[i] = 1;
		}
		for(i=0; i<nCommand; i++){
			fscanf(fp, "%hhd %hhd", &command, &value);
			if(command == PUSH){
				
				queueAdd(value, &qhead);
				stackPush(&stack, value);
				queuePush(&queue, value);
			} else if(command == POP){
				if(queueExtract(&qhead) != value) ds[PRIORITY_QUEUE] = 0;
				if(stackPop(&stack) != value) ds[STACK] = 0;
				if(queuePop(&queue) != value) ds[QUEUE] = 0;
				free(key);
			}
		}
		/*
		while(queueHasElement(&qhead)){
			printf("%hhd\n", queueExtract(&qhead));
		}
		*/
		solve(ds);
		queueClear(&qhead);
	}
	
	free(stack.data);
	free(queue.data);
	return 0;
}