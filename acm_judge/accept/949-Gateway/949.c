#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCOL 128
#define SHIFT 7 /* 2^7 = 128 */
#define DEBUG 0
#define INTMAX 0x0fffffff
#define FAIL -1
#define SUCCESS 1

short nh, nv;

struct vertex{
	short id;
	short nNeighbor;
	short neighbor[4];
	short nLimit;
	int limit[500];
	int dist;
};

struct qele {
	void *key;
	struct qele *llink;
	struct qele *rlink;
	int dist;
};

struct qele * new_qele(const void *inkey){
	struct qele *e;
	e = (struct qele *) malloc(sizeof(struct qele));
	e->key = (void *)inkey;
	e->llink = NULL;
	e->rlink = NULL;
	e->dist = 1;
	return e;
}

int q_dist(struct qele *e){
	if ( NULL == e) return 0;
	else return e->dist;
}

struct qele * q_merge(struct qele *P, struct qele *Q, int (compr)() ){
/*The following codes are from The Art of Computer Programming, Sec 5.2.3*/
	struct qele *R,*T;
	int D;

	R = NULL;	
	
	/*List merge*/
	while ((NULL != P) && (NULL != Q)){
		if ((*compr)(P->key, Q->key) >=0){
			T  = P->rlink;
			P->rlink = R;
			R = P;
			P = T;
		}
		else {
			T = Q->rlink;
			Q->rlink = R;
			R = Q;
			Q = T;
		}
	}
	if (NULL == Q){
		D = q_dist(P);
	}
	if (NULL == P){
		P = Q;
		D = q_dist(P);
	}
	/*fix Dists; check if done*/
	while(NULL != R){
		Q = R->rlink;
		if (q_dist(R->llink) < D){
			D = q_dist(R->llink) + 1;
			R->rlink = R->llink;
			R->llink = P;
		}
		else {
			D++;
			R->rlink = P;
		}
		
		R->dist = D;
		P = R;
		R = Q;
	}	
	
	return P;
} 

void q_add(const void *key, struct qele **root, int (compr)()){
	struct qele *newe;
	newe = new_qele(key);
	*root = q_merge(*root, newe, compr);
}

struct qele *q_extract(struct qele **root, int (compr)()){
	struct qele *result;
	if (NULL == *root) return NULL;
	result = *root;
	*root = q_merge((*root)->llink, (*root)->rlink, compr);
	
	return result; 
}


void printVertex(struct vertex *v){
	short i;
	printf("id=%hd x=%d y=%d %hd neighbor:(", 
		v->id, v->id >> SHIFT, v->id % MAXCOL, v->nNeighbor);
	for(i=0; i< v->nNeighbor;i++){
		printf("%hd ",v->neighbor[i]);
	}
	printf(") limit: (");
	for(i=0; i< v->nLimit; i++){
		printf("%hd ", v->limit[i]);
	}
	printf(") ");
	printf("dist: %d\n",v->dist);
}

struct vertex *newVertex(short x, short y){
	struct vertex *v;
	v = (struct vertex *) malloc(sizeof(struct vertex));
	v->id = (x << SHIFT) + y;
	v->dist = INTMAX;
	v->nNeighbor = 0;
	v->nLimit = 0;
	memset(v->limit, 0, sizeof(int)*500);
	if(x - 1 >= 0){
		v->neighbor[v->nNeighbor++] = ((x-1) << SHIFT) + y;
	}
	if(x + 1 < nv){
		v->neighbor[v->nNeighbor++] = ((x+1) << SHIFT) + y;
	}
	if(y - 1 >=0 ){
		v->neighbor[v->nNeighbor++] = (x << SHIFT) + y - 1;
	}
	if(y + 1 < nh ){
		v->neighbor[v->nNeighbor++] = (x << SHIFT) + y + 1;
	}
	return v;
}

int permitStep(struct vertex *v, int step){
	short i;
	for(i=0; i< v->nLimit; i++){
		if(v->limit[i] == step) return 0;
	}
	return 1;
}

int removeNeighbor(struct vertex *v, short neighborId){
	short i;
	if (NULL == v){
		printf("ERROR 014: null pointer\n");
		return FAIL;
	}
	i=0;
	while((i < v->nNeighbor) && (v->neighbor[i] != neighborId)){
		i++;
	}
	if(i < v->nNeighbor){
		v->neighbor[i] = v->neighbor[v->nNeighbor - 1];
		v->nNeighbor -= 1;
	}
	return SUCCESS;
}

int compareVertex(const void *a, const void *b){
	struct vertex *v1, *v2;
	v1 = (struct vertex *)a;
	v2 = (struct vertex *)b;
	return v2->dist - v1->dist;
}

int main(){
	short i, j, nObstacle, x1, y1, x2, y2;
	short tlimit, nTlimit, state;
	struct vertex **V, *v;
	struct qele *root, *qe;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	V = (struct vertex **) malloc(sizeof(struct vertex *)*MAXCOL*MAXCOL);
	
	while(2 == fscanf(fp, "%hd %hd", &nv, &nh)){
	
		for(x1=0; x1<nv; x1++){
			for(y1=0; y1<nh; y1++){
				V[(x1 << SHIFT) + y1] = newVertex(x1, y1);
			}
		}			


		fscanf(fp, "%hd", &nObstacle);

		
		for(i=0; i<nObstacle; i++){
			fscanf(fp, "%hd %hd %hd %hd", &x1, &y1, &x2, &y2);
			state = removeNeighbor(V[(x1 << SHIFT) + y1], (x2 << SHIFT) + y2);
			if(state == FAIL){
				printf("cannot remove neighbor %d from vertex %d\n", (x2 << SHIFT) + y2, (x1 << SHIFT) + y1);
				exit(0);	
			}
		}

		fscanf(fp, "%hd", &nTlimit);
		for(i = 0; i<nTlimit; i++){
			fscanf(fp, "%hd %hd %hd", &tlimit, &x1, &y1);
			V[(x1 << SHIFT) + y1]->limit[V[(x1 << SHIFT) + y1]->nLimit] = tlimit;
			V[(x1 << SHIFT) + y1]->nLimit += 1;
		}
		
		
		root = NULL;
		V[0]->dist = 0;
		q_add(V[0], &root, compareVertex);
		while(NULL != root){
			int step;
			struct vertex *targetVertex;
			qe = q_extract(&root, compareVertex);
			v = (struct vertex *) qe->key;
			free(qe);
			for(i = 0; i < v->nNeighbor; i++){
				step = v->dist + 1;
				targetVertex = V[v->neighbor[i]];
				while(!permitStep(targetVertex, step)){
					step++;
				}
				if(step < targetVertex->dist){
					targetVertex->dist = step;
					q_add(targetVertex, &root, compareVertex); 
				}
			}
		}
		if(DEBUG){
			for(x1=0; x1<nv; x1++){
				for(y1=0; y1<nh; y1++){
					printVertex(V[(x1 << SHIFT) + y1]);
				}
			}
		}		

		printf("%d\n", V[((nv-1) << SHIFT) + nh - 1]->dist);
		
		for(x1=0; x1<nv; x1++){
			for(y1=0; y1<nh; y1++){
				free(V[(x1 << SHIFT) + y1]);
			}
		}	
	}
	free(V);
	return 0;
}