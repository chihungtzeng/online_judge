#include <stdio.h>
#include <stdlib.h>
#define HOLE_NUM 2500
#define ROW_NUM 50
#define VISITED '*'
#define GET_ROW(pos) ((pos) >> 8)
#define GET_COL(pos) ((pos) & 0xff)
#define CONVERT_TO_POS(row, col) (((row) << 8) | (col))
#define DEBUG 0

struct Hole {
	short nCell;
	char id;
};

char map[ROW_NUM][ROW_NUM];

int compareHole(const void *a, const void *b){
	struct Hole *x, *y;
	x = (struct Hole *)a;
	y = (struct Hole *)b;
	if(x->nCell != y->nCell) return x->nCell - y->nCell;
	else return y->id - x->id;
}

int validRange(int r, int range){
/*return true if 0 <= r < range*/
	if((r >= 0) && (r < range)) return 1;
	else return 0;
}

int validRowCol(int r, int c, int nRow, int nCol){
	return validRange(r, nRow) && validRange(c, nCol);
}

int BFS(char map[ROW_NUM][ROW_NUM], int nRow, int nCol, int r, int c){
	int nVisit = 0;
	char targetId;
	int cur, curr, curc, nextc, nextr;
	int queue[2500];
	int head=0, tail=1;
	int i, j;
	queue[0] = CONVERT_TO_POS(r, c);
	targetId = map[r][c];
	map[r][c] = VISITED;
	while(head < tail){
		cur = queue[head++];
		curr = GET_ROW(cur);
		curc = GET_COL(cur);
		nVisit++;
		#if DEBUG
		printf("(%d %d) has %c\n", curr, curc, targetId);
		#endif
		for(i=-1; i<=1; i++){
			for(j=-1; j<=1; j++){
				if(abs(i) + abs(j) == 1){
					nextr = curr + i;
					nextc = curc + j;
					if(validRowCol(nextr, nextc, nRow, nCol) && (map[nextr][nextc] == targetId)){
						queue[tail++] = CONVERT_TO_POS(nextr, nextc);
						map[nextr][nextc] = VISITED; 
					}
				}
			}
		}
	}
	return nVisit;
}

int solve(char map[ROW_NUM][ROW_NUM], struct Hole *hold, int nRow, int nCol){
	int nHole = 0;
	int i, j;
	for(i=0; i<nRow; i++){
		for(j=0; j<nCol; j++){
			if(isalpha(map[i][j])){
				hold[nHole].id = map[i][j];
				hold[nHole].nCell = BFS(map, nRow, nCol, i, j);
				nHole++;
			}
		}
	}
	return nHole;
}

int main(){
	struct Hole *hole;
	int nHole;
	int nRow, nCol;
	int i, k=1;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	hole = (struct Hole *) malloc(sizeof(struct Hole)*HOLE_NUM);
	while(2 == fscanf(fp, "%d %d", &nRow, &nCol)){
		if((0==nRow) && (0==nCol)) { break;}
		for(i=0; i<nRow; i++){
			fscanf(fp, "%s", map[i]);
		}
		nHole = solve(map, hole, nRow, nCol);
		qsort(hole, nHole, sizeof(struct Hole), compareHole);
		printf("Problem %d:\n", k++);
		for(i=nHole - 1; i>=0; i--){
			printf("%c %hd\n", hole[i].id, hole[i].nCell);
		}
	}
	
	free(hole);
	return 0;
}


