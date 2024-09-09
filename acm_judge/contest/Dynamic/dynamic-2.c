#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 200010
#define DEBUG 0

struct Pair {
	int u, v;
};


int *tmp, *a;
int len, nQuery;
int nMatch, target;
void *root[MAX];
int k=0;

struct Pair *newPair(int u, int v){
	struct Pair *p;
	p = (struct Pair *) malloc(sizeof(struct Pair));
	p->u = u;
	p->v = v;
	if((u >= v) || (u > len) || (v > len)){
		printf("new pair malfunction: u=%d, v=%d\n", u,v);
	}
	return p;
}

int comparePair(const void *a, const void *b){
	struct Pair *x, *y;
	x = (struct Pair *)a;
	y = (struct Pair *)b;
	if(x->u != y->u) return x->u - y->u;
	else return x->v - y->v;
}


long long mergeSort(int a[], int len){
	long long nSwap;
	int idx = 0, i;
	struct Pair *p;
	int middle, left, right;
	if(len <= 1) return 0;
	
	
	middle = len >> 1;
	nSwap = mergeSort(a, middle);
	nSwap += mergeSort(&a[middle], len - middle);
	left = 0;
	right = middle;
	while( (left < middle) && (right < len)){
		if(a[left] <= a[right]){			
			tmp[idx++] = a[left++];
		}
		else{
			nSwap += middle - left;
			for(i=left; i<middle; i++){
				p = newPair(a[right], a[i]);
				tsearch(p, &root[a[right]], comparePair);
				p = newPair(a[right], a[i]);
				tsearch(p, &root[a[i]], comparePair);
			}
			tmp[idx++] = a[right++];
		}
	}
	while(left < middle){
		tmp[idx++] = a[left++];
	}
	while(right < len){
		tmp[idx++] = a[right++];
	}
	memcpy(a, tmp, sizeof(int)*len);
	return nSwap;
}

void twalkDump(const void *rootp, const VISIT way, const int depth){
	struct Pair *p;
	
	if((way == leaf) || (way == postorder)){	
		p = *(struct Pair **)rootp;
		printf("%d %d\n", p->u, p->v);	
	}
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
	struct Pair *p;
	void *tmp;
	int index;
	if((way == leaf) || (way == postorder)){
		
		p = *(struct Pair **)rootp;
		
			index = p->u + p->v - target; 
			nMatch++;
			if(root[index] == NULL) return ;
			tmp = tfind(p, &root[index], comparePair);
			if(NULL != tmp){
				p = *(struct Pair **) tmp;
				tdelete(p, &root[index], comparePair);
				free(p);
			}
			else{
				printf("[ERROR]: (%d %d) should be in tree %d, Case %d, len=%d, nQuery=%d\n", 
					p->u, p->v, index, k, len, nQuery);
				printf("----tree %d-----\n", index);
				twalk(root[index], twalkDump);
				puts("----");
			}
	}
}

int findNumInversion(){
	nMatch = 0;
	if(DEBUG){
		/*
		puts("----");
		twalk(root[target], twalkDump);
		puts("----");
		*/
	}
	if(root[target] == NULL) return 0;
	twalk(root[target], twalkAction);
	
	tdestroy(root[target], free);
	root[target] = NULL;
	return nMatch;
}

int main(){
	int i, j;
	struct Pair *pair;
	FILE *fp;
	long long ans;
	
	
	/*fp = (DEBUG)? fopen("in2.txt", "r") : stdin;*/
	fp = (DEBUG)? fopen("dsmall.in", "r") : stdin;
	a = (int *) malloc(sizeof(int)*MAX);
	tmp = (int *) malloc(sizeof(int)*MAX);
	
	while(2 == fscanf(fp, "%d %d", &len, &nQuery)){
		for(i=0; i<len; i++){
			fscanf(fp, "%d", a + i );
			root[i] = NULL;
		}
		root[len] = NULL;
		k++;
		/*
		if(DEBUG){
		
			printf("Case %d:\n",k);
			for(i=0; i<len; i++){
				printf("%d ", a[i]);
			}
			printf("\n");
		}
		*/
		ans = mergeSort(a, len);
				
		for(i=0; i<nQuery; i++){
			printf("%lld\n", ans);
			fscanf(fp, "%d", &target);
			ans -= findNumInversion();
			if(ans < 0){
				printf("case %d: ans=%lld len = %d nQuery=%d\n", k, ans, len, nQuery);
			}		
		}
		for(i=len; i>=0; i--){
			if(root[i] != NULL){
				tdestroy(root[i], free);
				root[i] = NULL;
			}
		}
	}
	free(a);
	
	free(tmp);
	return 0;
}

