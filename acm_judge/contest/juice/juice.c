#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

struct Juice {
	int start, end;
	int length;
}

int compareJuice(const void *a, const void *b){
	struct Juice *x, *y;
	x = (struct Juice *)a;
	y = (struct Juice *)b;
	if(x->length != y->length) return x->length - y->length;
	if(x->start != y->start) return x->start - y->start;
	return x->end - y->end;
}

int solve(int nJuice, struct Juice juice[]){
	int ans = 0;
	int i, s, t, minLength = 1000000000;
	
	if(nJuice <= 1) return nJuice;

	for(i=0; i<nJuice; ++i){
		if(juice[i].length < minLength){
			s = juice[i].start;
			t = juice[i].end;
		}
	}	
	
	
	
}

int main(){
	int nTest, k=1;
	int nJuice;
	struct Juice juice[MAX];
	int ans;
	scanf("%hd", &nTest);
	while(nTest > 0){
		--nTest;
		scanf("%d", &nJuice);
		for(i=0; i<nJuice; ++i){
			scanf("%d %d", &juice[i].start, &juice[i].end);
			juice[i].length = juice[i].start - juice[i].end; 
		}
		ans = solve(nJuice, juice);
		printf("Case #%hd: %d\n", k++, ans);
	}
	return 0;
}