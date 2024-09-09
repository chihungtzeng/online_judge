#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#define MAXN 100001
#define MAXBUCKET 501
#define DEBUG 0

struct Num{
	int num;
	char isRepeat;
};



int bucket[MAXBUCKET];
char repeat[MAXN];
void *root;
FILE *fp;
long long ans;
int MOD;

struct Num * newNum(int n){
	struct Num *ptr;
	ptr = (struct Num *) malloc(sizeof(struct Num));
	ptr->num = n;
	ptr->isRepeat = 0;
	return ptr;
}

int compareNum(const void *a, const void *b){
	struct Num *x, *y;
	x= (struct Num *)a;
	y= (struct Num *)b;
	return x->num - y->num;
}

void readInput(int nNum, int MOD){
	int i, ai;
	int idx;
	struct Num *xNum;
	void *match;
	memset(bucket, 0, sizeof(int)*MAXBUCKET);
	memset(repeat, 0, sizeof(char)*MAXN);
	for(i=nNum; i>0; --i){
		fscanf(fp, "%d", &ai);
		xNum = newNum(ai);
		match = tsearch(xNum, &root, compareNum);
		if(*(struct Num **)match != xNum){
			free(xNum);
			xNum = *(struct Num **)match;
			xNum->isRepeat = 1;
		}
		else{
			if(ai >= 0){
				++bucket[ai % MOD];
			}
			else{
				idx = MOD - (abs(ai) % MOD);
				if(idx == MOD) idx = 0;	
				++bucket[idx];
			}
		}
	}
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct Num *xNum;
	if((which == leaf) || (which == postorder)){
		xNum = *(struct Num **)rootp;
		
		if((xNum->isRepeat && (xNum->num << 1) % MOD == 0)) ans++;
	}
}

void findAns(int MOD){
	ans = bucket[0]*(bucket[0] - 1) >> 1;
	int i;

	if(DEBUG){
		for(i=0; i<MAXBUCKET; i++){
			if(bucket[i] != 0){
				printf("bucket %d: %d\n", i, bucket[i]);
			}
		}
	}	
	
	if(MOD & 1){
		for(i=MOD >> 1; i>=1; i--){
			ans += bucket[i]*bucket[MOD - i];
		}
	}
	else{
		for(i = (MOD >> 1) - 1; i>=1; i--){
			ans += bucket[i] * bucket[MOD - i];
		}
		i = MOD >> 1;
		ans += bucket[i]*(bucket[i] - 1) >> 1;
	}	
	twalk(root, twalkAction);
}

int main(){
	char nTest, k = 1;
	
	int nNum;
	fp = (DEBUG)? fopen("in4.txt","r") : stdin;
	
	fscanf(fp, "%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		root = NULL;
		fscanf(fp, "%d %d", &nNum, &MOD);
		readInput(nNum, MOD);
		findAns(MOD);
		printf("Case %hhd: %lld\n", k++, ans);
		tdestroy(root, free);
	}
	return 0;
}