/*AC*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UNKNOWN '?'
#define COOKIE 'X'
#define NONE '.'
#define MAX 11
#define DEBUG 0
#define VERBOSE 0
#define DONE 1
#define NOT_DONE 0
#define VALID 1
#define INVALID 0

struct point{
	int row, col;
};

short R, C;
short row[MAX], col[MAX], diag[MAX << 1];
char rowFlag[MAX], colFlag[MAX], diagFlag[MAX << 1];
char solution[MAX][MAX];

struct point diagPos[MAX << 1][MAX << 1];
short nDiagPos[MAX << 1];

void printSolution(char cookie[MAX][MAX]){
	short r, c;
	for(r=0; r<R; r++){
		for(c = 0; c<C; c++){
			printf("%c",cookie[r][c]);
		}
		printf("\n");
	}
}

int getNextUnknown(char cookie[MAX][MAX], short *r, short *c){
	short i, j;
	*r = -1;
	*c = -1;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(cookie[i][j] == UNKNOWN){
				*r = i;
				*c = j;
				return 1;
			}
		}
	} 
	return 0;
}

void decideDiagPos(){
	short i, j, d;
	for(d=0; d<R+C - 1; d++){
		nDiagPos[d] = 0;
	}
		
	for(i=0; i < R; i++){
		for(j=0; j<C; j++){
			d = R - i - 1 + j;
			diagPos[d][nDiagPos[d]].row = i;
			diagPos[d][nDiagPos[d]].col = j;
			nDiagPos[d] += 1;
		}
	}	
}

int greedyStepForRow(char cookie[MAX][MAX], short r){
	short c;
	short nUnknown = 0, nCookie = 0;

	if(rowFlag[r] == DONE) return EXIT_FAILURE;
	if(VERBOSE){
		printf("greedy step for row %d\n",r);
	}	
	
	
	for(c = 0; c<C; c++){
		if(cookie[r][c] == UNKNOWN) nUnknown += 1;
		else if (cookie[r][c] == COOKIE) nCookie += 1;
	}
	
	if(nUnknown == 0){
		return EXIT_FAILURE;
	}
	else if(nUnknown == row[r] - nCookie){
		/*assign a cookie to those unknown cells*/
		for(c=0; c<C; c++){
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = COOKIE;
			}
		}
		rowFlag[r] = DONE;
		return EXIT_SUCCESS;
	}
	else if (0 == row[r] - nCookie){
		for(c=0; c<C; c++){
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = NONE;
			}
		}
		rowFlag[r] = DONE;
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}
}

int greedyStepForCol(char cookie[MAX][MAX], short c){
	short r;
	short nUnknown = 0, nCookie = 0;

	if(colFlag[c] == DONE) return EXIT_FAILURE;
	if(VERBOSE){
		printf("greedy step for col %d\n",c);
	}		
	
	for(r = 0; r < R; r++){
		if(cookie[r][c] == UNKNOWN) nUnknown += 1;
		else if (cookie[r][c] == COOKIE) nCookie += 1;
	}
	if(nUnknown == 0){
		return EXIT_FAILURE;
	}
	else if(nUnknown == col[c] - nCookie){
		/*assign a cookie to those unknown cells*/
		for(r=0; r<R; r++){
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = COOKIE;
			}
		}
		colFlag[c] = DONE;
		return EXIT_SUCCESS;
	}
	else if (0 == col[c] - nCookie){
		for(r=0; r<R; r++){
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = NONE;
			}
		}
		colFlag[c] = DONE;
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}
}

int greedyStepForDiagonal(char cookie[MAX][MAX], short d){
	short i, r, c;
	short nUnknown = 0, nCookie = 0;
	
	if(diagFlag[d] == DONE) return EXIT_FAILURE;
	if(VERBOSE){
		printf("greedy step for diagonal %d\n",d);
	}	
			
	for(i = 0; i < nDiagPos[d]; i++){
		r = diagPos[d][i].row;
		c = diagPos[d][i].col;
		if(cookie[r][c] == UNKNOWN) nUnknown += 1;
		else if (cookie[r][c] == COOKIE) nCookie += 1;
	}
	if(nUnknown == 0){
		return EXIT_FAILURE;
	}
	else if(nUnknown == diag[d] - nCookie){
		/*assign a cookie to those unknown cells*/
		for(i=0; i < nDiagPos[d]; i++){
			r = diagPos[d][i].row;
			c = diagPos[d][i].col;
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = COOKIE;
			}
		}
		diagFlag[d] = DONE;
		return EXIT_SUCCESS;
	}
	else if (0 == diag[d] - nCookie){
		for(i=0; i < nDiagPos[d]; i++){
			r = diagPos[d][i].row;
			c = diagPos[d][i].col;
			if(cookie[r][c] == UNKNOWN){
				cookie[r][c] = NONE;
			}
		}
		diagFlag[d] = DONE;
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}
}

int greedyStep(char cookie[MAX][MAX]){
	short i;
	short state;
	char done = 0;
	
	while(!done){
		done = 1;
		for(i=0; i<R; i++){
			state = greedyStepForRow(cookie, i);
			if(state == EXIT_SUCCESS) done = 0;
		}
		for(i=0; i<C; i++){
			state = greedyStepForCol(cookie, i);
			if(state == EXIT_SUCCESS) done = 0;
		}
		for(i=1; i<R+C-2; i++){
			state = greedyStepForDiagonal(cookie, i);
			if(state == EXIT_SUCCESS) done = 0;
		}
	}
	
}

int checkValid(char cookie[MAX][MAX]){
	short r, c, d, i;
	short tmpCol[MAX], tmpRow[MAX];
	short count;
	memset(tmpRow, 0, sizeof(short)*MAX);
	memset(tmpCol, 0, sizeof(short)*MAX);
	
	for(r =0; r < R; r++){
		for(c=0; c<C; c++){
			if(cookie[r][c] == COOKIE){
				tmpRow[r] += 1;
				tmpCol[c] += 1;
			}
			else if(cookie[r][c] == UNKNOWN){
				return INVALID;
			}
		} 
	}
	for(r = 0; r < R; r++){
		if(tmpRow[r] != row[r]) return INVALID; 
	}
	for(c = 0; c < C; c++){
		if(tmpCol[c] != col[c]) return INVALID;
	}
	for(d = 0; d<R+C-1; d++){
		count = 0;
		for(i = 0; i<nDiagPos[d]; i++){
			r = diagPos[d][i].row;
			c = diagPos[d][i].col;
			if(cookie[r][c] == COOKIE) {
				count++;
			}
		}
		if(count != diag[d]) return INVALID;
	}
	return VALID;
}

int findSolution(char cookie[MAX][MAX]){
	short r, c , d;
	char cookieCopy[MAX][MAX];
	char rowFlagCopy[MAX], colFlagCopy[MAX], diagFlagCopy[2*MAX];
	int nAns1, nAns2;	
	char hasUnknown;

	
	greedyStep(cookie);
	hasUnknown = getNextUnknown(cookie, &r, &c);
	
	if(!hasUnknown){
		if(checkValid(cookie) == VALID){
			if(DEBUG){
				printf("found a solution\n");
				printSolution(cookie);
				printf("******************\n");
			}
			memcpy(solution, cookie, sizeof(char)*MAX*MAX);
			return 1;
		}
		else return 0;
	}
	
	
	
	
	memcpy(cookieCopy, cookie, sizeof(char)*MAX*MAX);
	memcpy(rowFlagCopy, rowFlag, sizeof(char)*MAX);
	memcpy(colFlagCopy, colFlag, sizeof(char)*MAX);
	memcpy(diagFlagCopy, diagFlag, sizeof(char)*MAX*2);	
	
	cookie[r][c] = NONE;
	nAns1 = findSolution(cookie);
	
	memcpy(cookie, cookieCopy, sizeof(char)*MAX*MAX);
	memcpy(rowFlag, rowFlagCopy, sizeof(char)*MAX);
	memcpy(colFlag, colFlagCopy, sizeof(char)*MAX);
	memcpy(diagFlag, diagFlagCopy, sizeof(char)*MAX*2);
	cookie[r][c] = COOKIE;
	nAns2 = findSolution(cookie);
	
	return nAns1 + nAns2;
}


int main(){
	int nAns;
	int ans;
	short i, j;
	FILE *fp;
	char cookie[MAX][MAX];
	char first = 1;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;	
	
	while(2 == fscanf(fp, "%hd %hd", &R, &C)){
		memset(cookie, UNKNOWN, sizeof(char)*MAX*MAX);
		memset(rowFlag, NOT_DONE, sizeof(char)*MAX);
		memset(colFlag, NOT_DONE, sizeof(char)*MAX);
		memset(diagFlag, NOT_DONE, sizeof(char)*MAX*2);
		
		for(i=0; i<R; i++){
			fscanf(fp, "%hd", &row[i]);
		}
		for(i=0; i<C; i++){
			fscanf(fp,"%hd", &col[i]);
		}
		for(i=0; i < R + C - 1; i++){
			fscanf(fp,"%hd", &diag[i]);
		}
		
		decideDiagPos();
		if(DEBUG){
			int d;
			printf("R=%hd C=%hd\n",R,C);
			for(d=0; d<R+C-1; d++){
				printf("diag %d:\n", d);
				for(i=0; i<nDiagPos[d]; i++){
					printf("(%d %d) ", diagPos[d][i].row, diagPos[d][i].col);
				}
				printf("\n");
			} 
		}
		/*fill out trivial positions*/
		for(i=0; i<R; i++){
			if(row[i] == 0){
				for(j=0; j<C; j++){
					cookie[i][j] = NONE;
				}
				rowFlag[i] = DONE;
			}
		}		
		for(i=0; i<C; i++){
			if(col[i] == 0){
				for(j=0; j<R; j++){
					cookie[j][i] = NONE;
				}
				colFlag[i] = DONE;
			}
		}
		cookie[R-1][0] = (diag[0] == 0)? NONE : COOKIE;
		diagFlag[0] = DONE;
		cookie[0][C-1] = (diag[R+C-2] == 0)? NONE : COOKIE;
		diagFlag[R+C-2] = DONE;
		for(i=1; i<R+C-2; i++){
			if(diag[i] == 0){
				for(j=0; j<nDiagPos[i]; j++){
					cookie[diagPos[i][j].row][diagPos[i][j].col] = NONE;
				}
				diagFlag[i] = DONE;
			}
		}
		
		
		nAns = findSolution(cookie);
		
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		if(nAns == 1){
			printSolution(solution);
		}
		else{
			printf("%d\n",nAns);
		}
		
	}
	return 0;
}