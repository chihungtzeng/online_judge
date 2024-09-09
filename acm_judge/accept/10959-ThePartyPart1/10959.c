#include <stdio.h>
#define MAX 1001
#define INF 0x7fff

struct Node{
	short degree;
	short neighbor[MAX];
	short dist;
};

void BFS(short nNode, struct Node node[]){
	short queue[nNode];
	short head=0, tail=1, src, target;
	short i;
	node[0].dist = 0;
	queue[head]  = 0;
	while(head < tail){
		src = queue[head++];
		for(i=0; i<node[src].degree; i++){
			target = node[src].neighbor[i];
			if(node[target].dist > node[src].dist + 1){
				node[target].dist = node[src].dist + 1;
				queue[tail++] = target;
			}
		}
	} 
	for(i=1; i<nNode; i++){
		printf("%hd\n", node[i].dist);
	}
}

int main(){
	struct Node node[MAX];
	short nNode;
	int nDance, i;
	short nTest, u, v;
	char first = 1;
	FILE *fp = stdin;
	
	fscanf(fp, "%hd", &nTest);
	while(nTest--){
		fscanf(fp, "%hd %d", &nNode, &nDance);
		for(i=0; i<nNode; i++){
			node[i].degree = 0;
			node[i].dist = INF;
		}
		for(i=0; i<nDance; i++){
			fscanf(fp, "%hd %hd", &u, &v);
			node[u].neighbor[node[u].degree++] = v;
			node[v].neighbor[node[v].degree++] = u;
		}
		if(first) {
			first = 0;
		} else {
			puts("");
		}
		BFS(nNode, node);
	}
	
	return 0;
}