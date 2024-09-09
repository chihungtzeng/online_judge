#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105
#define DEBUG 0
#define LEN 1024

int hasNeighbor(int row, int col, int n, char map[N][N]){
	char target = map[row][col];
	if( (target == map[row][col+1]) || (target == map[row][col-1]) 
		|| (target == map[row+1][col]) || (target == map[row-1][col])
		)
		return 1;
	else return 0; 
}

void solve(int n, char map[N][N], char nCount[N]){
	int i, j;
	char target;

	for(i=0; i<n; i++){
		if(nCount[i] != n){
			#if 0
			printf("initial checking: nCount[%d] = %d, n=%d\n", i, nCount[i], n);
			#endif
			puts("wrong");
			return ;
		}
	}
	
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			target = map[i][j];
			if(hasNeighbor(i, j, n, map)){
				nCount[target] -= 1;
			}
		}
	}

	for(i=0; i<n; i++){
		if(nCount[i] != 0){
			
			#if 0
			printf("nCount[%d] = %d\n", i, nCount[i]);
			#endif
			puts("wrong");
			return ;
		}
	}	
	puts("good");	
	
	return ;
}

int main(){
	char map[N][N];
	char nCount[N];
	int n, row, col, i, j;
	int nTest;
	FILE *fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	char line[LEN];
	char *tok;
	
	
	while(NULL != fgets(line, LEN, fp)){
		n = atoi(line);
		if(n <= 0) break;
		
		for(i=0; i<=n; i++){
			memset(map[i], 0, N);
		}
		memset(nCount, 0, N);
		
		for(i = n - 1; i > 0; i--){
			fgets(line, LEN, fp);
			tok = strtok(line, " \n");
			if(tok == NULL) continue;
			
			do {
				row = atoi(tok);
				tok = strtok(NULL, " \n");
				col = atoi(tok);
				if(map[row][col] == 0){
					map[row][col] = i;
					nCount[i] += 1;
				}
				tok = strtok(NULL, " \n");
			} while(tok != NULL);
		}
		nCount[0] = n * n;
		for(i = n - 1; i > 0; i--){
			nCount[0] -= nCount[i];
		}
		j = n + 1;
		for(i = 0; i <= j; i++){
			map[i][0] = -1;
			map[i][j] = -1;
			map[j][i] = -1;
			map[0][i] = -1;
		}
		
		#if 0
		for(row = 0; row <= n + 1; row++){
			for(col = 0; col <= n + 1; col++){
				printf("%3hhd ", map[row][col]);
			}
			printf("\n");
		}
		printf("-------\n");
		#endif
		if(n == 1){
			puts("good");
		} else {
			solve(n, map, nCount);
		}
	}

	
	return 0;
}


