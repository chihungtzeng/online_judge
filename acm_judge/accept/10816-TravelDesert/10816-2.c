#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#define DEBUG 0
#define MAX 1000
#define MAXE 10001
#define MAXN 128


struct vertex{
	short id;
	short from;
	short nNeighbor;
	short neighbor[MAXN];
	double temperature;
	double dist;
};

struct GeoData{
	short from, to;
	double temperature, dist;
};

struct vertex *V;
struct GeoData *gd[MAXE];
double **temperature;
double **dist;
int N, E, S, T;


struct GeoData *newGeoData(short from, short to, double t, double d){
	struct GeoData *g;
	g = (struct GeoData *) malloc(sizeof(struct GeoData));
	g->from = from;
	g->to = to;
	g->temperature = t;
	g->dist = d;
	return g;
}

int compareGeoData(const void *a, const void *b){
	struct GeoData *x, *y;
	x = (struct GeoData *)a;
	y = (struct GeoData *)b;
	if(x->from != y->from) return x->from - y->from;
	else return x->to - y->to;
}

double max(double a, double b){
	if(a < b) return b;
	else return a;
}

double min(double a, double b){
	if(a < b) return a;
	else return b;
}

short minShort(short a, short b){
	if(a < b) return a;
	else return b;
}

short maxShort(short a, short b){
	if(a < b) return b;
	else return a;
}

void printVertex(struct vertex *v){
	short i;
	printf("%hd neighbors:(",v->nNeighbor);
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
		V[i].dist = 1000000;
		V[i].from  = 0;
	}
	
/*first pass, find the temperature*/	
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
	/*second pass, find the distance*/
	
	for(i=0; i<E; i++){
		src = gd[i]->from;
		target = gd[i]->to;
		if((gd[i]->temperature <= V[T].temperature) && (gd[i]->dist <= dist[src][target])){
			dist[src][target] = gd[i]->dist;
			dist[target][src] = gd[i]->dist;
		}
	}	
	V[S].dist = 0;
	flag[S] = 1;
	head = 0;
	tail = 1;	
	while(head < tail){
		src = queue[head++];
		flag[src] = 0;
		for(i=0; i<V[src].nNeighbor; i++){
			target = V[src].neighbor[i];
			if(V[target].dist > V[src].dist + dist[src][target]){
				V[target].dist = V[src].dist + dist[src][target];
				V[target].from = src;
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
	/*output answer*/
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
	int i, j, u, v;
	double dis, tmp;
	FILE *fp;
	

	fp = (DEBUG)? fopen("in2.txt","r") : stdin;	
	
	V = (struct vertex *) malloc(sizeof(struct vertex)*MAXN);
	temperature = (double **) malloc(sizeof(double *)*MAXN);
	dist = (double **) malloc(sizeof(double *)*MAXN);
	
	for(i=0; i < MAXN; i++){
		temperature[i] = (double *) malloc(sizeof(double)*MAXN);		
		dist[i] = (double *) malloc(sizeof(double)*MAXN);
		assert((temperature[i] != NULL) && (dist[i] != NULL));
	}
		
	while(2 == fscanf(fp, "%d %d",&N, &E)){
		fscanf(fp, "%d %d",&S, &T);
		memset(V, 0, sizeof(struct vertex)*(N+1));

		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				temperature[i][j] = MAX;
				dist[i][j] = MAX;
			}
		}

		for(i=0; i<E; i++){
			fscanf(fp, "%d %d %lf %lf", &u, &v, &tmp, &dis);
			gd[i] = newGeoData(minShort(u,v), maxShort(u,v), tmp, dis);
			if(temperature[u][v] > tmp){
				temperature[u][v] = tmp;
				temperature[v][u] = tmp;
			}
			
			if(addNeighbor(&V[u], v) == EXIT_SUCCESS){
				addNeighbor(&V[v], u);
			}
		}
		if(DEBUG){
			for(i=1; i<=N; i++){
				printf("vertex %hd:", i);
				printVertex(&V[i]);
			}
			printf("start solving the problem\n");
		}
		solve();
		
		for(i=0; i<E;i++){
			free(gd[i]);
		}
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
