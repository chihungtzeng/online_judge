#include <stdio.h>
#include <stdlib.h>
#define LEN 12

char grid[LEN][LEN];
char n;

char decide(char row, char col){
	char i, j, nForbidden = 0;
	char nr, nc;
	char fobidden[4], conflict;
	for(i=-1; i<=1; i++){
		for(j=-1; j<=1; j++){
			if( abs(i) + abs(j) != 1) continue;
			nr = row + i;
			nc = col + j;
			if((nr < 0) || (nr >= n)) continue;
			if((nc < 0) || (nc >= n)) continue;
			
			if(grid[nr][nc] != '.'){
				fobidden[nForbidden++] = grid[nr][nc];
			}
		}
	}
	for(i = 'A'; i <= 'Z'; i++){
		conflict = 0;
		for(j=0; j<nForbidden; j++){
			if(i == fobidden[j]) conflict = 1;
		}
		if(!conflict) return i;
	}
}

void solve(){
	char i, j;	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(grid[i][j] == '.') {
				grid[i][j] = decide(i, j);
			}
		}
	}
}

int main(){
	short nTest, k = 1;
	FILE *fp = stdin;
	char line[LEN];
	char i, j;
	
	fgets(line, LEN, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, LEN, fp);
		n = atoi(line);
		for(i=0; i<n; i++){
			fgets(grid[i], LEN, fp);
		}
		solve();
		printf("Case %hd:\n", k++);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}