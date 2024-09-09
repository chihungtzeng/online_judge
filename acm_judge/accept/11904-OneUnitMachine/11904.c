/*TLE*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 1024
#define MOD 1000000007
#define DEBUG 0

struct bCoef{
	int n, m;
	int value;
};

void *root;

struct bCoef *newBCoef(int n, int m, int value){
	struct bCoef *b;
	b = (struct bCoef *) malloc(sizeof(struct bCoef));
	b->n = n;
	b->m = m;
	b->value = value;
	return b;
}

int compareBCoef(const void  *a, const void  *b){
	struct bCoef *x, *y;
	x = (struct bCoef *)a;
	y = (struct bCoef *)b;
	if(x->n != y->n) return x->n - y->n;
	else return x->m - y->m; 
}

int searchBCoef(int n, int m){
	struct bCoef *b;
	void *match;
	int result, x, y;
	if(m == 0) return 1;
	if(m == 1) return n;
	if(m == n) return 1;
	if((n <= 0) || (m < 0)) return 0;
	if(n - m < m) return searchBCoef(n, n - m);  
	
	b = newBCoef(n, m, 0);
	match = tfind(b, &root, compareBCoef);
	if(match != NULL){
		free(b);
		b = *(struct bCoef **) match;
		return b->value;
	}
	else{
		x = searchBCoef(n-1, m-1);
		y = searchBCoef(n-1, m);
		result = (x + y) % MOD;
		b->value = result;
		tsearch(b, &root, compareBCoef);
		return result;
	}
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct bCoef *b;
	b = *(struct bCoef **) rootp;
	if( (which == leaf) || (which == postorder)){
		printf("%d choose %d = %d\n",b->n, b->m, b->value);
	}
	return ;
}

int findAns(short nJob, int job[]){
	long long result = 1;
	short i;
	int nPos, nObj, sum;
	
	sum = job[0];
	
	for(i=1; i<nJob; i++){
		result *= searchBCoef(sum + job[i] - 1, job[i] - 1);
		sum += job[i];
		result = result % MOD;
	}
	
	
	return (int)result;
}

int main(){
	char nTest, k = 1;
	short nJob, i;
	int job[MAX], ans;
	
	root = NULL;
	
	
	scanf("%hhd",&nTest);
	
	while(k <= nTest){
		scanf("%hd", &nJob);
		for(i=0; i<nJob; i++){
			scanf("%d", job+i);
		}
		ans = findAns(nJob, job);
		printf("Case %hhd: %d\n", k, ans);
		k++;
	}
	if(DEBUG){
		twalk(root, twalkAction);
	}
	tdestroy(root, free);
	return 0;
}