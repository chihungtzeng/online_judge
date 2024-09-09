#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define MAX 30001


 
long long *exchange;
int unit[] = {50, 25, 10, 5, 1};

void buildTable(){
	int i, j;
	memset(exchange, 0, sizeof(long long)*MAX);
	exchange[0] = 1;
	for(i=0; i<5; i++){
		for(j=unit[i]; j<MAX; j++){
			exchange[j] += exchange[j - unit[i]];
		}
	}
}

int main(){
	int nCent;
	
	FILE *fp = (DEBUG)? fopen("in.txt", "r") :stdin;

	exchange = (long long *) malloc(sizeof(long long)*MAX);
	buildTable();
	
	while(1 == fscanf(fp, "%d", &nCent)){
		if(exchange[nCent] > 1){
			printf("There are %lld ways to produce %d cents change.\n", exchange[nCent], nCent);
			
		} else {
			printf("There is only 1 way to produce %d cents change.\n", nCent);
		}
	}
	free(exchange);
	return 0;
}