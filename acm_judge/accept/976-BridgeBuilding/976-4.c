/*AC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define MAXINT 1000000000
#define FAIL -1
#define SHIFT 10
#define VERBOSE 0
#define DEBUG 0


struct point{
	short row, col;
};


short R, C;
char map[MAX][MAX];
short nBridge, sep;
short dist[MAX];



void buildDistArray(){
	short count, row, col, done;
	memset(dist, 0, C);
	for(col=0; col<C; col++){
		count = 0;
		done = 0;
		for(row=1; (row < R) && (!done); row++){
			if(map[row][col] == '.'){
				count++;
			}
			else if (map[row][col] == 'U'){
				count = 0;
			}
			else if (map[row][col] == '#'){
				dist[col] = count;
				done = 1;
			}
		}
	}
}

void refineMap(){
	short i, j ;
	struct point queue[1<<20];
	int head, tail;
	int r, c, src, target;

	
	memset(map[0], 'U', C);
	
	for(i=0; i<C; i++){
		queue[i].row = 0;
		queue[i].col = i;
	}
	
	head = 0;
	tail = C;
	
	/*discover the up/down land*/
	while(head < tail){
		int nr, nc;
		
		r = queue[head].row;
		c = queue[head].col;
		head++;
		nr = r + 1;
		nc = c;
		
		if((nr < R) && (map[nr][nc] == '#')){
			map[nr][nc] = map[r][c];
			queue[tail].row = nr;
			queue[tail].col = nc;
			tail++;
		}
		nr = r;
		nc = c + 1;
		if((nc < C) && (map[nr][nc] == '#')){
			map[nr][nc] = map[r][c];
			queue[tail].row = nr;
			queue[tail].col = nc;
			tail++;
		}
		nr = r - 1;
		nc = c;
		if((nr >= 0) && (map[nr][nc] == '#')){
			map[nr][nc] = map[r][c];
			queue[tail].row = nr;
			queue[tail].col = nc;
			tail++;
		}
		nr = r;
		nc = c - 1;
		if((nc >=0) && (map[nr][nc] == '#')){
			map[nr][nc] = map[r][c];
			queue[tail].row = nr;
			queue[tail].col = nc;
			tail++;
		}
	}	
}


int findAns(){
	int i, j;
	int row, col, min, start, end;
	int table[nBridge][C];

	min = MAXINT;
	for(col = 0; col < C; col++){
		if(dist[col] < min){
			min = dist[col];
		}
		table[0][col] = min;
	}

	for(row=1; row	< nBridge; row++){
		min = MAXINT;
		for(col=0; col < C; col++){
			/*find the minimum in range [0..end]*/
			end = col - sep - 1;
			if((end >= 0) && (table[row-1][end] < min)){ 
				min = table[row-1][end];
			}
			if(min == MAXINT){
				table[row][col] = MAXINT;
			}
			else{
				table[row][col] = min + dist[col];
			}
		}
	}
	
	if(VERBOSE){
		for(row=0; row < nBridge; row++){
			for(col=0; col < C; col++){
				printf("%d ", table[row][col]);
			}
			printf("\n");
		}
	}
	
	min = MAXINT;
	row = nBridge - 1;
	for(i=0; i<C; i++){
		if(table[row][i] < min){
			min = table[row][i];
		}
	}
	
	return min;
}

int main(){
	int min;
	FILE *fp;

	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	
	while(2 == fscanf(fp, "%hd %hd",&R, &C)){
		short i,j;
		
		fscanf(fp, "%hd %hd", &nBridge, &sep);
		for(i=0; i < R; i++){
			fscanf(fp, "%s", map[i]);
		}
		refineMap();
		if(VERBOSE){
			short j;
			for(i=0; i<R; i++){
				for(j=0; j<C; j++){
					
					printf("%c", map[i][j]);
					
				}
				printf("\n");
			}
			printf("\n");
		}
		buildDistArray();
		min = findAns();
		printf("%d\n", min);
		
	}
	return 0;	
}

