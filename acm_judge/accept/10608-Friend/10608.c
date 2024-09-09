#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30001

struct Vertex {
	int degree;
	short *neighbor;
	int maxDegree;
};

void addNeighbor(struct Vertex *v, short u){
	int i;
	for(i=0; i<v->degree; i++){
		if(v->neighbor[i] == u) return ;
	}
	
	if(v->degree == v->maxDegree){
		v->maxDegree = v->maxDegree * 2;
		v->neighbor = (short *) realloc(v->neighbor, sizeof(short)*v->maxDegree);
	}
	v->neighbor[v->degree++] = u;
	return ;
}

int findAns(struct Vertex V[], int n){
	int ans = 0, i, j;
	short src, target, head, tail;
	char color[n+1];
	short queue[n+1];
	memset(color, 0, n+1);
	
	for(i=1; i<=n; i++){
		if(color[i] == 1) continue;
		
		queue[0] = i;
		color[i] = 1;
		head = 0;
		tail = 1;
		while(head < tail){
			src = queue[head++];
			for(j=0; j<V[src].degree; j++){
				target = V[src].neighbor[j];
				if(color[target] == 0){
					queue[tail++] = target;
					color[target] = 1;
				}
			}
		}
		if(tail > ans){
			ans = tail;
		}
	}	
	
	return ans;
}

int main(){
	int i, j;
	int n, m, ans;
	short nTest, u, v;
	struct Vertex V[MAX];
	for(i=0; i<MAX; i++){
		V[i].maxDegree = 10;
		V[i].neighbor = (short *) malloc(sizeof(short)*10);
	}	
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&n, &m);
		for(i=n; i>=1; i--){
			V[i].degree = 0;
		}
		
		for(i=m; i>=1; i--){
			scanf("%hd %hd", &u, &v);
			addNeighbor(V + u, v);
			addNeighbor(V + v, u);
		}
		ans = findAns(V, n);
		printf("%d\n",ans);
	}
		
	for(i=0; i<MAX; i++){
		free(V[i].neighbor);
	}
	return 0;
}