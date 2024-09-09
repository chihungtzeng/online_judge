/*AC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAXN 1000001
#define SUCCESS 1
#define FAILURE 0
#define DEBUG 0
#define WHITE 0
#define BLACK 1



struct edge {
	long int v[2];
	long int cost;
};

struct vertex {
	long int id;
	long int nNeighbor;
	long int *neighbor;
};



long int lmin(long int a, long int b){
	if (a > b) return b;
	else return a;
}

long int lmax(long int a, long int b){
	if (a > b) return a;
	else return b;
}



int compareEdge(const void *e1, const void *e2){
	struct edge e11, e22;
	e11 = *(struct edge *)e1;
	e22 = *(struct edge *)e2;
	return (e11.v[0] - e22.v[0])*MAXN + (e11.v[1] - e22.v[1]);
}

int deleteEdge(struct vertex *v, int u){
/*remove a neighbor u from v*/
	int i, pos;
	int found = FAILURE; 
	for(i=0; (i < v->nNeighbor) ; i++){
		if (u == v->neighbor[i]){
			pos = i;
			found = SUCCESS;
			break;
		}
	}
	
	if(SUCCESS == found){
		v->nNeighbor -= 1; 
		for(i = pos; i< v->nNeighbor; i++){
			v->neighbor[i] = v->neighbor[i+1];
		}
	}
	return found;
}

int deleteEdgeFromTree(struct vertex *treeSet, long int u, long int v){
	int state[2];
	state[0] = deleteEdge(&treeSet[u], v);
	state[1] = deleteEdge(&treeSet[v], u);
	if((state[0] == SUCCESS) && (state[1] == SUCCESS)){
		return SUCCESS;
	}
	else {
		printf("delete edge (%ld %ld) from tree failed\n",u,v);
		return FAILURE;
	}
}

void dumpTreeEdge(struct edge *treeEdge, long int n){
	int i;
	for(i = 0; i < n; i++){
		printf("(%ld %ld) has cost %ld \n",treeEdge[i].v[0], treeEdge[i].v[1], treeEdge[i].cost);
	}
}

void dumpTree(struct vertex *treeSet, long int N){
	long int i,j;
	printf("tree structure:\n");
	for(i = 1;i<= N; i++){
		printf("%ld: ",i);
		for(j=0;j<treeSet[i].nNeighbor;j++){
			printf("%ld ",treeSet[i].neighbor[j]);
		}
		printf("\n");
	}
}

int addEdge(struct vertex *v, long int u){
	int state = SUCCESS;
	int i;
	for(i=0; (i < v->nNeighbor) && (SUCCESS == state); i++){
		if( v->neighbor[i] == u){
			printf("already has neighbor %ld\n", u);
			state = FAILURE;
		}
	}
	if(SUCCESS == state){
		v->neighbor[v->nNeighbor] = u;
		v->nNeighbor += 1;
	}
	return state;
}

int addEdgeToTree(struct vertex *treeSet, long int u, long int v){
	if( u == v){
		printf("Error: add null edge (%ld %ld) to tree\n", u, v);
		return FAILURE;
	}
	int state[2];
	state[0] = addEdge(&treeSet[u], v);
	state[1] = addEdge(&treeSet[v], u);
	if((SUCCESS == state[0]) && (SUCCESS == state[1])){
		return SUCCESS;
	}
	else{
		printf("add edge (%ld %ld) to tree failed\n",u,v);
		return FAILURE;
	}
}



void freeTreeSet(struct vertex *treeSet, long int N){
	long int i;
	for(i = 1; i <= N; i++){
		free(treeSet[i].neighbor);
	}
	free(treeSet);
}

struct edge *newEdge(long int u, long int v, long int cost){
	struct edge *e;
	e = (struct edge *)malloc(sizeof(struct edge));
	e->v[0] = lmin(u, v);
	e->v[1] = lmax(u, v);
	e->cost = cost;
	return e;
}


int main(){
	void *te;
	struct vertex *treeSet;
	struct edge *newEdgeSet, *treeEdge;
	struct edge *e;
	long int u, v, cost;
	long int N, K, M;
	long int oldTreeCost, newTreeCost;
	long int *degree;
	long int i,j;
	short *markV;
	long int maxEdgeCost, maxEdgePos[2];
	int first=1;
	
	
	while(1 == scanf("%ld",&N)){
		te = NULL;
		if(!first){
			printf("\n");
		}
		else{
			first = 0;
		}
		treeEdge = (struct edge *) malloc(sizeof(struct edge)*(N));
		degree = (long int *) malloc(sizeof(long int)*(N+1));
		memset(degree, 0, sizeof(long int)*N);
		oldTreeCost = 0;
		for(i = N - 2; i >= 0; i--){
			scanf("%ld %ld %ld",&u, &v, &cost);
			treeEdge[i].v[0] = lmin(u, v);
			treeEdge[i].v[1] = lmax(u, v);
			treeEdge[i].cost = cost;
			e = newEdge(u, v, cost);
			tsearch(e, &te, compareEdge);
			degree[u]++;
			degree[v]++;
			oldTreeCost += cost;
		}
		newTreeCost = oldTreeCost;
		
		treeSet = (struct vertex *) malloc(sizeof(struct vertex)*(N+1));
		for(i=1;i <= N;i++){
			treeSet[i].neighbor = (long int *) malloc(sizeof(long int)*(degree[i] + 10));
			treeSet[i].nNeighbor = 0;
		}
		
		
		
		for(i = N -2; i>=0; i--){
			u = treeEdge[i].v[0];
			v = treeEdge[i].v[1];
			if( SUCCESS != addEdgeToTree(treeSet, u, v) ){
				printf("set neighbor failed\n");
				exit(0);
			}	
		}
		free(treeEdge);
		free(degree);
		/*From now on, we only concern newEdgeSet, te, and treeSet*/
		
		scanf("%ld",&K);
		newEdgeSet = (struct edge *) malloc(sizeof(struct edge)*K);
		for(i = 0; i < K; i++){
			scanf("%ld %ld %ld",&u, &v, &cost);
			newEdgeSet[i].v[0] = lmin(u, v);
			newEdgeSet[i].v[1] = lmax(u, v);
			newEdgeSet[i].cost = cost;
		}	
		scanf("%ld",&M);
		for(i = 0; i < M; i++){
			scanf("%ld %ld %ld",&u, &v, &cost);
		}
		/*====================================*/
		if(DEBUG){
			printf("Catch input:\n");
			printf("tree set:\n");
			for(i=0;i<N-1;i++){
				printf("%ld %ld cost = %ld\n",treeEdge[i].v[0], treeEdge[i].v[1], treeEdge[i].cost);
			}
			printf("new edges:\n");
			for(i=0;i<K;i++){
				printf("%ld %ld cost = %ld\n",newEdgeSet[i].v[0], newEdgeSet[i].v[1], newEdgeSet[i].cost);
			}
			printf("degrees in tree\n");
			for(i=1;i<N+1;i++){
				printf("%ld ",degree[i]);
			}			
			printf("\n");
			printf("tree structure:\n");
			for(i = 1;i<= N; i++){
				printf("%ld: ",i);
				for(j=0;j<treeSet[i].nNeighbor;j++){
					printf("%ld ",treeSet[i].neighbor[j]);
				}
				printf("\n");
			}
			printf("--- end of configureation ---\n");
		}	
		/*====================================*/
		
		
		/*update tree*/
		markV = (short *) malloc(sizeof(short)*(N+1));

		while(K >= 1){
			if(DEBUG){
				printf("%ld round start\n", K);
				dumpTree(treeSet,N);
			}		
			long int queue[N], head, tail;
			long int src, target, nWhite;
			long int _u, _v, _cost;
			
			head = 0;
			tail = 0;
			

			
			for(i = 1; i <= N; i++){
				markV[i] = WHITE;
			}
			u = newEdgeSet[K-1].v[0];
			v = newEdgeSet[K-1].v[1];
			cost = newEdgeSet[K-1].cost; 
			e = newEdge(u, v, cost);
			tsearch(e, &te, compareEdge);
			newTreeCost += cost; 
			if( SUCCESS != addEdgeToTree(treeSet, u, v)){
				printf("add edge (%ld %ld) to tree failed\n",u,v);
			}
			
			
			
			
			for(i=1; i <= N; i++){
				if(treeSet[i].nNeighbor == 1){
					if(DEBUG) {
						printf("insert %ld into queue\n", i);
					}
					queue[tail] = i;
					tail++;
					markV[i] = BLACK;
				}
			}
			while(head < tail){
				src = queue[head];
				if(DEBUG){
					printf("remove vertex of degree 1 form T: %ld\n",src);
				}
				for(i = 0; i < treeSet[src].nNeighbor; i++){
					target = treeSet[src].neighbor[i];
					nWhite = 0;
					for(j = 0; j <treeSet[target].nNeighbor; j++){
						if (WHITE == markV[treeSet[target].neighbor[j]]){
							nWhite++;
						}
					}
					if(1 == nWhite ){
						if(DEBUG){
							printf("insert vertex of degree 1 into T: %ld\n",target);
						}
						markV[target] = BLACK;
						queue[tail] = target;
						tail++;
					}
				}
				head++;
			}
			/*Now, if a vertex is colored by white, then it is in a cycle*/
			maxEdgeCost = 0;

			for(i = 1; i <= N; i++){
				if (WHITE == markV[i]){
					_u = i;
					for(j = 0; j < treeSet[i].nNeighbor; j++){
						if(WHITE == markV[treeSet[i].neighbor[j]]){
							struct edge *match;
							_v = treeSet[i].neighbor[j];
							e = newEdge(_u, _v, 0);
							match = *(struct edge **) tsearch(e, &te, compareEdge);
							if( NULL == match ){
								printf("error on t_search funnction\n");
								exit(0);
							}
							if (match == e){
								printf("Anonaly: t_search funnction should containe e, but it doesn't\n");
								exit(0);
							}
							free(e);
							_cost = match->cost;

							if(_cost > maxEdgeCost){

								maxEdgeCost = _cost;
								maxEdgePos[0] = _u;
								maxEdgePos[1] = _v;
							}
						}
					} 
				} 
			} 			
			if(maxEdgeCost > cost){
				
				newTreeCost = newTreeCost - maxEdgeCost;
				_u = maxEdgePos[0];
				_v = maxEdgePos[1];
				
				if(DEBUG){
					printf("replace edge with (%ld, %ld) of old/new cost %ld/%ld\n",_u,_v,maxEdgeCost,cost);
				}
				
				deleteEdgeFromTree(treeSet, _u, _v);
				
				if(DEBUG){
					printf("currnet Tree cost: %ld\n",newTreeCost);
				}
			}
			else{
				
				newTreeCost -= cost;
				deleteEdgeFromTree(treeSet, u, v);
				if(DEBUG){
					printf("Tree cost does not update: %ld\n",newTreeCost);
				}
				
			}
			
			if(DEBUG){
				printf("%ld round end\n",K);
				dumpTree(treeSet,N);
			}
			K--;
		}	/*end of updating tree*/
		free(markV);
		
		
		

	
	/*report answer*/
		printf("%ld\n",oldTreeCost);	
		printf("%ld\n",newTreeCost);
		freeTreeSet(treeSet,N);
		free(newEdgeSet);
		tdestroy(te, free);

	} /*end a test case */
	return 0;
}
