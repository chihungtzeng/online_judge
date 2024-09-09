#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000000
#define MAX 102

struct Vertex{
	int nNeighbor;
	int neighbor[MAX];
	int dist;
	int from;
};

void removeNeighbor(struct Vertex *u, int v){
	int i;
	int tmp;
	for(i=0; i<u->nNeighbor; i++){
		if((u->neighbor[i] == v)){
			u->nNeighbor--;
			tmp = u->neighbor[u->nNeighbor];
			u->neighbor[u->nNeighbor] = u->neighbor[i];
			u->neighbor[i] = tmp;
			return ;
		}
	}
}

int n, m;
int dist[MAX][MAX];
struct Vertex V[MAX];

int findShortestPath(){
	char queue[10000], flag[MAX];
	int head, tail, i;
	int src, target;
	
	for(i=1; i<=n; i++){
		V[i].dist = INF;
		V[i].from = 0;
		flag[i] = 0;
	}
	V[1].dist = 0;
	flag[1] = 1;
	head = 0;
	tail = 1;
	queue[0] = 1;
	while(head < tail){
		src = queue[head++];
		flag[src] = 0;
		for(i=0; i<V[src].nNeighbor; i++){
			target = V[src].neighbor[i];
			if(V[src].dist + dist[src][target] < V[target].dist){
				V[target].dist = V[src].dist + dist[src][target];
				V[target].from = src;
				if(flag[target] == 0){
					queue[tail++] = target;
					flag[target] = 1;
				}
			}
		}
	}
	return V[n].dist;
}

void solve(){
	int ans[2];
	int i, u, v;

	/*first pass: friend*/
	ans[0] = findShortestPath();
	/*remove all the edges that the friend visit*/
	u = n;
	while(V[u].from != 0){
		v = V[u].from;
		removeNeighbor(&V[v], u);
		dist[v][u] = INF;
		dist[u][v] = -dist[u][v];
		/*printf("(%hd %hd)",u,v);*/
		u = v;
	}
	ans[1] = findShortestPath();
	if(ans[0] + ans[1] >= INF){
		printf("Back to jail\n");
	}
	else {
		printf("%d\n", ans[0] + ans[1]);
	}
}



int main(){
	int i, u, v, tmp;
	while(1 == scanf("%d", &n)){
		if(n == 0) break;
		scanf("%d",&m);
		memset(dist, 0x7f, sizeof(int)*MAX*MAX);
		for(i=1; i<=n; i++){
			V[i].nNeighbor = 0;
		}
		for(i=0; i<m;i++){
			scanf("%d %d %d", &u, &v, &tmp);
			V[u].neighbor[V[u].nNeighbor++] = v;
			V[v].neighbor[V[v].nNeighbor++] = u;
			dist[u][v] = tmp;
			dist[v][u] = tmp;
		}
		solve();
	}
	return 0;
}