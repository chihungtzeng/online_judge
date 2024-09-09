#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define VISITED 1
#define LEN 128
#define DEBUG 0

char land[LEN][LEN];

void solve(int nRow, int nCol, int r, int c){
	int area;
	int i, j;
	int head, tail;
	char visit[LEN][LEN];
	char x[LEN*LEN], y[LEN*LEN];
	int curX, curY, targetX, targetY;
	
	if(land[r][c] == 'L'){
		printf("0\n");
		return;
	}
	
	for(i=0; i<nRow; i++){
		memset(visit[i], 0, nCol);
	}

	head = 0;
	tail = 1;
	area = (land[r][c] == 'W')? 1 : 0;
	x[0] = r;
	y[0] = c;
	visit[r][c] = VISITED;

	while(head < tail) {
		curX = x[head];
		curY = y[head];
		head++;
		for(i=-1; i<=1; i++){
			for(j=-1; j<=1; j++){
				if( (i == 0) && (j == 0)){
					continue;
				}
				targetX = curX + i;
				if((targetX < 0) || (targetX >= nRow)){
					continue;
				}
				targetY = curY + j;
				if( (targetY < 0) || (targetY >= nCol)){
					continue;
				}
				if(land[targetX][targetY] != 'W'){
					continue;
				}
				
				if(visit[targetX][targetY] != VISITED){
					visit[targetX][targetY] = VISITED;
					area++;
					x[tail] = targetX;
					y[tail] = targetY;
					tail++;
				}
			}
		}
	} 
	
	printf("%d\n", area);

}

int main(){
	
	char line[LEN];
	int nTest;
	int r, c, nRow, nCol;
	char first = 1;
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt", "r"):stdin;
	fgets(line, LEN, fp);
	nTest = atoi(line);
	/*empty line*/
	fgets(line, LEN, fp);
	
	while(nTest--){		
		nRow = 0;
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		
		while( (NULL != fgets(line, LEN, fp)) && (isalpha(line[0]))){
			strcpy(land[nRow], line);
			nRow++;
		}
		#if 0
		for(r=0; r<nRow; r++){
			printf("%s", land[r]);
		}
		#endif
		nCol = strlen(land[0]) - 1; /* -1 is for not counting '\n'*/
		do {
			sscanf(line, "%d %d", &r, &c);
			solve(nRow, nCol, r - 1, c - 1);
		}while((NULL != fgets(line, LEN, fp)) && (isdigit(line[0])));
	}
	
	return 0;
}