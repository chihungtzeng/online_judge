#include <stdio.h>
#include <stdlib.h>
#include <search.h>

struct partition{
	int n, m;
	int value;
};

struct partition *newPartition(int n, int m, int value){
	struct partition *p;
	p = (struct partition *) malloc(sizeof(struct partition));
	p->n = n;
	p->m = m;
	p->value = value;
	return p;
}

int comparePartition(const void *a, const void *b){
	struct partition *p1, *p2;
	p1 = (struct partition *)a;
	p2 = (struct partition *)b;
	if (p1->n != p2->n) return p1->n - p2->n;
	else return p1->m - p2->m;
}

int findNPartition(int n, int m, void **root){
	struct partition *p, *match;
	int tmp1, tmp2;
	if ((m == 0) && (n == 0)) return 1;
	if ((m == 0) && (n != 0)) return 0;
	if ((m < 0) || (n < 0)) return 0;
	
	
	p = newPartition(n, m, 0);
	match = *(struct partition **) tsearch(p, root, comparePartition);
	if(match == NULL){
		printf("search failed");
		return -1;
	}
	else if(match == p){
		tdelete(p, root, comparePartition);
		free(p);
	}
	else{
		return match->value;
	}
	
	tmp1 = findNPartition(n - 1, m - 1, root);
	tmp2 = findNPartition(n - m, m, root);
	p = newPartition(n, m, tmp1 + tmp2);
	tsearch(p, root, comparePartition);
	return p->value;
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
		ans = 0;
		for(i=
		ans += findNPartition(n, m, &root);
		
		printf("Case %d: %d\n",k, ans);
		k++;
	}
	tdestroy(root, free);
	return 0;
}