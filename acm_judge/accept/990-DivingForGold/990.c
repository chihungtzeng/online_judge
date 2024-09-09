#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXT 30
#define YES 1
#define NO 0
#define DEBUG 0

struct treasure {
	int id;
	int depth;
	int cost;
	int gold;
	short isDive; 
};

int t, w, nTreasure;
struct treasure *tSet;
int goldRecover, nDive;

int compareTreasureByID(const void *a, const void *b){
	struct treasure x, y;
	x = *(struct treasure *)a;
	y = *(struct treasure *)b;
	return x.id - y.id;
}

int compareTreasureByDensity(const void *a, const void *b){
	struct treasure *x, *y;
	x = (struct treasure *)a;
	y = (struct treasure *)b;
	if (x->id > y->id) return 1;
	else if(x->id < y->id) return -1;
	else return 0;
}

void findAns(struct treasure *tSetin, int air, int nT){
	struct treasure *tSetClone;
	int i, j;
	int recover=0, diveCount=0;

	if(NULL == tSetin){	
		printf("tSetin is NULL\n");
		exit(0);
	}

	if((nT <= 0) || (air <= 0)){
		for(i=0;i<nTreasure; i++){
			if(tSetin[i].isDive == YES){
				recover += tSetin[i].gold;
				diveCount++;
			}
		}
		if(recover > goldRecover){
			memcpy(tSet, tSetin, sizeof(struct treasure)*MAXT);
			nDive = diveCount;
			goldRecover = recover;
		}
		return ;
	}

	tSetClone = (struct treasure *) malloc(sizeof(struct treasure)*MAXT);
	memcpy(tSetClone, tSetin,  sizeof(struct treasure)*MAXT);
	if (tSetin[nT - 1].cost <= air){
		if(!tSetClone){
			printf("allocate memory failed\n");
			exit(0);
		}				
		tSetClone[nT - 1].isDive = YES;
		findAns(tSetClone, air - tSetClone[nT - 1].cost, nT - 1 );
	}
	tSetClone[nT - 1].isDive = NO;
	findAns(tSetClone, air, nT - 1);
	free(tSetClone);
	
		
	
	return ;
}


int main(){
	int i, first;
	int d, g;
	FILE *fp;
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}
	tSet = (struct treasure *) malloc(sizeof(struct treasure)*MAXT);
	first = 1;
	while ( 3 == fscanf(fp, "%d %d %d", &t, &w, &nTreasure)){
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		goldRecover = -1;
		memset(tSet, 0, sizeof(struct treasure)*MAXT);
		for(i=0; i < nTreasure; i++){
			fscanf(fp, "%d %d", &d, &g);
			tSet[i].depth = d;
			tSet[i].cost = 3*d*w;
			tSet[i].gold = g;
			if(DEBUG){
				printf("treasure %d: depth %d gold: %d\n",i,tSet[i].depth, tSet[i].gold);
			} 
		}		
		findAns(tSet, t, nTreasure);
		printf("%d\n%d\n",goldRecover, nDive);
		for(i=0;i<nTreasure;i++){
			if(tSet[i].isDive == YES){
				printf("%d %d\n",tSet[i].depth, tSet[i].gold);
			}
		}
	}
	
	free(tSet);
	return 0;
}