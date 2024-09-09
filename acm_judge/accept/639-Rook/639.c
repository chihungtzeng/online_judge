#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 5
#define EMPTY ' '
#define ROOK 'R'
#define WALL 'X'
#define MAX 16
#define DEBUG 0

char n = 0;
char stop;

char nextPos(char grid[LEN][LEN], char cur){
	char next = cur;
	char r = cur / n, c = cur % n;
	while((grid[r][c] != '.') && (next < stop)){
		next++;
		r = next / n;
		c = next % n;
	} 
	return next;
}

int isSafe(char grid[LEN][LEN], char pos){
	/*check if able to place a rook at pos */
	char i, j, r, c;
	r = pos / n;
	c = pos % n;
	for(i=c+1; i < n; i++){
		if(grid[r][i] == ROOK) return EXIT_FAILURE;
		else if (grid[r][i] == WALL) break;
	}
	for(i=c-1; i >=0; i--){
		if(grid[r][i] == ROOK) return EXIT_FAILURE;
		else if (grid[r][i] == WALL) break;
	}
	for(i=r+1; i<n; i++){
		if(grid[i][c] == ROOK) return EXIT_FAILURE;
		else if (grid[i][c] == WALL) break;
	}
	for(i=r-1; i >=0; i--){
		if(grid[i][c] == ROOK) return EXIT_FAILURE;
		else if (grid[i][c] == WALL) break;
	}
	return EXIT_SUCCESS;
}

char solve(char grid[LEN][LEN], char pos){
	char i, j, r, c;
	char ans[2];
	char copy[LEN][LEN];
	
	if(pos == stop){
		char count = 0;
		for(i=0; i<n; i++){
			for(j=0; j < n; j++){
				if(grid[i][j] == ROOK) count++; 
			}
		}
		return count;
	}
	r = pos / n;
	c = pos % n;
	
	if(grid[r][c] == '.'){
		if(isSafe(grid, pos) == EXIT_SUCCESS){
			memcpy(copy, grid, 25);
			copy[r][c] = ROOK;
			ans[0] = solve(copy, nextPos(copy, pos));
			
			memcpy(copy, grid, 25);
			copy[r][c] = EMPTY;
			ans[1] = solve(copy, nextPos(copy, pos));
			return (ans[0] > ans[1])? ans[0] : ans[1]; 
		} 
		else{
			memcpy(copy, grid, 25);
			copy[r][c] = EMPTY;
			return solve(copy, nextPos(copy, pos));
		}
	}
	else{
		return solve(grid, nextPos(grid, pos)); 
	}
}

int main(){
	char i;
	char grid[LEN][LEN];
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	while(1 == fscanf(fp, "%hhd", &n)){
		if(0 == n) return 0;
		stop = n*n;
		for(i=0; i<n; i++){
			fscanf(fp, "%s", grid[i]);
			if(DEBUG){
				puts(grid[i]);
			}
		}
		printf("%hhd\n", solve(grid, 0));
	}
	return 0;
}