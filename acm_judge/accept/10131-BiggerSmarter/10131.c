#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

struct Elephant{
	short i;
	short IQ, weight;
	short sn;
};

int compareElephant(const void *a, const void *b){
	struct Elephant *x, *y;
	x = (struct Elephant *)a;
	y = (struct Elephant *)b;
	if(x->IQ != y->IQ) return y->IQ - x->IQ;
	else return x->weight - y->weight;
}

void LIS(int nElephant, struct Elephant elephant[]){
	short best[MAX];
	short parent[MAX];
	short i, j;
	short max = 0, idx;
	short ans[MAX];
	
	memset(parent, 0xff, sizeof(short)*MAX);
	for(i=0; i<nElephant; i++){
		best[i] = 1;
	}
	
	for(i=1; i<nElephant; i++){
		for(j=0; j<i; j++){
			if( (elephant[i].weight > elephant[j].weight) && (elephant[i].IQ != elephant[j].IQ) && (best[i] < best[j] + 1)){
				best[i] = best[j] + 1;
				parent[i] = j;
			}
		}
	}
	
	for(i=0; i<nElephant; i++){
		if(best[i] > max){
			max = best[i];
			idx = i;
		}
	}
	i=0;
	while(parent[idx] != -1){
		ans[i++] = elephant[idx].sn;
		idx = parent[idx];
	}
	ans[i++] = elephant[idx].sn;
	printf("%hd\n",i);
	for(j=i-1; j>=0; j--){
		printf("%hd\n",ans[j]);
	}
}


int main(){
	int nElephant = 0;
	int i;
	struct Elephant elephant[MAX];
	while(2 == scanf("%hd %hd", &elephant[nElephant].weight, &elephant[nElephant].IQ)){
		elephant[nElephant].sn = nElephant + 1;
		nElephant++;
	}
	
	qsort(elephant, nElephant, sizeof(struct Elephant), compareElephant);
	/*
	for(i=0; i<nElephant; i++){
		printf("%hd %hd %hd\n",elephant[i].sn,elephant[i].weight,elephant[i].IQ);
	}
	*/
	LIS(nElephant, elephant);
	return 0;
}