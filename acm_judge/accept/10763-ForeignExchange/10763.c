#include <stdio.h>
#include <stdlib.h>
#define MAX 500001
#define DEBUG 0

struct Exchange{
	int src, dest;
};

int compareExchange(const void *a, const void *b){
	struct Exchange *x, *y;
	x = (struct Exchange *)a;
	y = (struct Exchange *)b;
	if(x->src != y->src) return x->src - y->src;
	else if (x->dest != y->dest) return x->dest - y->dest;
	else return 0;
}

struct Exchange *inc, *dec;
int n, nInc, nDec;


int main(){
	int i, j, u, v;
	char mismatch;
	inc = (struct Exchange *) malloc(sizeof(struct Exchange)*MAX);
	dec = (struct Exchange *) malloc(sizeof(struct Exchange)*MAX);
	while(1 == scanf("%d",&n)){
		if(0 == n){
			break;
		}
		nInc = 0;
		nDec = 0;
		for(i=n-1; i>=0; i--){
			scanf("%d %d", &u, &v);
			if(u > v){
				dec[nDec].src = u;
				dec[nDec].dest = v;
				nDec++;
			}
			else{
				inc[nInc].src = v;
				inc[nInc].dest = u;
				nInc++;
			}
		}
		if(DEBUG){
			printf("nDec:%d nInc:%d\n",nDec, nInc);
		}
		if(nDec != nInc){
			printf("NO\n");
			continue;
		}
		qsort(inc, nInc, sizeof(struct Exchange), compareExchange);
		qsort(dec, nDec, sizeof(struct Exchange), compareExchange);
		mismatch = 0;
		for(i=0; (i<nDec) && (!mismatch); i++){
			
			if( (inc[i].src != dec[i].src) || (inc[i].dest != dec[i].dest)){
				if(DEBUG){
					printf("inc[i]=(%d %d) dec[i]=(%d %d)\n",inc[i].src, inc[i].dest, dec[i].src, dec[i].dest);
				}
				printf("NO\n");
				
				mismatch = 1;
			}
		}
		if(!mismatch){
			printf("YES\n");
		}
	}
	free(inc);
	free(dec);
	return 0;
}