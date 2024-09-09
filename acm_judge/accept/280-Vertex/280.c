#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2048
#define DEBUG 0

struct Vertex{
	short degree;
	short neighbor[MAX];
};

short nV;
struct Vertex V[MAX];

void findAns(short src){
	/*Use DFS to find those unreachable*/
	char reachable[MAX];
	short stack[MAX], top, visit;
	short ans[MAX], nAns;
	short i, target, cur;
	memset(reachable, 0, sizeof(char)*MAX);
	
	stack[0] = src;
	top = 0;
	while(top >= 0){
		cur = stack[top--];
		for(i=0; i<V[cur].degree; i++){
			target = V[cur].neighbor[i];
			if(reachable[target] == 0){
				reachable[target] = 1;
				top++;
				stack[top] = target;
			}
		}
	}
	nAns = 0;
	for(i=1; i<=nV; i++){
		if(reachable[i] == 0){
			ans[nAns++] = i;
		}
	}
	printf("%hd",nAns);
	for(i=0; i<nAns; i++){
		printf(" %hd",ans[i]);
	}
	printf("\n");
}

int main(){
	short i, j;
	short u, v;
	short nQuery, src;
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	while((1 == fscanf(fp, "%hd", &nV)) && (nV != 0)){
		for(i=1; i <= nV; i++){
			V[i].degree = 0;
		}
		while( (1 == fscanf(fp, "%hd", &u)) && (u != 0)){
			while((1 == fscanf(fp, "%hd", &v)) && (v != 0)){
				V[u].neighbor[V[u].degree] = v;
				V[u].degree += 1;
			}
		}
		fscanf(fp, "%hd", &nQuery);
		for(i=0; i<nQuery; i++){
			fscanf(fp, "%hd", &src);
			findAns(src);
		}
	}
	return 0;
}


