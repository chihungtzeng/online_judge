#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32768
#define DEBUG 0


int *findSeq(char *input, int nNum){
	char *inputCut, *tmpStr;
	int *returnSeq;
	int *curSeq;
	int operant;
	char operator;
	int i, len, oppos;

	if(input == NULL){
		printf("null input\n");
		return NULL;
	}

	if(DEBUG){
		printf("call findSeq(%s %d)\n", input, nNum);
	}

	curSeq = (int *) malloc(sizeof(int)*nNum);

	len = strlen(input);
	oppos = 0;
	while( (oppos < len) && (input[oppos] != '*') && (input[oppos] != '+')){
		oppos++;
	}

	if(oppos == len){
		/*base case*/
		tmpStr = strndup(input + 1, len - 2);
		operant = atoi(tmpStr);
		if(DEBUG){
			printf("operant=%d tmpStr=%s\n", operant, tmpStr);
		}
		free(tmpStr);
		for(i=0; i<nNum; i++){
			curSeq[i] = operant;
		}
		return curSeq;
	}

	operator = input[oppos];
	inputCut = strndup(input + oppos + 1, len - oppos -2);
	tmpStr = strndup(input + 1, oppos - 1); 
	operant = atoi(tmpStr);
	free(tmpStr);
	
	if(DEBUG){
			printf("operant=%d operator=%c\n", operant, operator);
	}
	returnSeq = findSeq(inputCut, nNum);	
	if(operator == '+'){
		curSeq[0] = operant;
		for(i=1; i<nNum; i++){
			curSeq[i] = curSeq[i-1] + returnSeq[i-1];
		}
	}
	else {
		curSeq[0] = operant * returnSeq[0];
		for(i=1; i<nNum; i++){
			curSeq[i] = curSeq[i-1] * returnSeq[i];
		}
	}
	if(DEBUG){
		printf("rtnSeq:");
		for(i=0; i<nNum; i++){
			printf("%d ", returnSeq[i]);
		}
		printf("\n");
		printf("curSeq:");
		for(i=0; i<nNum; i++){
			printf("%d ", curSeq[i]);
		}
		printf("\n");
	}
	free(returnSeq);
	return curSeq; 	
	
}

int main(){
	char *input;
	int nNum;
	int *output;
	
	input = (char *) malloc(MAX);	
	
	while(2 == scanf("%s %d",input, &nNum)){
		short i;		
		output = findSeq(input, nNum);
		
		
		printf("%d", output[0]);
		for(i=1; i<nNum; i++){
			printf(" %d", output[i]);
		}
		printf("\n");
		free(output);
	}
	
	free(input);
	return 0;
}