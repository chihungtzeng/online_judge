#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define DEBUG 0
#define MAXCOL 1000
#define BUFSIZE 10000

struct mazecell{
	int x,y;
	int d;
};

/*start of priority queue*/
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
/*End of priority queue*/

struct mazecell *new_mazecell(int xx, int yy, int cc){
	struct mazecell *e;
	e = (struct mazecell *)malloc(sizeof(struct mazecell));
	e->x = xx;
	e->y = yy;
	e->d = cc;
	return e;
}

int compareKey(const void *k1, const void *k2){
	struct mazecell x,y;
	x = *(struct mazecell *) k1;
	y = *(struct mazecell *) k2;
	if( x.d > y.d) return -1;
	else if (x.d < y.d ) return 1;
	else return 0;
}

int isValid(int row,int col,int nRow,int nCol){
	if ((row>=0) && (row<nRow) && (col>=0) && (col<nCol) ) return 1;
	else return 0;
}

int update_cost(int maze[MAXCOL][MAXCOL], int cost[MAXCOL][MAXCOL],int row, int col,int rc,int cc){
	int tmp;
	tmp = cost[row][col]+maze[rc][cc];
	if (cost[rc][cc] > tmp){
		cost[rc][cc] = tmp;
		return 1;
	}
	return 0;
}

void find_ans(int maze[MAXCOL][MAXCOL], int cost[MAXCOL][MAXCOL],int nRow,int nCol){
	int i,j;
	int row,col,rc,cc;
	int tmp;
	struct mazecell *k;
	struct qele *root,*qelement;
	
	cost[0][0] = maze[0][0];
	
	k = new_mazecell(0,0,maze[0][0]);	
	root = new_qele(k);
	
	while(root != NULL){
		qelement = (struct qele *) q_extract(&root,compareKey);
		k = (struct mazecell *) qelement->key;
		
		row = k->x;
		col = k->y;
		free(k);
		free(qelement);
		
		rc = row-1;
		cc = col;
		if(isValid(rc,cc,nRow,nCol)){
			if(update_cost(maze,cost,row,col,rc,cc)){
				k = new_mazecell(rc,cc,cost[rc][cc]);
				q_add(k,&root,compareKey);
			}
		}
		rc = row;
		cc = col-1;
		if(isValid(rc,cc,nRow,nCol)){
			if(update_cost(maze,cost,row,col,rc,cc)){
				k = new_mazecell(rc,cc,cost[rc][cc]);
				q_add(k,&root,compareKey);
			}
		}
		rc = row+1;
		cc = col;
		if(isValid(rc,cc,nRow,nCol)){
			if(update_cost(maze,cost,row,col,rc,cc)){
				k = new_mazecell(rc,cc,cost[rc][cc]);
				q_add(k,&root,compareKey);
			}
		}
		rc = row;
		cc = col+1;
		if(isValid(rc,cc,nRow,nCol)){
			if(update_cost(maze,cost,row,col,rc,cc)){
				k = new_mazecell(rc,cc,cost[rc][cc]);
				q_add(k,&root,compareKey);
			}
		}

	}
}


int main(){
	int nG,nRow,nCol;
	int maze[MAXCOL][MAXCOL];
	int cost[MAXCOL][MAXCOL];
	int i,j,k;
	int ans;
	char buf[BUFSIZE];
	char ch;
	FILE *fp;
	
	
	if(DEBUG){
		fp = fopen("in.txt","r");
		if (NULL == fp) {
			printf("open file failed\n");
			exit(1);
		}
	}
	else{
		fp = stdin;
	}
	
	
	
	
	fgets(buf,BUFSIZE,fp);
	
	nG=atoi(buf);
	if(DEBUG) {printf("nG = %d\n",nG);}
	for(i=0;i<nG;i++){
		nRow=0;
		nCol=0;
		fscanf(fp,"%d %d",&nRow,&nCol);

		for(j=0;j<nRow;j++){
			k=0;
			while(k<nCol){
				ch = fgetc(fp);
				if(isdigit(ch)){
					maze[j][k] = ch - '0';
					cost[j][k] = INT_MAX;
					k++;
				}
			}
		}
		
		if(DEBUG){
			printf("nRow=%d nCol=%d\n",nRow,nCol);
			for(j=0;j<nRow;j++){
				for(k=0;k<nCol;k++){
					printf("%d ",maze[j][k]);
				}
				printf("\n");
			}
		}
		/*start calculating maze[i][j]
		for a cell (i,j), its key = i*nRow+j; 
		*/
		
		find_ans(maze,cost,nRow,nCol);

		/*-------------------*/
		if(DEBUG){
			printf("nRow=%d nCol=%d\n",nRow,nCol);
			for(j=0;j<nRow;j++){
				for(k=0;k<nCol;k++){
					printf("%5d ",cost[j][k]);
				}
				printf("\n");
			}
		}		
		
		printf("%d\n",cost[nRow-1][nCol-1]);
		

	}

	return 0;
}
