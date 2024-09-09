#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1025

int grid[MAX][MAX];
int radius;

int effect(short r, short c){
/*place a bomb at (r, c)*/
	int ans = 0;
	short ulr, ulc, lrr, lrc;
	ulr = (r - radius > 0)? r - radius : 0;
	ulc = (c - radius > 0)? c - radius : 0;
	lrr = (r + radius < MAX)? r + radius : 1024;
	lrc = (c + radius < MAX)? c + radius : 1024;
	if(ulr == 0){
		if (ulc == 0){
			return grid[lrr][lrc];
		}
		else{
			return grid[lrr][lrc] - grid[lrr][ulc - 1];
		}
	} 
	else {
		if(ulc == 0){
			return grid[lrr][lrc] - grid[ulr - 1][lrc];
		}
		else{
			return grid[lrr][lrc] - grid[ulr - 1][lrc] - grid[lrr][ulc - 1] + grid[ulr - 1][ulc - 1];
		}
	}
}

void solve(){
	short i, j, r, c;
	int best = 0;
	int rBest = -1, cBest = -1;
	int amount;
	for(i=1; i<MAX; i++){
		grid[0][i] += grid[0][i-1];
		grid[i][0] += grid[i-1][0];
	}
	for(i=1; i<MAX; i++){
		for(j=1; j<MAX; j++){
			grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]; 
		}
	}
	for(r=0; r<MAX; r++){
		for(c=0; c<MAX; c++){
			amount = effect(r, c);
			if(amount > best){
				best = amount;
				rBest = r;
				cBest = c;
			}
		}
	} 
	printf("%hd %hd %d\n", rBest, cBest, best);
}

int main(){
	char nTest;
	short nPos, i, r, c, amount;
	FILE *fp = stdin;
	fscanf(fp, "%hhd", &nTest);
	
	while(nTest >= 1){
		nTest--;
		memset(grid, 0, sizeof(int)*MAX*MAX);
		fscanf(fp, "%d %hd", &radius, &nPos);
		for(i=0; i<nPos; i++){
			fscanf(fp, "%hd %hd %hd", &r, &c, &amount);
			grid[r][c] = amount;
		}
		solve();
	}
	return 0;
}