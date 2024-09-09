#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
#define LEN 8192

int main(){
	short degree[MAX], minDegree, n;
	char nTest;
	char line[LEN], *tok;
	short i, neighbor, ans[MAX], nAns;
	FILE *fp = stdin;
	
	fgets(line, LEN, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		memset(degree, 0, sizeof(short)*MAX);
		minDegree = 0x7f7f;
		fgets(line, LEN, fp);
		n = atoi(line);
		i=1;
		while(NULL != fgets(line, LEN, fp)){
			if((line[0] == ' ') || (line[0] == '\n')) break;
			tok = strtok(line, " \n");
			while(tok != NULL){
				degree[i] += 1;
				tok = strtok(NULL, " \n");
			}
			if(degree[i] < minDegree) minDegree = degree[i];
			i++;
		}
		nAns = 0;
		for(i=1; i<=n; i++){
			if(degree[i] == minDegree){
				ans[nAns++] = i;
			}
		}
		printf("%hd",ans[0]);
		for(i=1; i<nAns; i++){
			printf(" %hd",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

