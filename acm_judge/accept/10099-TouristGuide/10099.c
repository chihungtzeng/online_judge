#include <stdio.h>
#include <string.h>
#define MAX 101
#define QUEUESIZE 30000
#define DEBUG 0

struct vertex{
	int nCarry;
	int edgeCapacity[MAX];
	short nNeighbor;
	int neighbor[MAX];
};


int N, R, start, end, nPeople;
struct vertex V[MAX];

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int min(int a, int b){
	if (a > b) return b;
	else return a;
}

void addNeighbor(int u, int v, int capacity){
	V[u].neighbor[V[u].nNeighbor++] = v;
	V[v].neighbor[V[v].nNeighbor++] = u;
	V[u].edgeCapacity[v] = capacity;
	V[v].edgeCapacity[u] = capacity; 
}

int findAns(){
	short queue[QUEUESIZE], head, tail, newTail;
	int src, target, i;
	int newCarry;
	
	V[start].nCarry = nPeople;
	queue[0] = start;
	head = 0;
	tail = 1;
	
	while(head != tail){
		src = queue[head];
		head = (head + 1);
		for(i=0; i<V[src].nNeighbor; i++){
			target = V[src].neighbor[i];
			newCarry = min(V[src].nCarry, V[src].edgeCapacity[target]);
			if (newCarry > V[target].nCarry){
				V[target].nCarry = newCarry;
				queue[tail] = target;
				tail = (tail + 1) ;
			}
		}
	}	
	
	return V[end].nCarry;
	
}

int main(){
	char first = 1;
	int kCase = 1, i, u , v, capacity, nTrip;

	while(1){
		scanf("%d %d",&N, &R);
		if((0 == N) && (0 == R)){
			break;
		}
		memset(V, 0, sizeof(struct vertex)*MAX);
		for(i=0; i<R; i++){
			scanf("%d %d %d", &u, &v, &capacity);
			addNeighbor(u, v, capacity);
		}
		scanf("%d %d %d", &start, &end, &nPeople);
		if( start == end){
			nTrip = 0;
		}
		else {
			capacity = findAns() - 1;
			nTrip = nPeople / capacity;
			if (nPeople % capacity != 0){
				nTrip++;
			}
		}
		if(DEBUG){
			printf("each trip takes %d people\n",capacity);
		}
		printf("Scenario #%d\n",kCase++);
		printf("Minimum Number of Trips = %d\n\n",nTrip);		
	}
	
	return 0;
}