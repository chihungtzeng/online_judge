#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SRC_MAX 101
#define DEST_MAX 1001
#define INF DEST_MAX
#define DEBUG 1
#define TYPE short

void buildTable(TYPE **ans){
	int i, j, k, tmp;
	char bPrime[DEST_MAX];

	memset(bPrime, 1, DEST_MAX);	
	
	for(i=2; i<DEST_MAX;i++){
		if(bPrime[i]){
			for(j=i<<1; j<DEST_MAX; j+=i){
				bPrime[j] = 0;
			}
		}
	}
	bPrime[0] = 0;
	bPrime[1] = 0;

	for(i=2; i<SRC_MAX; i++){
		for(j=i+2; j < DEST_MAX; j++){
			if( (j != (i << 1)) && (bPrime[j-i])){
				ans[i][j] = 1;
			}
		}
	}	
	for(i=1; i<SRC_MAX; i++){
		for(j=1; j<DEST_MAX; j++){
			for(k=i+1; k<j; k++){
				tmp = ans[i][k] + ans[k][j]; 
				if(tmp < ans[i][j]){
					ans[i][j] = tmp; 
				}
			} 
		}
	}
	
}


int main(){
	int S, T, k = 1;
	FILE *fp;
	TYPE **ans;
	int i, j;

	ans = (TYPE **) malloc(sizeof(TYPE *) * SRC_MAX);
	for(i=0; i<SRC_MAX; i++){
		ans[i] = (TYPE *) malloc(sizeof(TYPE) * DEST_MAX);
		for(j=0; j<DEST_MAX; j++){
			ans[i][j] = INF;
		}
	}	
	buildTable(ans);
	
	fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
	
	
	while(2 == fscanf(fp, "%d %d", &S, &T)){
		if(!(S | T)){
			break;
		}
		printf("Case %d: %d\n", k++, (ans[S][T] >= INF)? -1 : ans[S][T]);
	}		
	
	for(i=0; i<SRC_MAX; i++){
		free(ans[i]);
	}
	free(ans);
	return 0;
}