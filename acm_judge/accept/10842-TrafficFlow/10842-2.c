#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
#define DEBUG 0

struct edge {
	int u, v;
	int weight;
};

struct edge *newEdge(int u, int v, int weight){
	struct edge *e;
	e = (struct edge *) malloc(sizeof(struct edge));
	e->u = min(u,v);
	e->v = max(u,v);
	e->weight = weight;
	return e;
}

int compareEdge(const void *a, const void *b){
	struct edge *e1, *e2;
	e1 = (struct edge *)a;
	e2 = (struct edge *)b;
	if(e1->weight < e2->weight) return 1;
	else if (e1->weight > e2->weight) return -1;
	else if (e1->u < e2->u) return -1;
	else if (e2->u > e2->u) return 1;
	else return e1->v - e2->v;
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}
int max(int a, int b){
	if(a < b) return b;
	else return a;
}

int findSet(int parent[], int x){
	if (x != parent[x]){
		parent[x] = findSet(parent, parent[x]);
	}
	return parent[x];
}

void link(int rank[], int parent[], int x, int y){
	if(rank[x] > rank[y]){
		parent[y] = x;
	}
	else {
		parent[x] = y;
		if (rank[x] == rank[y]){
			rank[y] += 1;
		}
	}
}

void dsunion(int rank[], int parent[], int x, int y){
	link(rank, parent, findSet(parent, x), findSet(parent, y));
}

int findMST(const int n, const int m, struct edge *eSet){
	int rank[n], parent[n];
	int i, j, index, u, v, x, y;
	int ans=0;
	int nGroup;	
	
	/*MAKE SET*/
	for(i=0; i<n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
	/**/
	qsort(eSet, m, sizeof(struct edge),compareEdge);
	nGroup = n;
	index = 0;
	while(nGroup > 1){
		u = eSet[index].u;
		v = eSet[index].v;
		
		if(findSet(parent, u) == findSet(parent, v)){
			index++;
			continue;
		} 
		else{
			dsunion(rank, parent, u, v);
			nGroup--;
			ans = eSet[index].weight;
			index++;
		}
	}
	
	return ans;
}

int main(){
	int n, m;
	int totalWeight;
	int i, u, v, weight, MSTweight, ans;
	struct edge *eSet;
	FILE *fp;
	short nTest, k=1;
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	

	eSet = (struct edge *) malloc(sizeof(struct edge)*MAX);
	
	fscanf(fp, "%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%d %d", &n ,&m);
		
		for(i = m - 1; i >= 0; i--){
			fscanf(fp, "%d %d %d", &u, &v, &weight);
			eSet[i].u = min(u,v);
			eSet[i].v = max(u,v);
			eSet[i].weight = weight;
		}
		
		if(DEBUG){
			for(i=0; i<m;i++){
				printf("(%d %d) = %d\n",eSet[i].u, eSet[i].v, eSet[i].weight);
			}
		}
		/**/
		ans = findMST(n, m, eSet);
		printf("Case #%d: %d\n", k++, ans);
	}


	
	free(eSet);
	return 0;
}
