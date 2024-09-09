#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ILLEGAL 1
#define SAFE 2
#define SUCCESS 3
#define FAIL 4
#define STUCK 5
#define DEBUG 0

void printSudoku();
void genConflictCell(char);
int compareChar();
void initConflict();
int tryAns(char *cell);
int check(char *);
int checkValid(char *);

char nRow = 9, nCell = 81;
char nConflict = 20;
char conflict[81][20]; 


int main(int argc, char *argv[]) {
   short i, j, kcase = 1, nAns, state, input;
   char *sudoku;
   FILE *fp;
   

   if(DEBUG){	
   	/*fp = fopen("in.txt","r");*/  
		fp = fopen("in5.txt","r");
   }
   else{ 	fp = stdin;   }
   initConflict();
   
   sudoku = (char *) malloc(81);
   while(1 == fscanf(fp, "%hd", &input)){
   	sudoku[0] = input;    	
   	for(i=1;i< nCell; i++){
	   	fscanf(fp, "%hd", &input);
	   	sudoku[i] = input;
   	}
   	state = checkValid(sudoku);
   	if(ILLEGAL == state){
   		printf("Case %hd: Illegal.\n",kcase++);
   		continue;
   	}
   	nAns = findAns(sudoku);
   	if(nAns == 0){
   		printf("Case %hd: Impossible.\n",kcase++);
   	}
   	else if (nAns == 1){
   		printf("Case %hd: Unique.\n",kcase++);
   	}
   	else if (nAns > 1){
   		printf("Case %hd: Ambiguous.\n", kcase++);
   	}
   	else {
   		printf("undefined return\n");
   	}	  
   }
   free(sudoku);
	return 0;
}

void initConflict(){
	char i;
	for(i=0; i<81; i++){
		genConflictCell(i);
	}
}

void genConflictCell(char n){
	char rgrid, cgrid;
	char rpos, cpos;
	char i,j, k;
	char conflictCellPos[27];
	char start;

	
	rpos = n / 9;
	cpos = n  % 9;
	rgrid = rpos / 3;
	cgrid = cpos / 3;
	j=0;
	start = rpos * 9;
	for(i=0;i<9;i++){
		conflictCellPos[j++] = start + i;
	}
	start = cpos;
	for(i=0;i<9;i++){
		conflictCellPos[j++] = start;
		start += 9;
	}
	start = (rgrid*3)*9 + cgrid*3;
	for(i=0;i<3;i++){
		for(k=0;k <3; k++){
			conflictCellPos[j++] = start + k;
		}
		start += 9;
	}

	qsort(conflictCellPos, 27 , 1, compareChar);
	
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

int findAns(char *cell){
	char i,j;
	char fValue[10]; /*forbidden*/
	char pValue[9]; /*possible*/
	char idx;
	char firstUnknown=0;
	short state;
	char *carbonCopy;
	short nAns = 0;
	
	while(SUCCESS == tryAns(cell)){
	}
	state = check(cell);
	if(SUCCESS == state){
		if(DEBUG) {
			printf("Ya!\n");
		}
		return 1;
	}
	
	firstUnknown = 0;
	while((firstUnknown < nCell) && (cell[firstUnknown] != 0)){ 
		firstUnknown++;
	}
	memset(fValue,0, 10);
	for(i=0; i < nConflict; i++){
		j = conflict[firstUnknown][i];
		fValue[cell[j]] = 1;
	}
	idx = 0;
	for(i=1; i<=9; i++){
		if(fValue[i] == 0){
			pValue[idx++] = i;
		}
	}

	carbonCopy = (char *) malloc(81);
	for(i = 0; i < idx ; i++){	
		memcpy(carbonCopy, cell, 81);
		carbonCopy[firstUnknown] = pValue[i];
		if(DEBUG){
			printf("try to set %d to cell %d\n",pValue[i], firstUnknown);
		}
		nAns += findAns(carbonCopy);
		if(nAns > 1){
			free(carbonCopy);
			return nAns;
		}
	}
	free(carbonCopy);
	return nAns;
}



int tryAns(char *cell){
	char state = STUCK;
	char i, j, nUnknown, check, target;
	char unknownCell[81];
	
	nUnknown=0;
	for(i=0;i<nCell;i++){
		if(0 == cell[i]){
			unknownCell[nUnknown++] = i;
		}
	}
	
	for(i=0;i<nUnknown;i++){
		char nCandidate = 0;
		char candidate;
		char fValue[10];

		memset(fValue, 0 , 10);			
		target = unknownCell[i];

		for(j=0;j<nConflict;j++){
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

int checkValid(char *cell){
	char i, j, rival;
	for(i=0; i<81; i++){
		if(cell[i] != 0){
			for(j=0; j<nConflict; j++){
				rival = conflict[i][j];
				if(cell[i] == cell[rival]){
					return ILLEGAL;
				}
			}
		}
	}
	return SAFE;
}

int check(char *cell){
	unsigned int flag = 0;
	unsigned int filled = 0;
	char i,j;
	char rival;
	

	for(i=0;i<81;i++){
	/*check if the current configuration is valid*/
		filled = (1 << nRow+1) -2 ; /*lsb = 0*/
		flag = 0;
		for(j=0; j < nConflict; j++){
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
	return SUCCESS;
}



int compareChar(const void *a, const void *b){
	char x, y;
	x = *(char *)a;
	y = *(char *)b;
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}