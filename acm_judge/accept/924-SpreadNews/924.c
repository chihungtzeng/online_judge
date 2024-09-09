#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXE 2500
#define MAXF 15
#define VISITED 1
#define UNVISISTED 0;

struct employee *e;
int nEmployee, src;

struct employee {
	int friend[MAXF];
	int nFriend;
};

void findAns(){
	int queue[nEmployee];
	short depth[nEmployee], visit[nEmployee], boom[nEmployee]; 
	int i,j,qhead,qtail;
	int trace, boomDay, boomSize;
	memset(depth, 0, sizeof(int)*nEmployee);
	memset(visit, 0, sizeof(int)*nEmployee);
	memset(queue, 0, sizeof(int)*nEmployee);
	memset(boom, 0, sizeof(int)*nEmployee);
	
	qhead = 0;
	qtail = 1;
	queue[qhead] = src;
	depth[src] = 0;
	visit[src] = VISITED;
			
	while(qhead < qtail){
		src = queue[qhead];
		for(i = 0; i < e[src].nFriend; i++){
			trace = e[src].friend[i];
			if(VISITED != visit[trace]){
				queue[qtail] = trace; 
				qtail++;
				depth[trace] = depth[src] + 1;
				boom[depth[trace]]++;
				visit[trace] = VISITED;
			}
		}
		qhead++;
	} 
	boomSize = 0;
	for(i = 0; i < nEmployee; i++){
		if(boom[i] > boomSize){
			boomSize = boom[i];
			boomDay = i;
		}
	}
	if(boomSize == 0){
		printf("0\n");
	}
	else {
		printf("%d %d\n",boomSize,boomDay);
	}
}

int main(){

	int i,j, nTest;
	
	e = (struct employee *) malloc(sizeof(struct employee)*MAXE);
	memset(e, 0, sizeof(struct employee)*MAXE);
	
	scanf("%d",&nEmployee);
	for(i=0; i < nEmployee; i++){
		scanf("%d", &e[i].nFriend);
		for(j = 0; j < e[i].nFriend; j++){
			scanf("%d", &e[i].friend[j]);
		}
	}
	scanf("%d",&nTest);
	for(i=0;i < nTest; i++){
		scanf("%d",&src);
		findAns();
	}
	return 0;
}