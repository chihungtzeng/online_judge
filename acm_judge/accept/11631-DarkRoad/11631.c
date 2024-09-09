#include <stdio.h>
#include <stdlib.h>
#define MAX 200000
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
	if(e1->weight < e2->weight) return -1;
	else if (e1->weight > e2->weight) return 1;
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

int findMST(const int n, const int m, struct edge *eSet){
	
	int **group;
	int *nGroupMember;
	int *vertexGroup;
	
	/*	
	int group[n][n], nGroupMember[n], vertexGroup[n];
	*/
	int MSTweight = 0;
	int nGroup;
	int i, j, minEdgeIndex, u, v, weight;
	char found;
	
	
	group = (int **) malloc(sizeof(int *)*n);
	for(i = 0; i<n; i++){
		group[i] = (int *) malloc(sizeof(int)*n);
	}
	nGroupMember = (int *) malloc(sizeof(int)*n);
	vertexGroup = 	(int *) malloc(sizeof(int)*n);
	
	qsort(eSet, m, sizeof(struct edge),compareEdge);
	
	/*use disjoint set to find MST, */	
	for(i=0; i < n; i++){
		group[i][0] = i;
		nGroupMember[i] = 1;
		vertexGroup[i] = i;
	}
	
	nGroup = n;
	minEdgeIndex = 0;
	while(nGroup > 1){
		int targetGroup, sourceGroup;
		int targetGroupSize, sourceGroupSize;
		int src;
		found = 0;
		while((!found) && (minEdgeIndex < m)){
			u = eSet[minEdgeIndex].u;
			v = eSet[minEdgeIndex].v;
			if(vertexGroup[u] != vertexGroup[v]){
				found = 1;
				weight = eSet[minEdgeIndex].weight;
			}
			minEdgeIndex++;
		}
		if(DEBUG){
			printf("find a tree edge (%d %d) = %d\n",u,v,weight);
		}
		MSTweight += weight;
		/*union two groups*/
		targetGroup = vertexGroup[u];
		targetGroupSize = nGroupMember[targetGroup];
		
		sourceGroup = vertexGroup[v];		
		sourceGroupSize = nGroupMember[sourceGroup];
		for(i=0; i < sourceGroupSize; i++){
			src = group[sourceGroup][i];
			group[targetGroup][targetGroupSize++] = src;
			vertexGroup[src] = targetGroup;
		}
		nGroupMember[targetGroup] = targetGroupSize;
		nGroupMember[sourceGroup] = 0;
		nGroup--;
	}
	
	
	/*Done!*/
	
	for(i = 0; i<n; i++){
		if(group[i] != NULL){
			free(group[i]);
		}
	}
	free(group);
	free(vertexGroup);
	free(nGroupMember);
	
	return MSTweight;
}

int main(){
	int n, m;
	int totalWeight;
	int i, u, v, weight, MSTweight;
	struct edge *eSet;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	

	eSet = (struct edge *) malloc(sizeof(struct edge)*MAX);

	while(2 == fscanf(fp, "%d %d", &n, &m)){
		if((0 == n) && (0 == m)){
			break;
		}
		totalWeight = 0;
		for(i = m - 1; i >= 0; i--){
			fscanf(fp, "%d %d %d", &u, &v, &weight);
			totalWeight += weight;
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
		MSTweight = findMST(n, m, eSet);
		printf("%d\n",totalWeight - MSTweight);
	}


	
	free(eSet);
	return 0;
}
