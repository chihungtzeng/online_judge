#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define LEN 1000
#define BLOCK 1
#define DEBUG 0

char map[MAX][MAX];
long long nPath[MAX][MAX];
short W, N;

long long findAns(){
	short x, y;
	memset(nPath, 0, sizeof(long long)*MAX*MAX);
	if(map[1][1] == BLOCK) return 0;
	
	nPath[1][1] = 1;
	for(y=2; y<=W; y++){
		nPath[y][1] = (map[y][1] == BLOCK)? 0 : nPath[y - 1][1];
	}
	for(x=2; x<=N; x++){
		nPath[1][x] = (map[1][x] == BLOCK)? 0 : nPath[1][x - 1];
	}
	for(y = 2; y <= W; y++){
		for(x = 2; x<=N; x++){
			if(map[y][x] != BLOCK){
				nPath[y][x] = nPath[y-1][x] + nPath[y][x-1];
			}
			else{
				nPath[y][x] = 0;
			}
		}
	}

	if(DEBUG){
		for(y=1; y<=W; y++){
			for(x=1; x<=N; x++){
				printf("%lld ",nPath[y][x]);
			}
			printf("\n");
		}
	}	
	
	return nPath[W][N];
}


int main(){
	short nTest, i, j;
	char firstCase = 1;	
	char line[LEN], *tok;
	long long ans;	

	fgets(line, LEN, stdin);
	nTest = atoi(line);	
	while(nTest >= 1){
		nTest--;
		memset(map, 0, sizeof(char)*MAX*MAX);
		fgets(line, LEN, stdin);
		fgets(line, LEN, stdin);
		W = atoi(strtok(line, " \n"));
		N = atoi(strtok(NULL, " \n"));
		for(i=1; i <= W; i++){
			fgets(line, LEN, stdin);
			tok = strtok(line, " \n");
			tok = strtok(NULL, " \n");
			while(tok != NULL){
				j = atoi(tok);
				map[i][j] = BLOCK;
				tok = strtok(NULL, " \n");
			}
		}

		if(DEBUG){
			for(i=1; i<=W; i++){
				for(j = 1; j<=N; j++){
					printf("%hhd ", map[i][j]);
				}
				printf("\n");
			}
		}		
		
		ans = findAns();
		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}