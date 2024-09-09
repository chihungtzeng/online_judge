#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105
#define MAXFIB 0x7fffffff
#define DEBUG 0
#define LINELEN 10000

unsigned int fib[MAX];
short nFib;

void initFib(){
	fib[0] = 1;
	fib[1] = 1;
	nFib = 1;
	while((nFib < MAX) && (fib[nFib] <= (1 << 30))){
		nFib++;
		fib[nFib] = fib[nFib - 1] + fib[nFib - 2];
	}
	nFib++;
	if(DEBUG){
		int i;
		printf("%d numbers found\n", nFib);
		for(i=0; i<nFib; i++){
			printf("%d ", fib[i]);
		}
		printf("\n");
	}
}

short findFibIndex(unsigned int x){
	short index;
	index = nFib - 1;
	while((index > 0) && (fib[index] != x)){
		index--;
	}
	if(DEBUG){
		printf("%d has index %d\n",x, index);
	}
	return index;
}

int main(){
	char output[MAX], ciphertext[MAX];
	unsigned int inputSeq[MAX];
	char line[LINELEN];
	int nTest, nChar, i, len;
	short largestIndex, index, seqIndex;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	initFib();

	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	
	
	while(nTest >= 1){
		nTest--;
		memset(output, ' ', sizeof(char)*MAX);
		
		fgets(line, LINELEN, fp);
		nChar = atoi(line);
		fgets(line, LINELEN, fp);
		inputSeq[0] = atoi(strtok(line, " "));
		for(i=1; i<nChar; i++){
			inputSeq[i] = atoi(strtok(NULL, " "));
		}
		fgets(line, MAX, fp);
		len = 0;
		while( (line[len] != '\n') && (line[len] != EOF)){ 
			ciphertext[len] = line[len];
			len++;
		}
		ciphertext[len] = '\0';
		largestIndex = 0;
		index = 0;
		seqIndex = 0;
		for(i=0; (i<len) && (seqIndex < nChar); i++){
			if((ciphertext[i] >= 'A') && (ciphertext[i] <= 'Z')){
				index = findFibIndex(inputSeq[seqIndex]);
				seqIndex++;
				output[index] = ciphertext[i];
				if(index > largestIndex){
					largestIndex = index;
				}
			}
		}
		output[largestIndex + 1] = '\0';
		printf("%s\n", output + 1);
	}
	return 0;
}