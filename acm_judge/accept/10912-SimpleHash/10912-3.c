#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define VERBOSE 0

struct partition{
	int n, m, base;
	int value;
};

struct partition *newPartition(int n, int m, int base, int value){
	struct partition *p;
	p = (struct partition *) malloc(sizeof(struct partition));
	p->n = n;
	p->m = m;
	p->base = base;
	p->value = value;
	return p;
}

int comparePartition(const void *a, const void *b){
	struct partition *p1, *p2;
	p1 = (struct partition *)a;
	p2 = (struct partition *)b;
	if (p1->n != p2->n) return p1->n - p2->n;
	else if (p1->m != p2->m) p1->m - p2->m;
	else return p1->base - p2->base;
}

int findNPartition(int n, int m, int base, void **root){
	struct partition *p, *match;
	int i, ans, stop;
	
	/*if( m == 0) return 0;*/
	if( m == 0) return 0;
	if((n + base <= 0) && (m == 1)) return 0;
	if((n + base >= 1) && (n + base <= 26) && (m == 1)) return 1;
	if((n + base >= 27) && (m == 1)) return 0;
	if((m > 26) || (n>351)) return 0;
	
	

	
	p = newPartition(n, m, base, 0);
	match = *(struct partition **) tsearch(p, root, comparePartition);
	if(match == NULL){
		printf("search failed");
		return 0;
	}
	else if(match == p){
		tdelete(p, root, comparePartition);
		free(p);
	}
	else{
		return match->value;
	}
	ans = 0;
	
	for(i=1; (i <= n/m); i++){
		if(n - i*m != 0){
			ans += findNPartition(n - i*m, m - 1, base + i , root);
		}
	}
	if(VERBOSE){
		printf("find answer: n=%d, m=%d, base=%d ans=%d\n", n, m, base, ans);
	}
	p = newPartition(n, m, base, ans);
	tsearch(p, root, comparePartition);
	return ans;
}

int main(){
	int n, m, ans;
	int k, i;
	void *root;
	
	root = NULL;
	k = 1;
	while(1){
		scanf("%d %d",&m, &n);
		if((0 == n) && (0 == m)){
			break;
		}
		ans = findNPartition(n, m, 0, &root);
		printf("Case %d: %d\n",k, ans);
		k++;
	}
	tdestroy(root, free);
	return 0;
}