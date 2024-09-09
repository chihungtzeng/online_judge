#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 200
#define WHITE 1
#define BLACK 2
#define WB 3
#define UNCOLORED 0
#define SUCCESS 1
#define FAILURE 0
#define DEBUG 0

struct vertex{
	unsigned short color;
	unsigned short nNeighbor;
	unsigned short neighbor[200];
};

unsigned short mmin(unsigned short a, unsigned short b){
	if (a > b) return b;
	else return a;
}

unsigned short mmax(unsigned short a, unsigned short b){
	if (a > b) return a;
	else return b;
}

int main(){
	struct vertex *V;
	short int queue[MAXN];
	int n,m;
	int i;
	unsigned short x, y, u, v;
	int head, tail;
	int state, target, source;
	FILE *fp;
	
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}
	
	V = (struct vertex *) malloc(sizeof(struct vertex)*MAXN);
	while(2 == fscanf(fp, "%d %d",&n, &m)){
		memset(V, 0, sizeof(struct vertex)*MAXN);
		
		for(i=0; i<m; i++){
			fscanf(fp, "%hd %hd", &x, &y);
			u = mmin(x, y);
			v = mmax(x, y);
			V[u].neighbor[V[u].nNeighbor] = v;
			V[u].nNeighbor += 1;
			V[v].neighbor[V[v].nNeighbor] = u;
			V[v].nNeighbor += 1;						
		}
		
		head = 0;
		tail = 1;
		queue[0] = 0;
		V[0].color = WHITE;
		state = SUCCESS;
		while((head < tail) && (tail < MAXN) && (state == SUCCESS)){
			source = queue[head];
			if(DEBUG){
				printf("check vertex %d\n",source);
			}
			for(i=0; i < V[source].nNeighbor; i++){
				target = V[source].neighbor[i];
				if(V[target].color == 0){
					V[target].color = WB - V[source].color;
					queue[tail] = target;
					tail++;
				}
				else if (V[target].color == V[source].color){
					if (DEBUG){
						printf("vertex %d is uncolored\n", target);
					}
					state = FAILURE;
				}
			}
			head++;
		}
		if(SUCCESS == state){
			puts("BICOLORABLE.");
		}
		else{
			puts("NOT BICOLORABLE.");
		}
	}
	free(V);
	
	if (DEBUG) {
		fclose(fp);
	}
	return 0;
}

