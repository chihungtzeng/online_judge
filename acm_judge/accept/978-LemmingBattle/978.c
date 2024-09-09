#include <stdio.h>
#include <stdlib.h>
#define GREEN 1
#define BLUE 2
#define DRAW 0
#define MAX 10000

int compareInt(const void *k1, const void *k2){
	int x,y;
	x = *(int *)k1;
	y = *(int *)k2;
	return x-y;
}

int min(int a, int b){
	if (a > b) return b;
	else return a;
}

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

int findWinner(int B, struct qele **green, int SG, struct qele **blue, int SB){
	int gSuvivor[MAX], bSuvivor[MAX];
	int nGS, nBS, *gsLife, *bsLife;
	int nFight, i;
	struct qele *gSolider, *bSolider;
	
	while((SG >0) && (SB > 0)){
		nFight = min(B, min(SG, SB));
		nGS = 0;
		nBS = 0;
		for(i=nFight; i>=1; i--){
			gSolider = q_extract(green, compareInt);
			bSolider = q_extract(blue, compareInt);
			gsLife = (int *) gSolider->key;
			bsLife = (int *) bSolider->key;
			if(*gsLife > *bsLife){
				gSuvivor[nGS++] = *gsLife - *bsLife;
			}
			else if (*gsLife < *bsLife){
				bSuvivor[nBS++] = *bsLife - *gsLife;
			}
			free(gsLife);
			free(bsLife);
			free(gSolider);
			free(bSolider);
		}

		for(i=0; i<nGS; i++){
			gsLife = (int *) malloc(sizeof(int));
			*gsLife = gSuvivor[i];
			q_add(gsLife, green, compareInt);
		}
		for(i=0; i<nBS; i++){
			bsLife = (int *) malloc(sizeof(int));
			*bsLife = bSuvivor[i];
			q_add(bsLife, blue, compareInt);
		}
		SG = SG - nFight + nGS;
		SB = SB - nFight + nBS;
	}
	
	if(SG > 0) return GREEN;
	else if (SB > 0) return BLUE;
	else return DRAW;
}

void q_output(struct qele **root){
	struct qele *q;
	int *i;
	while(*root != NULL){
		q = q_extract(root, compareInt);
		i = (int *) q->key;
		printf("%d\n",*i);
		free(i);
		free(q); 
	}
}

int main(){
	short nTest;
	int B, SG, SB, i, j, *solider;
	struct qele *green, *blue, *q, *winnerGroup;
	short winner;
	char first = 1;

	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		scanf("%d %d %d",&B, &SG, &SB);
		solider = (int *) malloc(sizeof(int));
		scanf("%d",solider);
		green = new_qele(solider);
		for(i=1; i< SG; i++){
			solider = (int *) malloc(sizeof(int));
			scanf("%d",solider);
			q_add(solider, &green, compareInt);
		}
		solider = (int *) malloc(sizeof(int));
		scanf("%d",solider);
		blue = new_qele(solider);
		for(i=1; i< SB; i++){
			solider = (int *) malloc(sizeof(int));
			scanf("%d",solider);
			q_add(solider, &blue, compareInt);
		}
		winner = findWinner(B, &green, SG, &blue, SB);
		if(winner == DRAW){
			printf("green and blue died\n");
		} 
		else if (winner == GREEN){
			printf("green wins\n");
			q_output(&green);
		}
		else if (winner == BLUE){
			printf("blue wins\n");
			q_output(&blue);
		}
		else {
			printf("undefined\n");
			exit(0);
		}
	}
	free(green);
	free(blue);
	return 0;
}