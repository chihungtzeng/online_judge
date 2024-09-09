/*WA*/
#include <stdio.h>
#include <string.h>
#define MAX 1025
#define MAX_LEVEL 11
#define TRUE 1
#define FALSE 0
#define DEBUG 0

#define PARENT(x) ((x) >> 1)

int nPeople[MAX_LEVEL];

int calcWalkOver(int treeHeight, char withdraw[]){
	char withdrawBackup[MAX];
	int i, level;	
	int nWalkOver = 0;
	memset(withdrawBackup, FALSE, MAX);
	for(level = treeHeight; level >= 1; level--){
		for(i=1; i<=nPeople[level]; i += 2){
			if(withdraw[i] ^ withdraw[i + 1] == TRUE){
				nWalkOver++;
			}
			withdrawBackup[PARENT(i)] = (withdraw[i] & withdraw[i+1])? TRUE : FALSE;
		}
		memcpy(withdraw, withdrawBackup, nPeople[level]);
		memset(withdrawBackup, FALSE, MAX);
	}
	return nWalkOver;
}

int main(){
	int nTest;
	int nWithdraw, treeHeight;
	int i, tmp;
	char withdraw[MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	
	for(i=0; i<MAX_LEVEL; i++){
		nPeople[i] = (1 << i);
	}
	

	fscanf(fp, "%d", &nTest);
	while(nTest--){
		fscanf(fp, "%d %d", &treeHeight, &nWithdraw);
		memset(withdraw, FALSE, MAX);
		for(i=0; i<nWithdraw; i++){
			fscanf(fp, "%d", &tmp);
			withdraw[tmp] = TRUE;
		}
		printf("%d\n", calcWalkOver(treeHeight, withdraw));
	}	
	return 0;
}
