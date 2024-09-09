#include <stdio.h>
#include <stdlib.h>
#include <search.h>

struct BCNum{
	short n, k, m;
	unsigned long long count;
};

int compareBCNum(const void *a, const void *b){
	struct BCNum *x, *y;
	x = (struct BCNum *)a;
	y = (struct BCNum *)b;
	if(x->n != y->n) return x->n - y->n;
	else if (x->k != y->k) return x->k - y->k;
	else if (x->m != y->m) return x->m - y->m;
	else return 0;
}

unsigned long long findAns(short n, short k,short m, void **root){
	unsigned long long ans = 0;
	struct BCNum *bc, *match;
	 
	if((n > k*m) || (n < k)) return 0;
	else if ((n == k*m) || (n == k) || ((n<=m) && (n>=1) && (k==1))) return 1;
		
	bc = (struct BCNum *) malloc(sizeof(struct BCNum));
	bc->n = n;
	bc->k = k;
	bc->m = m;
	
	match = tfind(bc, root, compareBCNum);
	if(match != NULL){
		free(bc);
		match = *(struct BCNum **) match;
		return match->count;
	}
	else{
		short i;
		for(i=1; i<=m; i++){
			ans += findAns(n-i, k-1, m, root);
		}
		bc->count = ans;
		tsearch(bc, root, compareBCNum);
		return ans;
	}
}

int main(){
	void *root;
	short n, k, m;
	unsigned long long ans;
	root = NULL;
	while(3 == scanf("%hd %hd %hd",&n, &k, &m)){
		ans = findAns(n, k, m, &root);
		printf("%llu\n", ans);
	}
	tdestroy(root, free);
	return 0;
}