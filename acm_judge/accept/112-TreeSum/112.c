#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20000
#define DEBUG 0

struct node {
	int value;
	int sum;
	struct node *lc, *rc;
};


struct node *buildTree(char *expr){
	struct node *root;
	char c;
	char *lse,*rse;
	int sep,i,v;
	int lbrace;
	int rbrace;
	int neg=0;
	
	if (('(' == expr[0]) && (')' == expr[1])){
		return NULL;
	}
	
	root = (struct node *) malloc(sizeof(struct node));
	lse = (char *) malloc(sizeof(char)*MAX);
	rse = (char *) malloc(sizeof(char)*MAX);

	
	/*scan expr until lbrace==rbrace*/
	i=1;
	v=0;
	while(((expr[i] >= '0') && (expr[i]<='9')) || ('-' == expr[i])){
		if('-' == expr[i]){
			neg = 1;
			
		}
		else {
			v = 10*v + expr[i] - '0';
			
		}
		i++;
	}
	if (1 == neg){
		v = -v;
	}	
	
	sep = i;
	i=0;
	lbrace = 0;
	rbrace = 0;
	while((lbrace != rbrace)||(0 == lbrace)){
		c = expr[sep];
		if('(' == c) {
			lbrace++;
		}
		if (')' == c){
			rbrace++;
		}
		lse[i] = c;
		sep++;
		i++;
	}
	lse[i] = '\0';
	
	i=0;
	lbrace = 0;
	rbrace = 0;
	while((lbrace != rbrace)||(0 == lbrace)){
		c = expr[sep];
		if('(' == c) {
			lbrace++;
		}
		if (')' == c){
			rbrace++;
		}
		rse[i] = c;
		sep++;
		i++;
	}
	rse[i]='\0';

	if (DEBUG){
		printf("root value=%d, sep=%d \n",v,sep);
		printf("expr=%s lse=%s rse=%s\n",expr,lse,rse);
	}
	root->value = v;
	root->lc = buildTree(lse);
	root->rc = buildTree(rse);	
	
	free(lse);
	free(rse);
	return root;
}
void sumTree(struct node *root, int ss){
	if (NULL == root) return;
	if(DEBUG){
		printf("travse to a node with value %d\n",root->value);
	}
	root->sum = root->value + ss;
	if(NULL != root->lc) {
		sumTree(root->lc, root->sum);
	}
	if(NULL != root->rc) {
		sumTree(root->rc, root->sum);
	}
}
int query(int n, struct node *root){
	if (NULL == root){
		return 0;
	}
	if ((NULL == root->lc) &&(NULL == root->rc)){
		if (root->sum == n) return 1;
		else return 0;
	}
	return query(n,root->lc)+query(n,root->rc);
}

int ismyspace(char c){
	if ((' ' == c) || ('\t' == c) || ('\n' == c)){
		return 1;
	}
	else return 0;
}

int main(int argc, char *argv[]){
	int testValue;
	int scanComplete;
	int seLen;
	char *se;
	int lbrace,rbrace;
	char c;
	struct node *treeRoot;
	int result;
	
	se = (char *) malloc(sizeof(char)*MAX);
	
	while(1 == scanf("%d",&testValue)){
		seLen=0;
		scanComplete=0;
		lbrace = 0;
		rbrace = 0;
		
		while(!scanComplete){
			scanf("%c",&c);
			
			if('(' == c){
				lbrace++;
			}
			if(')' == c){ 
				rbrace++;
			}
			if(!ismyspace(c)){
				se[seLen] = c;
				seLen++;
			}
			if ((lbrace == rbrace)&&(lbrace != 0)){
				scanComplete=1;
				se[seLen] = '\0';
			}
		}
		if (DEBUG) {
			printf("Test Value: %d S expression: %s\n",testValue,se);
		}
		treeRoot=buildTree(se);
		sumTree(treeRoot,0);
		result = query(testValue,treeRoot);
		if(result > 0) printf("yes\n");
		else printf("no\n");
	}

	exit(0);
}