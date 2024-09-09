#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64
#define MAXTNUM 65536
#define DEBUG 0
#define VERBOSE 1

struct structTNum{
	short pos;
	short quota;
	char tNum[MAX];
};


short N, K, M;
short nQuery;
int nTNum;
long tNum[MAXTNUM];

int queryByIndex(long target){

	int i;
	for(i=0; i<nTNum; i++){
		if(tNum[i] == target){
			return i + 1;
		}
	}
	
	return -1;

}

long atoil(char *s){
	int len, i;
	long result = 0;
	len = strlen(s);
	for(i=0; i < N; i++){
		result = (result << 1) + s[i] - '0'; 
	}
	return result;
}

long str2tnum(char *s){
	char t[MAX];
	int i,j,idx;
	short digit;
	long result = 0;
	idx = 0;
	for(i=0;i<K;i++){
		digit = (i % 2 == 0)? 1 : 0;
		for(j=0; j<s[i];j++){
			t[idx++] = digit;
		}
	}
	for(i=0; i<N; i++){
		result = (result << 1) + t[i]; 
	}
	return result;
}

void rFindTNum(struct structTNum *pre){
	struct structTNum *cur;
	short i;
	short nRemainingDigit;
	
	nRemainingDigit = K - pre->pos - 1; 
	if((pre->pos == K - 1) && (pre->quota == 0)){
		if(DEBUG){
			printf("find tweedle num:");
			for(i=0; i<K; i++){
				printf("%d",pre->tNum[i]);
			}
			printf("\n");
		}
		tNum[nTNum++] = str2tnum(pre->tNum);
		
		return ;
	}
	else if (pre->pos == K - 1){
		return ;
	}
	else if ((pre->pos < K - 1 ) && (pre->quota == 0)){
		return ;
	}
	else if ( M * nRemainingDigit < pre->quota ){
		
		return;
	}
	
	cur = (struct structTNum *) malloc(sizeof(struct structTNum));
	memcpy(cur, pre, sizeof(struct structTNum));
	cur->pos = pre->pos + 1;
	if(cur->pos % 2 == 0){
		for(i=1; (i <= M) && (pre->quota >= i); i++){		
			cur->tNum[cur->pos] = i;
			cur->quota = pre->quota - i;
			rFindTNum(cur);
		}
	}
	else {
		for(i=M; (i >= 1); i--){
			if(pre->quota >= i){
				cur->tNum[cur->pos] = i;
				cur->quota = pre->quota - i;
				rFindTNum(cur);
			}		
		}
	}
	free(cur);
}

void findTNum(){
	struct structTNum *base;
	short i;
	base = (struct structTNum *) malloc(sizeof(struct structTNum));
	memset(base, 0, sizeof(struct structTNum));
	base->pos = 0;
	
	for(i=1; i<=M; i++){
		base->tNum[0] = i;
		base->quota = N - i;
		rFindTNum(base);
	}
	free(base);
}

int main(){
	char bitSeq[MAX];
	char first = 1;
	int i, j;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	
	while(3 == fscanf(fp, "%hd %hd %hd",&N, &K, &M)){
		char match;
		long queryTarget;
		
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		nTNum = 0; 	
		findTNum();
		

		if(DEBUG){
			int j;
			for(i=0; i<nTNum; i++){
				printf("%ld\n",tNum[i]);
			}
			printf("\n");
			
		}	
		if(VERBOSE){
			printf("Find %d tweedle numbers\n",nTNum);
		}	
		
		fscanf(fp, "%hd",&nQuery);
		for(i=0; i<nQuery; i++){
			fscanf(fp, "%s",bitSeq);
			queryTarget = atoil(bitSeq);
			if(DEBUG){
				printf("query %s -> %ld\n",bitSeq, queryTarget);
			}
			printf("%d\n",queryByIndex(queryTarget));
		}		
	}
	return 0;
}