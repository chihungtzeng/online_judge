#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX 5001
#define DEBUG 0
#define BLACK 1
#define WHITE 0

struct Specie{
	char name[32];
	short id;
	short *preyList;
	short nPrey;
	short preyCapacity;
};

void freeSpecie(struct Specie *s){
	assert(s != NULL);
	free(s->preyList);
}

int compareSpecie(const void *a, const void *b){
	struct Specie *x, *y;
	x = (struct Specie *)a;
	y = (struct Specie *)b;
	return strcmp(x->name, y->name);
}

void addPreyList(struct Specie *prey, struct Specie *predator){
	assert(NULL != prey);
	assert(NULL != predator);
	if(predator->nPrey == predator->preyCapacity){
		predator->preyCapacity <<= 1;
		predator->preyList = (short *) realloc(predator->preyList, sizeof(short)*predator->preyCapacity); 
	}
	predator->preyList[predator->nPrey++] = prey->id;
}

void dumpInfo(struct Specie specie[], short nSpecie){
	short i, j;
	short targetId;
	struct Specie *target;
	for(i=0; i<nSpecie; i++){
		printf("%s **", specie[i].name);
		for(j=0; j<specie[i].nPrey; j++){
			targetId = specie[i].preyList[j];
			printf("%s ", specie[targetId].name);
		}
		printf("\n");
	}
}

short DFS(short src, struct Specie specie[], short nSpecie, char color[]){
	short ans = 1;
	short i, target;
	color[src] = BLACK;
	for(i=0; i<specie[src].nPrey; i++){
		target = specie[src].preyList[i];
		if(color[target] == WHITE){
			ans += DFS(target, specie, nSpecie, color);
		}
	}
	return ans;
}

short findAns(struct Specie specie[], short nSpecie){
	char color[nSpecie];
	short i, groupSize;
	short ans = -1;
	
	memset(color, WHITE, nSpecie);
	for(i=0; i<nSpecie; i++){
		if(color[i] == WHITE){
			groupSize = DFS(i, specie, nSpecie, color);
			if(groupSize > ans) ans = groupSize;
		}
	}
	return ans;
}

/*
short findAns(struct Specie specie[], short nSpecie){
	short ans = 0;
	short inDegree[nSpecie], total[nSpecie];
	short queue[nSpecie], head=0, tail=0;
	short i, j, targetId, cur;
	
	
	memset(inDegree, 0, sizeof(short)*nSpecie);

	memset(total, 0, sizeof(short)*nSpecie);
	
	for(i=0; i<nSpecie; i++){
		for(j=0; j<specie[i].nPrey; j++){
			targetId = specie[i].preyList[j];
			inDegree[targetId] += 1;
		}
	}
	for(i=0; i<nSpecie; i++){
		if(inDegree[i] == 0){
			queue[tail++] = i;
		}
	}
	while(head < tail){
		cur = queue[head++];
		for(i=0; i<specie[cur].nPrey; i++){
			targetId = specie[cur].preyList[i];
			inDegree[targetId] -= 1;
			total[targetId] = total[targetId] + total[cur] + 1;
			if(0 == inDegree[targetId]){
				queue[tail++] = targetId;				
			}
		}
	}
	for(i=0; i<nSpecie; i++){
		if(total[i] > ans) ans = total[i];
	}
	if(DEBUG){
		for(i=0; i<nSpecie; i++){
			printf("%s %hd\n", specie[i].name, total[i]);
		}
	}
	return ans + 1;
}
*/

int main(){
	short nSpecie, nRelation;
	short i;
	FILE *fp;
	struct Specie query, *predator, *prey;
	struct Specie specie[MAX];
	short ans;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;	
	
	while(2 == fscanf(fp, "%hd %hd", &nSpecie, &nRelation)){		
		if((nSpecie == 0) && (nRelation == 0)) return 0;
		for(i=0; i<nSpecie; i++){
			fscanf(fp, "%s", specie[i].name);
		}
		qsort(specie, nSpecie, sizeof(struct Specie), compareSpecie);
		for(i=0; i<nSpecie; i++){
			specie[i].nPrey = 0;
			specie[i].preyCapacity = 8;
			specie[i].id = i;
			specie[i].preyList = (short *) malloc(sizeof(short)*specie[i].preyCapacity);
		}
		for(i=0; i<nRelation; i++){
			fscanf(fp, "%s", query.name);
			prey = bsearch(&query, specie, nSpecie, sizeof(struct Specie), compareSpecie);
			
			fscanf(fp, "%s", query.name);
			predator = bsearch(&query, specie, nSpecie, sizeof(struct Specie), compareSpecie);
			
			addPreyList(prey, predator);
			addPreyList(predator, prey);
		}
		if(DEBUG){
			/*dumpInfo(specie, nSpecie);*/
		}
		ans = findAns(specie, nSpecie);
		printf("%hd\n", ans);
		for(i=0; i<nSpecie; i++){
			freeSpecie(specie + i);
		}
	}
	return 0;
}