#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000
#define PEACE 1
#define NOPEACE 0
#define WHITE 2
#define BLACK 1
#define UNDECIDED 0
#define DEBUG 0


struct vertex {
	int nNeighbor;
	int *neighbor;
	int capacity;
};

int bull, cow, nField;
int nAnimal;
struct vertex *V;

int min(int a,int b){
	if(a < b) return a;
	else return b;
}

int addNeighbor(int u, int v){
	if(V[u].nNeighbor == V[u].capacity){
		V[u].capacity = V[u].capacity * 2;
		V[u].neighbor = (int *) realloc(V[u].neighbor, sizeof(int)*V[u].capacity);
	}
	V[u].neighbor[V[u].nNeighbor++] = v;
	return EXIT_SUCCESS;
}

int findAns(){
	char *color;
	char done = 0, found;
	int source, target, i, j, k, nBlack,nWhite;
	int queue[MAX], head, tail;
	int m, M;
	
	color = (char *) malloc(sizeof(char)*(nAnimal + 1));
	memset(color, UNDECIDED, (nAnimal + 1)*sizeof(char));
	while((bull > 0) || (cow > 0)){
		found = 0;
		for(i=1; (!found) && (i<=nAnimal); i++){
			if(color[i] == UNDECIDED){
				source = i;
				found = 1;
			}
		}
		
		queue[0] = source;
		color[source] = WHITE;
		nBlack = 0;
		nWhite = 1;
		head = 0;
		tail = 1;
		while(head < tail){
			source = queue[head++];
			for(i=0; i<V[source].nNeighbor; i++){
				target = V[source].neighbor[i];
				if(color[target] == UNDECIDED){
					color[target] = BLACK + WHITE - color[source];
					for(k=0; k<V[target].nNeighbor; k++){
						if(color[V[target].neighbor[k]] == color[target]){
							free(color);
							return NOPEACE;
						}
					}
					queue[tail++] = target;
					if(color[target] == BLACK) nBlack++;
					else if(color[target] == WHITE) nWhite++;
				}
			}
		}
		m = min(nBlack, nWhite);
		M = nBlack + nWhite - m;
		if(bull > cow){
			if((bull < M) || (cow < m)){
				free(color);
				return NOPEACE;
			}
			else {
				bull = bull - M;
				cow = cow - m;
			}
		}
		else{
			if( (cow < M) || (bull < m)){
				free(color);
				return NOPEACE;
			}
			else {
				bull = bull - m;
				cow = cow - M;
			}
		}
	}
	free(color);
	return PEACE;
}



int main(){
	int nTest, i;
	int u,v;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	
	
	fscanf(fp,"%d", &nTest);
	while(nTest >= 1){
		nTest--;
		
		
		fscanf(fp, "%d %d %d", &bull, &cow, &nField);
		nAnimal = bull + cow;
		V = (struct vertex *) malloc(sizeof(struct vertex)*(nAnimal+1));
		for(i=0; i<=nAnimal; i++){
			V[i].capacity = 10;
			V[i].neighbor = (int *) malloc(sizeof(int) * V[i].capacity);
			V[i].nNeighbor = 0;
		}
		for(i=0; i<nField; i++){
			fscanf(fp, "%d %d", &u, &v);
			addNeighbor(u,v);
			addNeighbor(v,u);
		}
		
		if(DEBUG){
			int j;
			for(i=1; i<=cow+bull; i++){
				printf("filed %d, neighbor:(",i);
				for(j = 0; j<V[i].nNeighbor; j++){
					printf("%d ", V[i].neighbor[j]);
				}
				printf(")\n");
			}
		}
		
		if(findAns() == PEACE){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
		/*DONE*/
		for(i=0; i<=nAnimal; i++){
			free(V[i].neighbor);
		}
		free(V);

	}
	return 0;
}