#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LEN 501
#define DEBUG 0
#define LINELEN 1024000

struct Entry {
	short next;
	short weight; 
};

char *flag;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

void calcLIS(struct Entry seq[], short nDish, short dish[]){
	/*
	find LIS and LDS (depending on the function pointer compr. 
	seq[i].weight = k means the LIS/LDS starting from i has length k 
	*/
	short i, j;
	for(i=nDish - 1; i>=0; i--){
		seq[i].weight = 1;
		seq[i].next = -1;
		for(j=nDish - 1; j>i; j--){
			if((dish[j] >= dish[i]) && (seq[j].weight + 1 > seq[i].weight)){
				seq[i].weight = seq[j].weight + 1;
				seq[i].next = j;
			}
		}
	}
}

void calcLDS(struct Entry seq[], short nDish, short dish[]){
	/*
	find LIS and LDS (depending on the function pointer compr. 
	seq[i].weight = k means the LIS/LDS starting from i has length k 
	*/
	short i, j;
	for(i=nDish - 1; i>=0; i--){
		seq[i].weight = 1;
		seq[i].next = -1;
		for(j=nDish - 1; j>i; j--){
			if((dish[j] <= dish[i]) && (seq[j].weight + 1 > seq[i].weight)){
				seq[i].weight = seq[j].weight + 1;
				seq[i].next = j;
			}
		}
	}
}

short pickDishAt(short start, short nDish, short dish[], struct Entry LIS[], struct Entry LDS[]){
	short i, j;
	short cur, result;
	short indexArray[1024], nIndex =0;
	short target;

	cur = start;
	while(LIS[cur].next != -1){
		indexArray[nIndex++] = LIS[cur].next;
		cur = LIS[cur].next;
	}
	cur = start;
	while(LDS[cur].next != -1){
		indexArray[nIndex++] = LDS[cur].next;
		cur = LDS[cur].next;
	}
	
	if(nIndex == 0) return 0;
	qsort(indexArray, nIndex, sizeof(short), compareShort);
	for(result = 1, i=1; i<nIndex; i++){
		if(indexArray[i] != indexArray[i-1]) result++;
	}
	
	#if DEBUG
	printf("%hd ", dish[start]);
	for(i=0; i<nIndex; i++){
		if(indexArray[i] != indexArray[i-1]){
			printf("%hd ", dish[indexArray[i]]);
		}
	}
	printf("\n");
	#endif
	
	return result;
}

void solve(short nDish, short dish[]){
	short result, nPick, i;
	struct Entry LIS[nDish], LDS[nDish];
	
	calcLIS(LIS, nDish, dish);
	calcLDS(LDS, nDish, dish);
	
	#if DEBUG
	printf("LIS\n");
	for(i=0; i<nDish; i++){
		printf("[%hd] dish %hd: weight=%hd, next=%hd\n", i, dish[i], LIS[i].weight, LIS[i].next);
	}
	printf("LDS\n");
	for(i=0; i<nDish; i++){
		printf("[%hd] dish %hd: weight=%hd, next=%hd\n", i, dish[i], LDS[i].weight, LDS[i].next);
	}
	#endif 
	
	for(i=0, result=-1; i<nDish; i++){
		nPick = pickDishAt(i, nDish, dish, LIS, LDS);
		if(nPick > result){
			result = nPick;
			#if DEBUG
			printf("update ans at index %hd\n", i);
			#endif
		}
	}
	printf("%hd\n", result + 1);
}

int main(){
	short nDish;
	short dish[LEN];
	short i;
	FILE *fp = stdin;
	
	
	
	while(1 == fscanf(fp, "%hd", &nDish)){
		if(0 == nDish) break;
		for(i=0; i<nDish; i++){
			fscanf(fp, "%hd", dish + i);
		}
		solve(nDish, dish);
	}
	
	return 0;
}