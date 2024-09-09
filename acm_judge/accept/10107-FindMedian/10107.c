#include <stdio.h>
#include <stdlib.h>




struct node {
	struct node *rc, *lc;
	int key;
	int occr;
	int lsize;
};


int compare_int(const void *x, const void *y){
	return *(int *)x - *(int *)y; 
}

struct node *new_node(int v){
	struct node *e;
	e = malloc(sizeof(struct node));
	if (NULL == e){
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	e->rc = NULL;
	e->lc = NULL;
	e->key = v;
	e->occr = 1;
	e->lsize = 0;
	return e;
}



struct node *insert(struct node *root, int v){
	/*v is the value to be inserted*/
	struct node *e;
	struct node *target,*parent;
	int duplicate_key;
	
	e = new_node(v);
	if ( root == NULL ){
		root = e;
		return root;
	}
	

	target = root;
	duplicate_key = 0;
	while((NULL != target)&&(!duplicate_key)){
		parent = target;
		if ( v > target->key ){
			target = target->rc;
		}
		else if (v < target->key){
			target->lsize += 1;
			target = target->lc;
		}
		else {
			target->occr += 1;
			duplicate_key = 1;
		}
	}
	if(!duplicate_key){
		if(v > parent->key){
			parent->rc = e;
		}
		else{
			parent->lc = e;
		}
	}
	else{
		free(e);
	}
	return root;
} 



int query_by_rank(struct node *root, int rank){
	if ((rank >= root->lsize) && (rank < root->lsize + root->occr)){
		return root->key;
	}
	else if (rank < root->lsize){
		return query_by_rank(root->lc, rank);
	}
	else{
		return query_by_rank(root->rc, rank - root->lsize - root->occr);
	}
}





int main(){
	struct node *root;


	int i,input,median;
	int ts;

	root = NULL;
	ts=0;	
	while(1==scanf("%d",&input)){
	
		root = insert(root, input);
		ts++;
		if ( ts % 2 == 1){
			median = query_by_rank(root,ts/2);
		}
		else {
			median = query_by_rank(root,ts/2);
			median = median + query_by_rank(root,(ts/2)-1);
			median = median >> 1;
		}
		printf("%d\n",median);
	}	
	return 0;	
}