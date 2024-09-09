#include <stdio.h>
#include <stdlib.h>
#include <search.h>

struct sn{
	long index;
	int value;
};

void *root = NULL;	

int compareSn(const void *a, const void *b){
	struct sn *x, *y;
	x = (struct sn *)a;
	y = (struct sn *)b;
	return x->index - y->index;
}

	

int gs(long  n){
	int ans, tmp;
	struct sn *e, *match;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n <= 0) return 0;
	
	e = (struct sn *) malloc(sizeof(struct sn));
	if(e == NULL){
		printf("No sufficient space\n");
		exit(0);
	}
	e->index = n;
	match = *(struct sn **) tsearch((void *) e, &root, compareSn);
	if(match == NULL){
		printf("No sufficient space\n");
		exit(0);
	}
	else if (match != e){
		ans = match->value;
		free(e);
		return ans;
	}
	else {
		tmp = gs(n - 1);
		ans = 1 + gs( n - gs(tmp) );
		e->value = ans;
		return ans;
	}
}


int main(){
	
	long n;
	int ans;	
	
	
	while(1){
		scanf("%ld",&n);
		if(n == 0){
			break;
		}
		printf("n=%ld\n",n);	
		ans = gs(n);
		printf("%d\n",ans);
	}	
	tdestroy(root, free);
	return 0;
}