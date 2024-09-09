#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 200010

#define INF 10000000
#define DEBUG 0

struct Pair {
	int u, v;
};


int *tmp, *a;
int len;
int nMatch, target;
void *root;


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
				tsearch(p, &root, comparePair);
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

void twalkAction(const void *rootp, const VISIT way, const int depth){
	struct Pair *p;
	if((way == leaf) || (way == postorder)){
		p = *(struct Pair **)rootp;
		
		if((p->u == target) || (p->v == target)){
			nMatch++;
			/*printf("+++No %d: (%d %d)\n", nMatch, p->u, p->v);*/
		}
	}
}

void twalkDelete(const void *rootp, const VISIT way, const int depth){
	struct Pair *p;
	if((way == leaf) || (way == postorder)){
		p = *(struct Pair **)rootp;
		
		if((p->u == target) || (p->v == target)){
			nMatch++;
			tdelete(p, &root, comparePair);
			free(p);
		}
	}
}

void removeElement(){
	nMatch = 1;
	while(nMatch){
		nMatch = 0;
		twalk(root, twalkDelete);
	}
}

int findNumInversion(){
	nMatch = 0;
	twalk(root, twalkAction);
	return nMatch;
}

int main(){
	int i, j, nQuery;
	struct Pair *pair;
	FILE *fp;
	long long ans;
	int k=0;
	
	/*fp = (DEBUG)? fopen("in2.txt", "r") : stdin;*/
	fp = (DEBUG)? fopen("dsmall.in", "r") : stdin;
	a = (int *) malloc(sizeof(int)*MAX);
	tmp = (int *) malloc(sizeof(int)*MAX);
	
	while(2 == fscanf(fp, "%d %d", &len, &nQuery)){
		
		root = NULL;
		for(i=0; i<len; i++){
			fscanf(fp, "%d", a + i );
		}
		/*
		if(DEBUG){
			k++;
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
			removeElement();
		}
		
		tdestroy(root, free);
	}
	free(a);
	
	free(tmp);
	return 0;
}

