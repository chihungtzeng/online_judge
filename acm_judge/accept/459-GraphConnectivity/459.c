#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define DEBUG 0

struct vertex {
	short nNeighbor;
	short neighbor[MAX];
};

struct vertex *V;
short nV;

void addNeighbor(char u, char v){
	short src, target, i;
	src = u - 'A';
	target = v - 'A';
	
	
	V[src].neighbor[V[src].nNeighbor++] = target;
	V[target].neighbor[V[target].nNeighbor++] = src;
}


void printV(){
	short i,j;
	for(i=0; i<nV; i++){
		printf("V[%d]: %d neighbors:", i, V[i].nNeighbor);
		for(j=0; j<V[i].nNeighbor;j++){
			printf("%d ", V[i].neighbor[j]);
		}
		printf("\n");
	}
}

short discoverComponent(){
	short nC = 0;
	short queue[MAX], head, tail, i, j, done, idx;
	short color[MAX];
	short src, target;
	
	memset(color, 0, sizeof(short)* MAX);
	done = 0;
	idx = 0;
	while(!done){
		done = 1;
		nC++;
		queue[0] = idx;
		color[idx] = 1;
		head = 0; 
		tail = 1;
		while(head < tail){
			src = queue[head++];
			for(i=0 ; i < V[src].nNeighbor; i++){
				target = V[src].neighbor[i];
				if(color[target] == 0){
					color[target] = 1;
					queue[tail++] = target;
				}
			}
		}
		for(i=0; (i < nV ) && (done); i++){
			if(color[i] == 0){
				idx = i;
				done = 0;
			}
		}
	}
	return nC;
}


int main(){
	int nTest, endCase;
	short first = 1, i, nComponent;
	char line[MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	V = (struct vertex *) malloc(sizeof(struct vertex)*MAX);
	
	fgets(line, MAX, fp);
	nTest = atoi(line);
	fgets(line, MAX, fp);
	
	while(nTest >= 1){
		char u, v, *state;
		nTest--;
		if(first){
			first = 0;
		}
		else {
			printf("\n");
		}
		memset(V, 0, sizeof(struct vertex)*MAX);
		fgets(line, MAX, fp);
		if(DEBUG){
			
		}
		nV = line[0] - 'A' + 1;
		endCase = 0;
		while(!endCase){
			state = fgets(line, MAX, fp);
			if( (NULL == state) || (line[0] == ' ') || (line[0] == '\n')){
				endCase = 1;
			}
			else{
				u = line[0];
				v = line[1];
				addNeighbor(u, v);
			}
		}
		if(DEBUG){
			printf("nV = %d\n", nV);
			printV();
		}


		nComponent = discoverComponent();
		printf("%hd\n",nComponent);
	}	
	
	free(V);
	return 0;
}