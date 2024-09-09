#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define DEBUG 1
#define VERBOSE 1

int fac[MAX];

char **findPermutation(char *input){
	char ch, tmpch;
	char **tmpOutput[MAX], **output;
	char *tmpInput, *inputCopy;
	int i,j,k, start, end, pos, target = 0;
	int nTmpOutput, nOutput;
	int inputLen;
	
	if(input == NULL){
		printf("input string is null\n");
		return NULL;
	}
	inputLen = strlen(input);
	
	nTmpOutput = fac[inputLen - 1];
	nOutput = fac[inputLen];
	
	if(inputLen < 0 ){
		return NULL; 
	}
	
	output = (char **) malloc(sizeof(char *)*nOutput);
	if(output == NULL){
		printf("insufficient memory\n");
		exit(0);
	}
	if(VERBOSE){
		printf("allocate %d strings for input %s\n", nOutput, input);
	}

	

	for(i = nOutput - 1; i>=0; i--){
		output[i] = (char *) malloc(sizeof(char)*MAX);
	}
	if(inputLen == 1){
		strcpy(output[0], input);
		return output;
	}

	if(inputLen == 2){
		output[0], input
		return 
	}

	inputCopy = strdup(input);
	tmpInput = (char *) malloc(sizeof(char)*MAX);
	for(i=0; i<inputLen;i++){
		
		tmpch = inputCopy[0];
		inputCopy[0] = inputCopy[i];
		inputCopy[i] = tmpch;
		
		ch = inputCopy[0];
		strcpy(tmpInput, inputCopy + 1);

		tmpOutput[i] = findPermutation(tmpInput);
		/*generate output*/
		if(VERBOSE){
			printf("input:%s generate following %d permutations\n", tmpInput, nTmpOutput);
			for(j=0; j<nTmpOutput; j++){
				printf("=== %s ===\n",tmpOutput[i][j]);
			}
		}
	}
	
	for(i=0; i<inputLen; i++){
		ch = input[i];
		for(j=0; j < nTmpOutput; j++){
			output[target][0] = ch;
			strcpy(&output[target][1], tmpOutput[i][j]);
			for(k = 0; k < inputLen - 1; k++){
				target++;
				strcpy(output[target], output[target - 1]);
				tmpch = output[target][j];
				output[target][j] = output[target][j + 1];
				output[target][j + 1] = tmpch;
			}
		}
	}
	/*
		for(i = nTmpOutput - 1; i >= 0; i--){
			free(tmpOutput[i]);
		}
		free(tmpOutput);
	}
*/

	free(tmpInput);
	free(inputCopy);
	return output;
} 


int main(){
	char first = 1;
	char line[MAX];
	char **output;
	int len, i;	
	FILE *fp;	
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	fac[0] = 1;
	fac[1] = 1;
	for(len = 2; len < MAX; len++){
		fac[len] = fac[len-1]*len;
	}
	
		
	while(EOF != fscanf(fp, "%s", line)){
		if(first == 1){
			first = 0;
		}
		else {
			printf("\n");
		}
		len = strlen(line);
		if(VERBOSE){
			printf("input string: %s len: %d\n",line, len);
		}

		output = NULL; 
		output = findPermutation(line);
		if(output != NULL){
			for(i=0; i<fac[len]; i++){
				printf("%s\n", output[i]);
			}
			for(i=fac[len] - 1; i>=0; i--){
				free(output[i]);
			}
			free(output);
		}
		

	}
	
	
	return 0;
}