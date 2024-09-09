#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10010
#define LEN 1000000

int coef[MAX];
int quotien[MAX];
int k, nCoef;


void findAns(){
	int i, iub;
	iub = nCoef - 1;
	for(i=0; i< iub; i++){
		quotien[i] = coef[i];
		coef[i+1] = coef[i+1] + k * quotien[i];
	}
	printf("q(x):");
	for(i=0; i<iub; i++){
		printf(" %d",quotien[i]);
	}
	printf("\n");
	printf("r = %d\n\n",coef[nCoef - 1]);
}

int main(){
	char *line;
	char *tok;
	
	int i;
	
	line = (char *)malloc(sizeof(char)*LEN);
	while(NULL != fgets(line, LEN, stdin)){
		k = atoi(line);
		fgets(line, LEN, stdin);
		nCoef = 0;
		tok = strtok(line, " \n");
		while(tok != NULL){
			coef[nCoef++] = atoi(tok);
			tok = strtok(NULL, " \n");
		}
		findAns();
	}
	return 0;
}