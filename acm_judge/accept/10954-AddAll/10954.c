#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5001
#define DEBUG 0

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

int compareInt(const void *k1, const void *k2){
	int x,y;
	x = *(int *)k1;
	y = *(int *)k2;
	return y-x;
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

int main(){
	int nNum;
	int *input, sum;
	struct qele *minHeap, *m1, *m2;
	short i, done;
	long ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	
	while(1){
		fscanf(fp, "%d", &nNum);
		if(nNum == 0){
			break;
		}		
		input = (int *) malloc(sizeof(int)); 
		fscanf(fp, "%d", input);
		minHeap = new_qele(input);	
		for(i = nNum -1; i >= 1; i--){
			input = (int *) malloc(sizeof(int)); 
			fscanf(fp, "%d", input);
			q_add(input, &minHeap, compareInt);	
		}
		ans = 0;
		done = 0;
		while(!done){
			m1 = q_extract(&minHeap, compareInt);
			if (minHeap == NULL){
				done = 1;
			}
			else {
				m2 = q_extract(&minHeap, compareInt);
				sum = *(int *)m1->key + *(int *) m2->key;
				ans += sum;
				input = (int *) malloc(sizeof(int));
				*input = sum;
				q_add(input, &minHeap, compareInt); 
				free(m2->key);
				free(m2);
			}
			free(m1->key);
			free(m1);
		}
		printf("%ld\n",ans);
	}

	
	return 0;
}