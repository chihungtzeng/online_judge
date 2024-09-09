#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 510
#define INITIAL_POSITION "0000"

struct Edge {
	short u, v;
	short weight;
};



int compareEdge(const void *a, const void *b){
	struct Edge *x, *y;
	x = (struct Edge *)a;
	y = (struct Edge *)b;
	return x->weight - y->weight;
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}


int calcEdgeWeight(char *t1, char *t2){
	int result = 0;
	int tmp;
	while(*t1 != '\0'){
		tmp = abs(*t1 - *t2);
		result += min(tmp, 10 - tmp);
		t1++;
		t2++;
	}	
	return result;
}

int Find(int x, int *parent){
	if ( parent[x] == x) return x;
	else {
		parent[x] = Find(parent[x], parent);
		return parent[x];
	}
}

int Union(int x, int y, int *parent, int *rank){
	int xRoot, yRoot;
	xRoot = Find(x, parent);
	yRoot = Find(y, parent);
	if(xRoot == yRoot) return EXIT_FAILURE;
	
	if(rank[xRoot] < rank[yRoot]){
		parent[xRoot] = yRoot;
	} 
	else if (rank[xRoot] > rank[yRoot]){
		parent[yRoot] = xRoot;
	}
	else {
		parent[yRoot] = xRoot;
		rank[xRoot] += 1;
	}
	return EXIT_SUCCESS;
}

int MST(int nNode, int nEdge, struct Edge *pEdge){
	int *parent, *rank;
	int i;
	int targetEdgeNum = nNode + 1; 
	int totalWeight = 0;
	int u, v;
	int nEdgeFound = 0;
	parent = (int *) malloc(sizeof(int)*MAX);
	rank = (int *) malloc(sizeof(int)*MAX);
	
	qsort(pEdge, nEdge, sizeof(struct Edge), compareEdge);
	/*makeset*/
	for(i=0; i<nNode; i++){
		parent[i] = i;
		rank[i] = 0;
	}
	i = 0;
	while( (nEdgeFound < targetEdgeNum) && (i < nEdge)){
		u = pEdge[i].u;
		v = pEdge[i].v;
		if(Union(u, v, parent, rank) == EXIT_SUCCESS){
			totalWeight += pEdge[i].weight;
			nEdgeFound++;
			#if 0
			printf("union (%d, %d)\n", u, v);
			#endif
		}
		i++;
	}

	return totalWeight;
}

int solve(int nNode, char **token){
	int i, j;
	struct Edge *pEdge;
	int nEdge = 0;
	int ret;
	pEdge = (struct Edge *) malloc(sizeof(struct Edge)*
		((nNode * nNode + nNode) >> 1)	
		);
	for(i=0; i<nNode; i++){
		for(j=0; j<i; j++){
			pEdge[nEdge].weight = calcEdgeWeight(token[i], token[j]);
			pEdge[nEdge].u = j;
			pEdge[nEdge].v = i;
			nEdge++;
		}
	}
	ret = MST(nNode, nEdge, pEdge);
	free(pEdge);
	return ret;
}

int main(){
	int nTest;
	int i;
	int nNode;
	int initialWeight, tmp;
	FILE *fp = stdin;
	char **token;
		
	
	
	
	token = (char **) malloc(sizeof(char *)*MAX);
	for(i=0; i<MAX; i++){
		token[i] = (char *) malloc(5);
	}	
	
	fscanf(fp, "%d", &nTest);
	
	while(nTest--){
		initialWeight = 100;
		fscanf(fp, "%d", &nNode);
		for(i=0; i<nNode; i++){
			fscanf(fp, "%s", token[i]);
		}
		for(i=0; i<nNode; i++){
			tmp = calcEdgeWeight(INITIAL_POSITION, token[i]);
			if(initialWeight > tmp){
				initialWeight = tmp;
			}
		}	
		printf("%d\n", initialWeight + solve(nNode, token));
	}

	

	for(i=0; i<MAX; i++){
		free(token[i]);
	}
	free(token);
	
	return 0;
}