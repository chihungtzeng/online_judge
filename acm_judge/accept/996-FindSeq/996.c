#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51
#define SEQLEN 2048
#define FOUND 1
#define NOANSWER -1
#define PLAUSIBLE 1
#define YES 2
#define NO -1
#define PLUS 1
#define MULTIPLY 2
#define TODECIDE ((1 << 30) - 35)
#define DEBUG 0

int M, N;
int seq[MAX][MAX];
int operation[MAX];


int seqFromMultiply(int stage){
	int i;
	for(i=1; i<N; i++){
		if( (seq[stage][i] != TODECIDE) && 
			(seq[stage][i] != TODECIDE) &&
			(seq[stage][i-1] != 0)){
			
			if (seq[stage][i] % seq[stage][i-1] != 0){
				return NO;
			}
		}
	}
	return PLAUSIBLE;
}

int ifBaseCase(int stage, int *operant){
	int i;
	*operant = TODECIDE;
	for(i=0; i < N - 1; i++){
		if((seq[stage][i] != TODECIDE)){		
			*operant = seq[stage][i];
			if((seq[stage][i+1] != TODECIDE) && (seq[stage][i+1] != seq[stage][i])){
				return NO;
			}
		}
	}
	if(*operant == TODECIDE){
		return NO;
	} 
	else{
		return YES;
	}
}

void fillSeqForStage(int stage, int operation){
	int i, nextStage;
	nextStage = stage + 1;
	if(operation == MULTIPLY){
		i = 0;
		while(seq[stage][i] == TODECIDE){
			i++;
		}
		i--;
		for(; i>=0; i--){
			seq[stage][i] = (seq[nextStage][i+1] == 0)?
				0 : seq[stage][i+1] / seq[nextStage][i+1];
		}
		i = N - 1;
		while(seq[stage][i] == TODECIDE){
			i--;
		} 
		i++;
		for(; i < N; i++){
			seq[stage][i] = seq[stage][i-1] * seq[nextStage][i];
		}
	}
	else if (operation == PLUS){
		i = 0;
		while(seq[stage][i] == TODECIDE){
			i++;
		}
		i--;
		for(; i>=0; i--){
			seq[stage][i] = seq[stage][i+1] - seq[nextStage][i];
		}
		i = N - 1;
		while(seq[stage][i] == TODECIDE){
			i--;
		}
		i++;
		for(; i<N;i++){
			seq[stage][i] = seq[stage][i-1] + seq[nextStage][i-1]; 
		}
	}
	else {
		printf("undefined operation\n");
	}
}

int findSeq(char *output, int stage){
	char *preOutput;
	int state = NOANSWER;
	int operant;
	int i, preStage, nextStage;
	if(DEBUG){
		printf("enter stage %d\n",stage);
	}
	if(stage > M){
		if(DEBUG){
			printf("stage has exceeded max. threshold M = %d\n",M);
		}
		return NOANSWER;
	}
	
	/*
		Check if it is a base case
	*/
	preStage = stage - 1;
	nextStage = stage + 1;
	
	if (ifBaseCase(preStage, &operant) == YES){		
		for(i=0; i < N; i++){
			seq[preStage][i] = operant;
		} 
		sprintf(output, "[%d]", operant);
		return FOUND;
	}	
	

	if(seqFromMultiply(preStage) == PLAUSIBLE){
		if(DEBUG){
			printf("enter mulitplication at stage %d\n", stage);
		}
		seq[stage][0] = TODECIDE;
		for(i=1; i<N; i++){
			if((seq[preStage][i] != TODECIDE) && (seq[preStage][i-1] != TODECIDE)){
				seq[stage][i] =  (seq[preStage][i-1] == 0)? 
					0 : seq[preStage][i] / seq[preStage][i-1];
			}
			else{
				seq[stage][i] = TODECIDE;
			}
		}

		state = findSeq(output, nextStage);
		if (state == FOUND){
			fillSeqForStage(preStage, MULTIPLY);
			preOutput = strdup(output);
			sprintf(output, "[%d*%s]", 
				(seq[stage] == 0)? 0 : seq[preStage][0]/seq[stage][0], 
				preOutput);
			free(preOutput);
			return FOUND;
		}

	} 
	/*Multiplication is impossible, try addition*/
	seq[stage][N-1] = TODECIDE;
	for(i=0; i<N-1; i++){
		if((seq[preStage][i] != TODECIDE) && (seq[preStage][i+1] != TODECIDE)){
			seq[stage][i] = seq[preStage][i+1] - seq[preStage][i];
		} 
		else{
			seq[stage][i] = TODECIDE;
		}
	}

	
	state = findSeq(output, nextStage);
	if((state == FOUND)){
		fillSeqForStage(preStage, PLUS);
		preOutput = strdup(output);
		sprintf(output, "[%d+%s]", seq[preStage][0], preOutput);
		free(preOutput);
		return FOUND;
	}
	else{
		return NOANSWER;
	}
	
}

int main(){
	char line[1024];
	char *tok;
	char *output;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	output = (char *) malloc(sizeof(char)*SEQLEN);
		
	while(NULL != fgets(line, 1024, fp)){
		short i, done, state;
		
		tok = strtok(line, " ");
		M = atoi(tok);
		N = 0;
		done = 0;
		while(!done){
			tok = strtok(NULL, " ");
			if((tok == NULL) || (tok[0] == ' ') || (tok[0] == '\n')){
				done = 1;
			}
			else{
				seq[0][N++] = atoi(tok);
			}
		}
		for(i=0; i<N; i++){
			seq[1][i] = TODECIDE;
		}

		if(DEBUG){
			for(i=0; i<N;i++){
				printf("%d ", seq[0][i]);
			}
			printf("M=%d N=%d\n", M, N);
		}		
		
		state = findSeq(output, 1);
		if (state == FOUND){
			printf("%s\n", output);
		}
		else {
			printf("[0]\n");
		}
	}
	free(output);
	return 0;
}