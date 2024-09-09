#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64
#define DEBUG 0
#define VERBOSE 0

short N, K, M;
short nQuery;
int nTNum;
long table[MAX][MAX];


long queryRank(char *target){
	long sum = 0;
	short i, j, row, col, pos;
	short quota;
	
	quota = N;
	for(pos = 0; pos < K-1; pos++){
		if(pos % 2 == 0){
			for(i=1; i < target[pos]; i++){
				sum += table[K - pos - 1][quota - i]; 
			}
		}
		else{
			for(i = M; i > target[pos]; i--){
				sum += table[K - pos - 1][quota - i];
			}
		}
		quota = quota - target[pos];
	} 
	
	
	return sum + 1;
}

void fillTable(){
	short i, j, row, col, done, preRow, targetCol;
	for(i=1; i<=M; i++){
		table[1][i] = 1;
	}
	for(row = 2; row < K; row++){
		table[row][row] = 1;
		preRow = row - 1;
		for(col = row + 1; col <= N; col++){
			done = 0;
			for(i=1; (i<=M) && (!done); i++){
				targetCol = col - i;
				if(targetCol < 1){
					done = 1;
					continue;
				}
				table[row][col] += table[preRow][targetCol];
			}
		}
	}
	if(DEBUG){
		printf("dump table:\n");
		for(row = 1; row < K; row++){
			for(col = 1; col <= N; col++){
				printf("%ld ",table[row][col]);
			}
			printf("\n");
			
		}
	}
}

void convertToNum(char *src, char *target){
	short i, j;
	char c = '0';
	j = 0;
	memset(target, 0, MAX);
	for(i=0; i<K; i++){
		c = '1' + '0' - c;
		while((j < N) && (src[j] == c)){
			target[i] += 1;
			j++;
		}
	}
	target[K] = '\0';
}


int main(){
	char bitSeq[MAX];
	char target[MAX];
	char first = 1;
	long rank;
	int i, j;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	
	while(3 == fscanf(fp, "%hd %hd %hd",&N, &K, &M)){
		memset(table, 0, sizeof(long)*MAX*MAX);
		fillTable();
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		fscanf(fp, "%hd",&nQuery);
		for(i=0; i<nQuery; i++){
			fscanf(fp, "%s",bitSeq);
			convertToNum(bitSeq, target);
			if(DEBUG){
				printf("query %s -> ",bitSeq);
				for(j=0; j<K; j++){
					printf("%d, ", target[j]);
				}
				printf("\n");
			}
			rank = queryRank(target);
			printf("%ld\n", rank);
		}		
	}
	return 0;
}