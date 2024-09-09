#include <stdio.h>
#define MAX 101
#define INF 0x0fffffff
#define DEBUG 0

void printMaze(int n, int maze[MAX][MAX]){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

int Warshall(int n, int maze[MAX][MAX], int exit, int timeout){
	int i, j, k;
	int  tmp, result = 0;;
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				tmp = maze[i][k] + maze[k][j];
				if(tmp < maze[i][j]){
					maze[i][j] = tmp;
				}
			}
		}
	}
	#if 0
	printMaze(n, maze);
	#endif
	for(i=1; i<=n; i++){
		if(maze[i][exit] <= timeout){
			result++;
		}
	}
	return result;
}

int main(){
	int nTest;
	int n, row, col, cost;
	int nEdge;
	int exit, timeout;
	int first = 1;
	int maze[MAX][MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r"):stdin;
	fscanf(fp, "%d", &nTest);
	while(nTest--){
		
		
		fscanf(fp, "%d %d %d %d", &n, &exit, &timeout, &nEdge);
		for(row = 1; row <= n; row++){
			for(col = 1; col <= n; col++){
				maze[row][col] = (row == col)? 0 : INF;
			}
		}
		while(nEdge--){
			fscanf(fp, "%d %d %d", &row, &col, &cost);
			maze[row][col] = cost;
		}
		#if 0
		printMaze(n, maze);
		printf("INF=%d\n", INF);
		printf("\n");
		
		#endif
		if(first){
			first = 0;
		} else {
			printf("\n");
		}
		printf("%d\n", Warshall(n, maze, exit, timeout));
	}
	
	return 0;
}