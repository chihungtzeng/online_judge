#include <stdio.h>
#include <string.h>
#define MAX 127
#define DEBUG 0

char map[MAX][MAX];
short nRow, nCol;

short solve(){
	short nDeposit = 0;
	char queueX[nRow*nCol];
	char queueY[nRow*nCol];
	short head, tail, src, target, i, j;
	char row, col, rinc, cinc, r,c;
	for(i=0; i<nRow; i++){
		for(j=0; j<nCol; j++){
			if(map[i][j] == '@'){
				/*mark the oil deposits*/
				map[i][j] = 'X';
				nDeposit++;
				queueX[0] = i;
				queueY[0] = j;
				head = 0;
				tail = 1;
				while(head < tail){
					
					row = queueX[head];
					col = queueY[head];
					head++;
					for(rinc = -1; rinc <= 1; rinc++){
						for(cinc = -1; cinc <= 1; cinc++){
							r = row + rinc;
							c = col + cinc;
							if( (r >= 0) && (r < nRow) && (c >= 0) && (c < nCol) && (map[r][c] == '@')){
								map[r][c] = 'X';
								queueX[tail] = r;
								queueY[tail] = c;
								tail++;
							}
						}
					}
				}
			}
		}
	}	
	return nDeposit;
}


int main(){
	short i, j, ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in5.txt","r") : stdin;
	while(2 == fscanf(fp, "%hd %hd", &nRow, &nCol)){
		if(0 == nRow) break;
		memset(map,0, MAX*MAX);
		for(i=0; i<nRow; i++){
			fscanf(fp,"%s", map[i]);
		}
		if(DEBUG){
			for(i=0; i<nRow; i++){
				for(j=0; j<nCol; j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
		}
		/*ans = solve();*/
		printf("%hd\n",solve());
		if(DEBUG){
			printf("--------after-------------\n");
			for(i=0; i<nRow; i++){
				for(j=0; j<nCol; j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}
