#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define CITY_NAME_LEN 11
#define MAX_CITY_NUM 401
#define MAX_EDGE_NUM 79801
#define INF 1000000000
#define DEBUG 0

struct Edge {
	int cost;
	short u, v;
};

struct Edge *newEdge(short u, short v, int cost){
	struct Edge *e;
	e = (struct Edge *) malloc(sizeof(struct Edge));
	e->u = u;
	e->v = v;
	e->cost = cost;
	return e;
}

int compareEdge(const void *a, const void *b){
	struct Edge *x, *y;
	x = *(struct Edge **)a;
	y = *(struct Edge **)b;
	return x->cost - y->cost;
}

void LINK(short parent[], short rank[], short x, short y){
	if(rank[x] > rank[y]){
		parent[y] = x;
	} else{
		parent[x] = y;
		if(rank[x] == rank[y]){
			rank[y] += 1;
		}
	}
}

short FIND_SET(short parent[], short x){
	if(x != parent[x]){
		parent[x] = FIND_SET(parent, parent[x]);
	}
	return parent[x];
}

void MAKE_SET(short parent[], short rank[], short x){
	parent[x] = x;
	rank[x] = 0;
}

void UNION(short parent[], short rank[], short x, short y){
	LINK(parent, rank, FIND_SET(parent, x), FIND_SET(parent, y));
}

void solve(struct Edge *eSet[], int nNode, int nEdge, int startId){
	short parent[nNode], rank[nNode];
	int i, u, v;
	short nDiscover = 0;
	int sum = 0;
	for(i=0; i<nNode; i++){
		MAKE_SET(parent, rank, i);
	}
	
	qsort(eSet, nEdge, sizeof(struct Edge *),compareEdge);
	for(i=0; i<nEdge; i++){
		u = eSet[i]->u;
		v = eSet[i]->v;
		if(FIND_SET(parent, u) != FIND_SET(parent, v)){
			sum += eSet[i]->cost;
			UNION(parent, rank, u, v);
			nDiscover += 1;
		}
		if(nDiscover == nNode - 1){
			break;
		}
	}
	if(nDiscover == nNode - 1){
		printf("%d\n",sum);
	} else {
		printf("Impossible\n");
	}
	
}



int main(){
	int nNode, nEdge, cost;
	int i, j, len, u, v;
	FILE *fp;
	struct Edge *eSet[MAX_EDGE_NUM];
	ENTRY src, dest;
	ENTRY *cityEntry[MAX_CITY_NUM];
	ENTRY *retEntry;
		
	
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	
	
	src.key = (char *) malloc(CITY_NAME_LEN);
	dest.key = (char *) malloc(CITY_NAME_LEN);

	while(2 == fscanf(fp, "%d %d", &nNode, &nEdge)){
		if( (nNode == 0) && (nEdge == 0) ) {
			break;
		}
		
		
		hcreate(MAX_CITY_NUM << 1);
		
		for(i=0; i<nNode; i++){
			cityEntry[i] = (ENTRY *) malloc(sizeof(ENTRY));
			cityEntry[i]->key = (char *) malloc(CITY_NAME_LEN);
			cityEntry[i]->data = (void *)i;
			
			fscanf(fp, "%s", cityEntry[i]->key);
			retEntry = hsearch(*cityEntry[i], ENTER);
			
			#if 0
			assert(retEntry != NULL);
			#endif
		}
		
		for(i=0; i<nEdge; i++){
			fscanf(fp, "%s %s %d", src.key, dest.key, &cost);
			retEntry = hsearch(src, FIND);
			u = (int) retEntry->data;
			retEntry = hsearch(dest, FIND);
			v = (int) retEntry->data;
			eSet[i] = newEdge(u, v, cost);
		}
		fscanf(fp, "%s", src.key);
		solve(eSet, nNode, nEdge, (int)src.data);

		#if 0		
		printf("start porint: %s (%d)\n", src.key, (int) src.data);
		#endif
		
		/*release memory*/
		for(i=0; i<nNode; i++){
			free(cityEntry[i]->key);
			free(cityEntry[i]);
		}
		for(i=0; i<nEdge; i++){
			free(eSet[i]);
		}
		hdestroy();
	}
	free(src.key);
	free(dest.key);
	
	
	return 0;
}