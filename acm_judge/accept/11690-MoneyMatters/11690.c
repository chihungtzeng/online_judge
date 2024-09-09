#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10000
#define MAXM 50000
#define POSSIBLE 1
#define IMPOSSIBLE 0
#define DEBUG 0

struct vertex{
	int degree;
	int maxDegree;
	int *neighbor;
	int debt;
};

void printVertex(int id, struct vertex *v){
	int i;
	printf("vertex %d:", id);
	printf("degree %d (",v->degree);
	for(i=0; i<v->degree; i++){
		printf("%d ", v->neighbor[i]);
	}
	printf("), debt=%d\n", v->debt);
}

struct vertex *newVertex(int debt){	
	struct vertex *v;
	v = (struct vertex *) malloc(sizeof(struct vertex));
	v->degree = 0;
	v->neighbor = (int *) malloc(sizeof(int)*5);
	v->maxDegree = 5;
	v->debt = debt;
	return v;
}

int addNeighbor(struct vertex *v, int u){
	if(v == NULL){
		printf("null vertex!\n");
		return -1;
	}
	if(v->degree == v->maxDegree){
		v->maxDegree = v->maxDegree << 1;
		v->neighbor = realloc(v->neighbor, sizeof(int)*v->maxDegree);
	}
	v->neighbor[v->degree] = u;
	v->degree++;
	return 1;
}

int findAns(int n, struct vertex *V[]){
	char *mask;
	int *queue, head, tail;
	int round, i, nVisit, found, total;
	int src, target;
	
	mask = (char *) malloc(sizeof(char)*n);
	queue = (int *) malloc(sizeof(int)*n);
	memset(mask, 0, sizeof(char)*n);
	nVisit = 0;

	while(nVisit < n){
		found = -1;
		for(i=0; (found < 0) && (i<n); i++){
			if(mask[i] == 0){
				found = i;
			}
		}
		queue[0] = found;
		total = V[found]->debt;
		mask[found] = 1;
		nVisit++;
		head = 0;
		tail = 1;
		while(head < tail){
			src = queue[head++];
			for(i=0; i < V[src]->degree; i++){
				target = V[src]->neighbor[i];
				if(mask[target] == 0){
					total += V[target]->debt;
					mask[target] = 1;
					queue[tail++] = target;
					nVisit++;
				}
			}
		}
		if(total != 0){
			free(mask);
			free(queue);
			return IMPOSSIBLE;
		}
	}
	
	free(mask);
	free(queue);
	return POSSIBLE;
}

int main(){
	short nTest;
	int n, m, debt;
	int i, u, v;
	struct vertex *V[MAXN];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	fscanf(fp,"%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp,"%d %d", &n, &m);
		for(i=0; i<n; i++){
			fscanf(fp,"%d", &debt);
			V[i] = newVertex(debt);
		}
		for(i=0; i<m; i++){
			fscanf(fp,"%d %d",&u, &v);
			addNeighbor(V[u], v);
			addNeighbor(V[v], u);
		}
		if(DEBUG){
			for(i=0; i<n; i++){
				printVertex(i, V[i]);
			}
		}
		/*Check trivial case*/
		
		if(findAns(n, V) == POSSIBLE){
			printf("POSSIBLE\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}
		
		/*free memory*/
		for(i=0; i<n; i++){
			free(V[i]->neighbor);
			free(V[i]);
		}
	}

	return 0;
}