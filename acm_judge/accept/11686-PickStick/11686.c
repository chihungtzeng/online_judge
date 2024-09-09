#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000001
#define LOOP -1
#define DEBUG 0

struct vertex {
	int nPre;
	int *pre;
	int preLimit;
};

struct vertex *newVertex(){
	struct vertex *v;
	v = (struct vertex *) malloc(sizeof(struct vertex));
	v->preLimit = 10;
	v->nPre = 0;
	v->pre = (int *) malloc(sizeof(int)*10);
	return v;
}

void printVertex(int id, struct vertex *v){
	int i;
	printf("vertex %d: nPre=%d limit=%d (",id, v->nPre, v->preLimit);
	for(i=0;i<v->nPre; i++){
		printf("%d ", v->pre[i]);
	}
	printf(")\n");
}

void addNeighbor(struct vertex *v, int u){
	if(v == NULL){
		printf("null vertex!\n");
		return ;
	}
	if(v->nPre == v->preLimit){
		v->preLimit = v->preLimit << 1;
		v->pre = (int *) realloc(v->pre, sizeof(int) * v->preLimit);
	}
	v->pre[v->nPre] = u;
	v->nPre += 1;
}

int findAns(int n, struct vertex *V[], int *output){
	int i, j;
	int head, tail;
	int ans;
	int *indegree;
	int src, target;
	
	indegree = (int *) malloc(sizeof(int)* (n + 1));

	memset(indegree, 0, sizeof(int)*(n+1));
	
	for(i=n; i>=1; i--){
		for(j=0; j<V[i]->nPre; j++){
			indegree[V[i]->pre[j]] += 1;
		}
	}
	tail = 0;
	for(i=1; i<=n; i++){
		if(indegree[i] == 0){
			output[tail++] = i;
		}
	}
	head = 0;
	while(head < tail){
		src = output[head++];
		for(i=0; i < V[src]->nPre; i++){
			target = V[src]->pre[i];
			indegree[target] -= 1;
			if(indegree[target] == 0){
				output[tail++] = target;
			}
		}
	}
	free(indegree);
	
	return tail;
}

int main(){
	int n, m;
	struct vertex *V[MAXN];
	int *output, nOutput;
	int i, u, v;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	output = (int *) malloc(sizeof(int)*MAXN);	
	
	while(2 == fscanf(fp, "%d %d", &n, &m)){
		if((n == 0) && (m == 0)){
			break;
		} 
		for(i=n; i>=1; i--){
			V[i] = newVertex();
		}
		for(i=m-1; i>=0; i--){
			fscanf(fp, "%d %d", &u, &v);
			addNeighbor(V[v], u);
		}

		if(DEBUG){
			for(i=1; i<=n; i++){
				printVertex(i, V[i]);
			}
		}		
		
		nOutput = findAns(n, V, output);
		
		if(nOutput < n){
			printf("IMPOSSIBLE\n");
		}
		else{
			for(i=n-1; i>=0; i--){
				printf("%d\n", output[i]);
			}
		}
		
		for(i=n; i>=1; i--){
			free(V[i]->pre);
			free(V[i]);
		}
	}

	free(output);	
	return 0;
}