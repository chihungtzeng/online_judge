#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define MAX 2000
#define UPWARD 0
#define DOWNWARD 1
#define BACKWARD 2
#define FORWARD 3
#define YES 1
#define NO 0

struct qele {
	void *key;
	struct qele *llink;
	struct qele *rlink;
	int dist;
};

struct cell{
	int row, col, z;
	int dist; 
};

struct cell *newCell(int z, int row, int col, int dist){
	struct cell *e;
	e = (struct cell *) malloc(sizeof(struct cell));
	e->row = row;
	e->col = col;
	e->z = z;
	e->dist = dist;
	return e;
}

int compareCell(struct cell *a, struct cell *b){
	struct cell *x, *y;
	x = (struct cell *) a;
	y = (struct cell *) b;
	return y->dist - x->dist;
}

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
	if(*root == NULL){
		*root = newe;
	}
	else {
		*root = q_merge(*root, newe, compr);
	}
}

struct qele *q_extract(struct qele **root, int (compr)()){
	struct qele *result;
	if (NULL == *root) return NULL;
	result = *root;
	*root = q_merge((*root)->llink, (*root)->rlink, compr);
	
	return result; 
}



/*global variables*/
char map[MAX][MAX];
int nRow, nCol;
int rStart, cStart, rEnd, cEnd;

int ifNoObstacle(int rs, int cs, int step, int orientation){
	int i;
	if(orientation == UPWARD){
		for(i=1;i<=step;i++){
			if(map[rs - i][cs] == '#') { return NO;}
		}
	}
	else if(orientation == DOWNWARD){
		for(i=1;i<=step;i++){
			if(map[rs + i][cs] == '#') { return NO;}
		}
	}
	else if(orientation == BACKWARD){
		for(i=1;i<=step;i++){
			if(map[rs][cs - i] == '#') { return NO;}
		}
	}
	else if(orientation == FORWARD){
		for(i=1;i<=step;i++){
			if(map[rs][cs+i] == '#') { return NO;}
		}
	}
	return YES;
}


void findAns(){
	int ***dist;
	struct cell *e;
	struct qele *root, *r;
	int i,j,k;
	int rc, cc, zc;
	int min_step;
	dist = (int ***) malloc(sizeof(int **)*3);
	for(i=0;i<3;i++){
		dist[i] = (int **) malloc(sizeof(int *)*nRow);
		for(j=0;j<nRow; j++){
			dist[i][j] = (int *) malloc(sizeof(int)*nCol);
			memset(dist[i][j], 0x7f, sizeof(int)*nCol);
			/*
			for(k=0;k<nCol;k++){
				dist[i][j][k] = 100;
			}
			*/
		}
		 
	}
	dist[0][rStart][cStart] = 0;
	e = newCell(0, rStart, cStart, 0);
	root = new_qele(e);
	
	while(root != NULL){
		int step;
		r = q_extract(&root, compareCell);
		e = (struct cell *) r->key;
		rc = e->row;
		cc = e->col;
		zc = e->z;
		step = zc + 1; 
		/*to left*/
		if((cc - step >= 0) && (ifNoObstacle(rc,cc,step,BACKWARD) == YES)){
			if ((dist[(zc + 1)%3][rc][cc - step] > e->dist + 1)){
				dist[(zc + 1)%3][rc][cc - step] = e->dist + 1;
				q_add(
					newCell((zc+1) % 3, rc, cc - step, dist[(zc + 1)%3][rc][cc - step]), 
					&root, compareCell);
			}
		}
		/*to right*/
		if((cc + step < nCol) && (ifNoObstacle(rc,cc,step,FORWARD) == YES)){
			if ((dist[(zc + 1)%3][rc][cc + step] > e->dist + 1)){
				dist[(zc + 1)%3][rc][cc + step] = e->dist + 1;
				q_add(
					newCell((zc+1) % 3, rc, cc + step, dist[(zc + 1)%3][rc][cc + step]), 
					&root, compareCell);
			}
		}
		/*to upper*/
		if((rc - step >= 0) && (ifNoObstacle(rc,cc,step,UPWARD) == YES)){
			if ((dist[(zc + 1)%3][rc - step][cc] > e->dist + 1)){
				dist[(zc + 1)%3][rc -step][cc] = e->dist + 1;
				q_add(
					newCell((zc+1) % 3, rc - step, cc, dist[(zc + 1)%3][rc - step][cc]), 
					&root, compareCell);
			}
		}
		/*to lower*/
		if((rc + step < nRow) && (ifNoObstacle(rc,cc,step, DOWNWARD) == YES)){
			if ((dist[(zc + 1)%3][rc + step ][cc] > e->dist + 1)){
				dist[(zc + 1)%3][rc + step][cc] = e->dist + 1;
				q_add(
					newCell((zc+1) % 3, rc + step, cc, dist[(zc + 1)%3][rc + step][cc]), 
					&root, compareCell);
			}
		}
		free(e);
		free(r);
	}
	if(DEBUG){
		for(i=0;i<nRow;i++){
			for(j=0;j<nCol;j++){
				printf("(%d %d %d) ",dist[0][i][j],dist[1][i][j],dist[2][i][j]);
			}
			printf("\n");
		}
	}
	
	min_step = 0x7f7f7f7f;
	for(i=0;i<3;i++){
		if(dist[i][rEnd][cEnd] < min_step){
			min_step = dist[i][rEnd][cEnd];
		}
	}
	if(min_step < 0x7f7f7f7f){
		printf("%d\n",min_step);
	}
	else{
		printf("NO\n");
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<nRow;j++){
			free(dist[i][j]);
		}
		free(dist[i]);
	}
	free(dist);
}

int main(){
	int nTest;	
	int i, j;
	char ch;
	char line[1000];
	fgets(line,1000,stdin);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line,1000,stdin);
		nRow = atoi(strtok(line," "));
		nCol = atoi(strtok(NULL," "));
		for(i=0; i<nRow; i++){
			fgets(line,1000,stdin);
			for(j=0;j<nCol;j++){
					ch = line[j];
					map[i][j] = ch;	
					if(ch == 'S'){
						rStart = i;
						cStart = j; 
					}
					else if (ch == 'E'){
						rEnd = i;
						cEnd = j;
					}
				if(DEBUG){
					printf("%c",ch);
				}
			}
			if(DEBUG){
				printf("\n");
			}
		}
		findAns();
	}
	
	return 0;
}