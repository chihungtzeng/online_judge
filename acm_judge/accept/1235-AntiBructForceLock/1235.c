#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 510

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int calcEdgeWeight(char *t1, char *t2){
	int result = 0;
	int tmp;
	while(*t1 != '\0'){
		tmp = abs(*t1 - *t2);
		result += min(tmp, 10 - tmp);
		t1++;
		t2++;
	}	
	return result;
}

void calcCostMatrix(int nNode, char **token, char **edgeCost){
	int i, j;
	for(i=0; i<=nNode; i++){
		edgeCost[i][i] = 0;
		for(j=0; j<i; j++){
			edgeCost[i][j] = calcEdgeWeight(token[i], token[j]);
			edgeCost[j][i] = edgeCost[i][j];
		}
	}
	#if 1
	for(i=0; i<=nNode; i++){
		for(j=0; j<=nNode; j++){
			printf("%2hhd ", edgeCost[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	#endif
}

int main(){
	int nTest;
	int i;
	int nNode;
	char **edgeCost;
	FILE *fp = stdin;
	char **token;
		
	
	
	edgeCost = (char **) malloc(sizeof(char *)*MAX);
	token = (char **) malloc(sizeof(char *)*MAX);
	for(i=0; i<MAX; i++){
		edgeCost[i] = (char *) malloc(sizeof(char)*MAX);
		token[i] = (char *) malloc(5);
	}	
	
	fscanf(fp, "%d", &nTest);
	strcpy(token[0], "0000");
	while(nTest--){
		fscanf(fp, "%d", &nNode);
		for(i=1; i<=nNode; i++){
			fscanf(fp, "%s", token[i]);
		}
		calcCostMatrix(nNode, token, edgeCost);
		
	}

	

	for(i=0; i<MAX; i++){
		free(edgeCost[i]);
	}
	free(edgeCost);
	
	return 0;
}