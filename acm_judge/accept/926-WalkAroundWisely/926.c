/*NO AC for unknown reason*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define SOUTH 1
#define EAST 2
#define DEBUG 0
#define VERBOSE 0

struct cell{
	int pos;
	unsigned long long int nPath;
	int nNeighbor;
	int neighbor[2];
};

int start, end, nRow;

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}


void findAns(struct cell *street){
	int i,j;
	int head, tail, *match;
	int src, target;
	int queue[MAX*MAX];
	short color[MAX*MAX];
	
	memset(color, 0, sizeof(short)*MAX*MAX);
	
	street[start].nPath = 1;
	color[start] = 1;
	head = 0;
	tail = 1;
	queue[head] = start;
	
	while(head < tail){
		src = queue[head++];
		for(i = 0; i<street[src].nNeighbor; i++){
			target = street[src].neighbor[i];
			street[target].nPath += street[src].nPath;
			if(color[target] == 0){
				color[target] = 1;
				queue[tail++] = target;
			}
		}
	}
}

void removeNeighbor(struct cell *e, int del){
	if(e->neighbor[0] == del){
		e->neighbor[0] = e->neighbor[e->nNeighbor - 1];
		e->nNeighbor -= 1;
	}
	else if (e->neighbor[1] == del){
		e->nNeighbor -= 1;
	}
}

int main(){
	int nTest;
	int nObstacle;
	int i,j,k,target;
	char ch;
	struct cell *street;
	FILE *fp;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else {
		fp = stdin;
	}
	
	fscanf(fp, "%d",&nTest);
	street = (struct cell *) malloc(sizeof(struct cell)*MAX*MAX);
	
	while(nTest >= 1){
		nTest--;
		memset(street, 0, sizeof(struct cell)*MAX*MAX);
		fscanf(fp,"%d",&nRow);
		
		for(i=0;i<nRow-1;i++){
			for(j=1;j<nRow;j++){
				target = i*nRow + j; 
				street[target].nNeighbor = 2;
				street[target].neighbor[0] = target - 1;
				street[target].neighbor[1] = target + nRow;
			}
			target = i*nRow;
			street[target].nNeighbor = 1;
			street[target].neighbor[0] = target + nRow;
		}
		for(j=1; j<nRow; j++){
			target = (nRow - 1) *nRow + j;
			street[target].nNeighbor = 1;
			street[target].neighbor[0] = target - 1;
		}

		fscanf(fp,"%d %d", &i, &j);
		end = (nRow - j)*nRow + i - 1;
		fscanf(fp,"%d %d", &i, &j);
		start = (nRow-j)*nRow + i - 1;
		if(DEBUG){
			printf("start:%d end:%d\n",start, end);
		}
		fscanf(fp,"%d", &nObstacle);
		for(i = 0; i<nObstacle; i++){
			fscanf(fp, "%d %d %c",&j, &k, &ch);
			target = (nRow- k )*nRow + j - 1;
			if((ch == 'S')&&(j>=1) &&(j<=nRow)&&(k>1)&&(k<=nRow)){
				removeNeighbor(&street[target], target + nRow);
				
			}
			else if((ch == 'E')&&(j>=1) &&(j<nRow)&&(k>=1)&&(k<=nRow)){
				removeNeighbor(&street[target+1], target);
				
			}
			else if ((ch == 'W')&&(j>1) &&(j<=nRow)&&(k>=1)&&(k<=nRow)){
				removeNeighbor(&street[target], target-1);
			}
			else if ((ch == 'N')&&(j>=1) &&(j<=nRow)&&(k>=1)&&(k<nRow)){
				removeNeighbor(&street[target - nRow], target);
			}
		}

		findAns(street);
		printf("%llu\n",street[end].nPath);
		if(DEBUG){
			for(i=0;i<nRow;i++){
				for(j=0;j<nRow;j++){
					target = i*nRow + j;
					printf("street %d: %d neighbors: %d %d, nPath=%llu\n", target, street[target].nNeighbor, street[target].neighbor[0], street[target].neighbor[1], street[target].nPath);
				}
			}
		}		
		if(VERBOSE){
			for(i=nRow;i>=1;i--){
				for(j=1; j<=nRow;j++){
					target = (nRow-j)*nRow + i - 1;
					printf("%llu ", street[target].nPath);
				}
				printf("\n");
			}
		}
		
	}	
	free(street);	
	return 0;
}