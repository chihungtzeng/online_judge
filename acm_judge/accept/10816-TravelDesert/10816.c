#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define DEBUG 1
#define MAX 10000000
#define MAXN 128
#define EPSILON 1e-12

struct vertex{
	short id;
	short from;
	short nNeighbor;
	short neighbor[MAXN];
	double temperature;
	double dist;
};



double **temperature;
double **dist;
struct vertex *V;
int N, E, S, T;

void resetTemperatureDist(){
	short i, j;
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			temperature[i][j] = 10000;
			dist[i][j] = -1;
		}
	}
}

double max(double a, double b){
	if(a < b) return b;
	else return a;
}

void printVertex(struct vertex *v){
	short i;
	printf("V[%hd]: %hd neighbors:(",v->id,v->nNeighbor);
	for(i=0; i<v->nNeighbor;i++){
		printf("%hd,",v->neighbor[i]);
	}
	printf(")\n");
}

void solve(){
	char *queue;
	char flag[MAXN];
	int head, tail, src, target, i, qsize=128;
	short output[MAXN], nOutput;
	
	queue = (char *) malloc(sizeof(char)*qsize);
	memset(flag, 0, sizeof(char)*MAXN);
	for(i=1; i<=N; i++){
		V[i].temperature = MAX;
		V[i].dist = MAX;
		V[i].from  = 0;
	}
	
	V[S].dist = 0;
	V[S].temperature = 0;
	queue[0] = S;
	flag[S] = 1;
	head = 0;
	tail = 1;
	while(head < tail){
		src = queue[head++];
		flag[src] = 0;
		for(i=0; i<V[src].nNeighbor; i++){
			target = V[src].neighbor[i];
			if(V[target].temperature > max(temperature[src][target], V[src].temperature)){
				V[target].temperature = max(temperature[src][target], V[src].temperature);
				V[target].from = src;
				V[target].dist = V[src].dist + dist[src][target];
				if(flag[target] == 0){
					flag[target] = 1;
					queue[tail++] = target;
					if(tail == qsize){
						qsize = qsize *2;
						queue = (char *) realloc(queue, sizeof(char)*qsize);
					}
				}
			}
			else if((V[target].temperature == max(temperature[src][target], V[src].temperature)) &&
					(V[target].dist > V[src].dist + dist[src][target])
					){
				
				V[target].from = src;
				V[target].dist = V[src].dist + dist[src][target];
				if(flag[target] == 0){
					flag[target] = 1;
					queue[tail++] = target;
					if(tail == qsize){
						qsize = qsize *2;
						queue = (char *) realloc(queue, sizeof(char)*qsize);
					}
				}
			}
		}
	}
	nOutput = 0;
	tail = T;
	while(V[tail].from != 0){
		output[nOutput++] = V[tail].from;
		tail = V[tail].from;
	}
	
	while(nOutput > 0){
		nOutput--;
		printf("%hd ", output[nOutput]);
	}
	printf("%hd\n",T);
	printf("%.1lf %.1lf\n", V[T].dist, V[T].temperature);
	free(queue);
}

int addNeighbor(struct vertex *u, short v){
	short i;
	assert(u != NULL);
	for(i=0; i<u->nNeighbor; i++){
		if(u->neighbor[i] == v) return EXIT_FAILURE;
	}
	u->neighbor[u->nNeighbor++] = v;
	return EXIT_SUCCESS;
}

int main(){
	int i, u, v;
	double dis, tmp;
	FILE *fp;

	fp = (DEBUG)? fopen("in2.txt","r") : stdin;	
	
	V = (struct vertex *) malloc(sizeof(struct vertex)*MAXN);
	assert(V != NULL);
	temperature = (double **) malloc(sizeof(double *)*MAXN);
	dist = (double **) malloc(sizeof(double *)*MAXN);
	assert(temperature != NULL);
	assert(dist != NULL);
	for(i=0; i < MAXN; i++){
		temperature[i] = (double *) malloc(sizeof(double)*MAXN);		
		dist[i] = (double *) malloc(sizeof(double)*MAXN);
		assert((temperature[i] != NULL) && (dist[i] != NULL));
		temperature[i][i] = 0;
		dist[i][i] = 0;
	}
		
	while(2 == fscanf(fp, "%d %d",&N, &E)){
		fscanf(fp, "%d %d",&S, &T);
		memset(V, 0, sizeof(struct vertex)*(N+1));
		resetTemperatureDist();
		for(i=0; i<E; i++){
			fscanf(fp, "%d %d %lf %lf", &u, &v, &tmp, &dis);
			
			if(tmp < temperature[u][v]){
				temperature[u][v] = tmp;
				temperature[v][u] = tmp;
				dist[u][v] = dis;
				dist[v][u] = dis; 
			}
			else if ((tmp == temperature[u][v]) && (dist[u][v] < dis)){
				dist[u][v] = dis;
				dist[v][u] = dis;
			}

			if(addNeighbor(&V[u], v) == EXIT_SUCCESS){
				addNeighbor(&V[v], u);
			}
		}
		if(DEBUG){
			for(i=1; i<=N; i++){
				printVertex(&V[i]);
			}
		}
		solve();
	}
	for(i=0; i<MAXN; i++){
		free(dist[i]);
		free(temperature[i]);
	}
	free(dist);
	free(temperature);
	free(V);
	return 0;
}
