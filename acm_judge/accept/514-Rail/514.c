#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

struct Statck{
	short ele[MAX];
	short nEle;
};

int push(struct Stack *stack, short ele){
	if(stack->nEle == MAX){
		printf("stack overflow\n");
		return EXIT_FAILURE;
	}
	if(stack->nEle < 0){
		stack->nEle = 0;
	}
	stack[stack->nEle] = ele;
	stack->nEle += 1;
	return EXIT_SUCCESS; 
}

int pop(struct Stack *stack, short *result){
	if(stack->nEle <= 0){
		printf("stack underflow");
		return EXIT_FAILURE;
	}
	*result = stack->ele[stack->nEle - 1];
	stack->nEle -= 1;
	return EXIT_SUCCESS;
}

short peek(struct Stack *stack){
	if(stack->nEle <= 0){
		printf("stack underflow");
		return EXIT_FAILURE;
	}
	return stack->ele[stack->nEle - 1];
}

int findAns(struct Stack *stack, short nTrain, short trainOut[]){
	short i, j;
	short out, result;
	stack->nEle = 0;
	for(i=1; i<=nTrain; i++){
		out = trainOut[i];
		
		if(out == i){
			/*stack is empty, SAFE*/
		}
		else{
			
		}
	}	
		
}

int main(){
	struct Stack stack;
	short i;
	short trainOut[MAX];
	short nTrain;
	char first=1;
	int ans;
	while(1 == scanf("%hd", &nTrain)){
		if(nTrain == 0) return 0;
		scanf("%hd", &trainOut[1]);
		if(trainOut[1] == 0){
			if(first) first = 0;
			else printf("\n");
			
			continue; 
		}
		
		for(i=2; i<= nTrain; i++){
			scanf("%hd", &trainOut[i]);
		}
		ans = findAns(&stack, nTrain, trainOut);
		puts((ans == EXIT_SUCCESS)? "Yes" : "No");
	}
	return 0;
}