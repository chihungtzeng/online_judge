#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDEGREE 2001

struct Vertex {
	short degree;
	short neighbor[MAXDEGREE];
};

void addNeighbor(struct Vertex *v, short u){
	v->neighbor[v->degree] = u;
	v->degree += 1;
}

short BFS(struct Vertex *V, int n, short start){
	short queue[MAXDEGREE];
	short head, tail;
	short src, target, i;
	char color[MAXDEGREE];
	memset(color, 0, sizeof(char)*MAXDEGREE);
	
	queue[0] = start;
	color[start] = 1;
	tail = 1;
	head = 0;
	while(head < tail){
		src = queue[head++];
		for(i=0; i<V[src].degree; i++){
			target = V[src].neighbor[i];
			if(color[target] == 0){
				queue[tail++] = target;
				color[target] = 1;
			}
		}
	}
	return tail;
} 

int main(){
	struct Vertex *V;
	short u, v, direction;
	int i, j;
	int n, m;
	char connected;
	
	V = (struct Vertex *) malloc(sizeof(struct Vertex)*MAXDEGREE);
	while(2 == scanf("%d %d",&n, &m)){
		if( (0 == n) && (0 == m)){
			break;
		}
		for(i=n; i>=1; i--){
			V[i].degree = 0;
		}
		for(i=m; i>=1; i--){
			scanf("%hd %hd %hd",&u, &v, &direction);
			if(direction == 1){
				addNeighbor(V + u, v);
			}
			else if (direction == 2){
				addNeighbor(V + u, v);
				addNeighbor(V + v, u);
			}
		}
		
		connected = 1;
		for(i=n; (i>=1) && connected; i--){
			if(BFS(V, n, i) != n){
				connected = 0;
			}
		}
		
		if(connected){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	free(V);
	return 0;
}

