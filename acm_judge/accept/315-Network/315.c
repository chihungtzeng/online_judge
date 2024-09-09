#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
#define LEN 1024
#define DEBUG 0

struct Vertex{
	short degree;
	short neighbor[MAX];
};

struct Vertex V[MAX];
short nV;

void dfs(short src, char visit[]){
	short v, i;
	if(DEBUG){
		printf("visit %hd\n", src);
	}
	for(i=0; i<V[src].degree; i++){
		v = V[src].neighbor[i];
		if(visit[v] == 0){
			visit[v] = 1;
			dfs(v, visit);
		}
	}
}

short findAns(){
	char visit[MAX];
	
	short root, i, v;
	short ans = 0;
	char articulate;
	
	for(root = 1; root <= nV; root++){		
		if(V[root].degree <= 1) continue;
		
		if(DEBUG) printf("****DFS with root %hd\n", root);
		memset(visit, 0, sizeof(char)*MAX);
		
		visit[root] = 1;
		visit[V[root].neighbor[0]] = 1;
		dfs(V[root].neighbor[0], visit);
		articulate = 0;
		for(i = 1; (i < V[root].degree) && (!articulate); i++){
			v = V[root].neighbor[i];
			if(visit[v] == 0){
				articulate = 1;
				if(DEBUG) printf("%hd is articulate\n",root);
			}
		}
		if(articulate) ans++;
	}
	return ans;
}

int main(){
	
	short u, v, i, j;
	char line[LEN], *tok;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	while(NULL != fgets(line, LEN, fp)){
		nV = atoi(line);
		if(nV == 0) return 0;
		for(i=1; i<=nV; i++){
			V[i].degree = 0;
		}
		
		while(NULL != fgets(line, LEN, fp)){
			tok = strtok(line, " \n");
			if(*tok == '0'){
				break;
			}
			else{
				u = atoi(tok);
			}
			tok = strtok(NULL, " \n");
			while (tok != NULL){
				v = atoi(tok);
				V[u].neighbor[V[u].degree++] = v;
				V[v].neighbor[V[v].degree++] = u;
				tok = strtok(NULL, " \n");
			}
		}
		
		printf("%hd\n",findAns());
	}

	return 0;
}