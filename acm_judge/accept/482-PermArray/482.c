#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000
#define MAXLEN 1000
#define LINELEN 1000000
#define DEBUG 0

int main(){
	char **input;
	char **output;
	int index[MAX], nIndex, i, target;
	int nTest;
	char line[LINELEN];
	char *tok, first=1;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;

	output = (char **) malloc(sizeof(char *)*MAX);
	input = (char **) malloc(sizeof(char *)*MAX);
	for(i=0; i<MAX; i++){
		output[i] = (char *) malloc(MAXLEN);
		input[i] = (char *) malloc(MAXLEN);
	}	
	
	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	
	while(nTest >= 1){
		nTest--;
		/*the empty line*/
		fgets(line, LINELEN, fp);
		/*index line*/
		if(fgets(line, LINELEN, fp) == NULL) break;
		nIndex = 1;
		tok = strtok(line, " \n");
		while(tok != NULL){
			index[nIndex++] = atoi(tok);
			tok = strtok(NULL, " \n");
		}
		/*array contents*/
		if(fgets(line, LINELEN, fp) == NULL) break;
		nIndex = 1;
		tok = strtok(line, " \n");
		while(tok != NULL){
			strcpy(input[nIndex++], tok);
			tok = strtok(NULL, " \n");
		}

		
		for(i=1; i<nIndex; i++){
			target = index[i];
			strcpy(output[target], input[i]);
		}
		if(first){
			first= 0;
		}
		else{
			puts("");
		}
		for(i=1; i<nIndex; i++){
			puts(output[i]);
		}
	}
	for(i=0; i<MAX; i++){
		free(output[i]);
		free(input[i]);
	}	
	free(input);
	free(output);
	return 0;
}