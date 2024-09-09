#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define DEBUG 0


struct bc {
	long n, m;
	long value;
};

struct bc *newBC(long n, long m){
	struct bc *c;
	c =(struct bc *)malloc(sizeof(struct bc));
	c->n = n;
	c->m = m;
	c->value = 0;
	return c;
} 

int compareBC(const void *a, const void *b){
	struct bc *x, *y;
	x = (struct bc *)a;
	y = (struct bc *)b;
	if(x->n != y->n) return x->n - y->n;
	else return x->m - y->m; 
}

long rchoose(long n, long m, void **root){
	long x, y;
	struct bc *bnm, *match, *target;
	
	if ((n==m) || (m==0)) return 1;
	if (m == 1) return n;
	if (n < m) return 0;
	
	/*check if C(n,m) is in the search tree*/
	bnm = newBC(n,m);
	match = *(struct bc **) tsearch(bnm, root, compareBC);
	if(!match){
		printf("No sufficint space\n");
		exit(0);
	}
	else if (match != bnm){
		/*C(n, m) has been in the search tree*/
		if(DEBUG){
			printf("C(%ld %ld)=%ld has been in the tree\n",n, m, match->value);
		}
		free(bnm);
		return match->value;
	}
	else {
		tdelete(bnm, root, compareBC);
	}
	
	x = rchoose(n-1, m-1, root);
	y = rchoose(n-1, m, root);
	bnm->value = x + y;
	if(DEBUG){
		printf("insert C(%ld %ld)=%ld\n",n,m,bnm->value);		
	}	
	tsearch(bnm, root, compareBC);
	
	return bnm->value;
}

int main(){
	
	long n, m, m2;
	short done;
	void *root = NULL;
	
	
	done = 0;
	while(!done){
		scanf("%ld %ld",&n, &m);
		if((n==0) && (m==0)){
			done = 1;
			continue;
		}
		m2 = (m > n-m)? n-m : m;
		
		printf("%ld things taken %ld at a time is %ld exactly.\n",n, m, rchoose(n, m2, &root));
	}
	tdestroy(root, free);
	return 0;
}
