#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUCK -1
#define FAIL -1
#define UNFILLED -2
#define DEAD -4
#define UNSOLVABLE -8
#define PROGRESS 1
#define SUCCESS 2
#define FILLED 4


#define DEBUG 0

void printSudoku();
void genConflictCell(short);
int compareShort();
void initConflict();
int tryAns(short *cell);
int check(short *cell);

short nSize, nRow, nCell;
short nConflict[4] = {0, 0, 7, 20};
short conflict[81][20]; 


int main(int argc, char *argv[]) {
   short i, j, preSize=10;
   short *sudoku;
   int state, first;
   FILE *fp;
   

   if(DEBUG){	
   	/*fp = fopen("in.txt","r");*/  
		fp = fopen("in5.txt","r");
   }
   else{ 	fp = stdin;   }
   
   first = 1;
   while( 1 == fscanf(fp, "%hd",&nSize)){
   	if(!first){
   		printf("\n");
   	}   	
   	else{
   		first = 0;
   	}
   	nRow = nSize * nSize;
   	nCell = nRow * nRow;
   	sudoku = (short *) malloc(sizeof(short)*nCell);

   	for(i=0;i< nCell; i++){
	   	fscanf(fp, "%hd", &sudoku[i] );
   	}
   	
   	if(nSize != preSize){
   		initConflict();
   		preSize = nSize;
   	}
   	/*
		for(i=0;i<nConflict[nSize];i++){
			printf("%d ",conflict[9][i]);
		} */  	
   	
   	state = findAns(sudoku);
   	
   	if(state == SUCCESS){
   		printSudoku(sudoku);
   	}
   	else {
   		printf("NO SOLUTION\n");
   	}
	  free(sudoku);
   }
	return 0;
}

void initConflict(){
	short i;
	for(i=0;i<nCell;i++){
		genConflictCell(i);
	}
}

void genConflictCell(short n){
	short rgrid, cgrid;
	short rpos, cpos;
	short i,j, k;
	short conflictCellPos[27];
	short start;
	

	rpos = n / nRow;
	cpos = n  % nRow;
	rgrid = rpos / nSize;
	cgrid = cpos / nSize;
	j=0;
	start = rpos * nRow;
	for(i=0;i<nRow;i++){
		conflictCellPos[j++] = start + i;
	}
	start = cpos;
	for(i=0;i<nRow;i++){
		conflictCellPos[j++] = start;
		start += nRow;
	}
	start = (rgrid*nSize)*nRow + cgrid*nSize;
	for(i=0;i<nSize;i++){
		for(k=0;k <nSize; k++){
			conflictCellPos[j++] = start + k;
		}
		start += nRow;
	}
	if(j != nRow*3){
		if(DEBUG) {printf("wrong ans: j is %d\n",j);}
	}
	qsort(conflictCellPos,j,sizeof(short),compareShort);
	
	k=0;
	if(conflictCellPos[0] != n){
		conflict[n][0] = conflictCellPos[0];
		k++;
	}
	for(i=1;i<j;i++){
		if((conflictCellPos[i] != conflictCellPos[i-1]) && (conflictCellPos[i] != n)){
			conflict[n][k++] = conflictCellPos[i];
		}
	}
	
}

int findAns(short *cell){
	int i,j;
	short fValue[nRow+1]; /*forbidden*/
	short pValue[nRow]; /*possible*/
	short idx;
	short firstUnknown=0;
	short state;
	short *carbonCopy;
	
	while(SUCCESS == tryAns(cell)){
	}
	state = check(cell);
	if(SUCCESS == state){
		if(DEBUG) {
			printf("Ya!\n");
		}
		return SUCCESS;
	}
	
	firstUnknown = 0;
	while((firstUnknown < nCell) && (cell[firstUnknown] != 0)){ 
		firstUnknown++;
	}
	memset(fValue,0,sizeof(short)*(nRow+1));
	for(i=0; i < nConflict[nSize]; i++){
		j = conflict[firstUnknown][i];
		fValue[cell[j]] = 1;
	}
	idx = 0;
	for(i=1; i<=nRow; i++){
		if(fValue[i] == 0){
			pValue[idx++] = i;
		}
	}

	for(i = 0; i < idx ; i++){
		carbonCopy = (short *) malloc(sizeof(short)*nCell);
		memcpy(carbonCopy, cell, sizeof(short)*nCell);
		carbonCopy[firstUnknown] = pValue[i];
		if(DEBUG){
			printf("try to set %d to cell %d\n",pValue[i], firstUnknown);
		}
		if(SUCCESS == findAns(carbonCopy)){
			memcpy(cell, carbonCopy, sizeof(short)*nCell);
			return SUCCESS;
		}
		else{
			if(DEBUG){
				printf("recursive method failed for value %d in cell %d, try next one\n",pValue[i], firstUnknown);
			}
			free(carbonCopy);
		}
	}
	return DEAD;
}

void findSmallGridPos(short pos[], short i, short j){
	if ((i>nSize) || (j > nSize) || (i < 0) || (j < 0)){
		if(DEBUG) printf("ERROR on finding positions of small grid\n");
		return;
	}
	short idx, m,n, start;
	idx = 0;
	start = i*nSize*nRow + j*nSize;
	for(m=0;m<3;m++){
		for(n = 0; n< 3; n++){
			pos[idx++] = start + n;
		}
		start += nRow;
	}
	
}

int tryAns(short *cell){
	int state = STUCK;
	short i, j, nUnknown, check, target;
	short unknownCell[nRow*nRow];
	
	nUnknown=0;
	for(i=0;i<nCell;i++){
		if(0 == cell[i]){
			unknownCell[nUnknown++] = i;
		}
	}
	
	for(i=0;i<nUnknown;i++){
		short nCandidate = 0;
		short candidate;
		short fValue[nRow+1];

		memset(fValue, 0 , sizeof(short)*(nRow+1));			
		target = unknownCell[i];

		for(j=0;j<nConflict[nSize];j++){
			check = conflict[target][j];
			fValue[cell[check]] = 1;
		}

		for (j = 1; j <= nRow; j++){
			if( fValue[j] == 0){
				nCandidate++;
				candidate = j;
			}
		}
		if(nCandidate == 1){
			/*success*/
				
			if(DEBUG){
				printf("set %d to cell %d\n", candidate, target);
			}
			cell[target] = candidate;
			state = SUCCESS;

		}
	}
	
	return state;
}

int check(short *cell){
	unsigned int flag = 0;
	unsigned int filled = 0;
	int i,j;
	short rival;
	
	for(i=0;i<nCell;i++){
		if( (cell[i] <= 0) || (cell[i] > nRow)){
			if(DEBUG){
				/*printf("cell %d has invalid value %d\n",i, cell[i]);*/
			} 
			return UNFILLED;
		}
	}
	for(i=0;i<nCell;i++){
	/*check if the current configuration is valid*/
		filled = (1 << nRow+1) -2 ; /*lsb = 0*/
		flag = 0;
		for(j=0; j < nConflict[nSize]; j++){
			rival = conflict[i][j];
			flag = flag | (1 << cell[rival]);
		}
		if ( filled != (flag ^ (1 << cell[i]))) {
			if (DEBUG) {
				printf("ERROR: cell %hd conflicted \n", i);
				printf("filled: %x, flag: %x\n",filled, flag);
			}
			return FAIL;
		}
	}
	if(DEBUG){
		printf("It is a solution\n");
	}
	return SUCCESS;
}

void printSudoku(short *sudoku) {  
	int i,j;
	for(i=0;i<nRow;i++){
		printf("%d",sudoku[i*nRow]);
		for(j=1;j<nRow;j++){
			printf(" %d", sudoku[i*nRow + j]);
		}
		printf("\n");
	}
}

int compareShort(const void *a, const void *b){
	return (int)(*(short *)a - *(short *)b);
}