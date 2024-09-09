#include <stdio.h>
#include <string.h>
#define MAX 26
#define QSIZE 1024
#define DEBUG 0

struct point {
	short x, y;
};

char transTable[2][MAX];
char diff[MAX][MAX];
char initState[MAX];
short nState;

void optimizeState(){
	struct point queue[QSIZE], nextQueue[QSIZE];
	short nQS = 0, nNQS = 0;
	char progress;
	short i, j;
	for(i=0; i<nState; i++){
		for(j=i+1; j<nState; j++){
			if(diff[i][j] == 0){
				queue[nQS].x = i;
				queue[nQS].y = j;
				nQS++;
			}
		}
	}
	progress = 1;
	while(progress){
		char a; /*a is the input for the states*/
		char nsi, nsj;
		char split;
		progress = 0;
		nNQS = 0;
		while(nQS >= 1){
			nQS--;
			i = queue[nQS].x;
			j = queue[nQS].y;
			split = 0;
			/**/
			for(a = 0; (a<2) && (!split); a++){
				nsi = transTable[a][i];
				nsj = transTable[a][j];
				if((diff[nsi][nsj] == 1) || (diff[nsj][nsi] == 1)){
					diff[i][j] = 1;
					split = 1;
					progress = 1;
				}
			}
			if(!split){
				nextQueue[nNQS].x = i;
				nextQueue[nNQS].y = j;
				nNQS++;
			}
		}
		memcpy(queue, nextQueue, sizeof(struct point)*QSIZE);
		nQS = nNQS; 
	}
	
}

int main(){
	short i, j;
	char s[2], s0[2], s1[2], ifInitState[2];
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	while(1 == fscanf(fp, "%hd", &nState)){
		/*Initially, all states are indistinguishable*/
		memset(transTable, 0, MAX << 1);
		memset(diff, 0, MAX*MAX);
		memset(initState, 0, MAX);
		
		for(i=0; i< nState; i++){
			fscanf(fp, "%s %s %s %s", s, s0, s1, ifInitState);
			transTable[0][s[0]-'A'] = s0[0] - 'A';
			transTable[1][s[0]-'A'] = s1[0] - 'A';
			if(ifInitState[0] == 'w'){
				initState[s[0] - 'A'] = 1;
			}
		}
		for(i=0; i<nState; i++){
			for(j=i+1; j<nState; j++){
				if(initState[i] != initState[j]){
					diff[i][j] = 1;
				}
			}
		}
		optimizeState();
		if(DEBUG){
			for(i=0; i<nState; i++){
				for(j=0; j<nState; j++){
					printf("%d ",diff[i][j]);
				}
				printf("\n");
			}
		}
		char redandant;
		printf("A");
		for(i=1; i<nState; i++){
			redandant = 0;
			for(j=0; (j<i) && (!redandant) ; j++){
				if(diff[j][i] == 0){
					redandant = 1;
				}
			}
			if(!redandant){
				printf(" %c", i + 'A');
			}
			
		}
		printf("\n");
	}
	return 0;
}