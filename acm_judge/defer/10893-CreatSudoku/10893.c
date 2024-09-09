#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ILLEGAL 1
#define SAFE 2
#define SUCCESS 3
#define FAIL 4
#define STUCK 5
#define DEBUG 1
#define TRIVIAL 1
#define NON_TRIVIAL 0

void printSudoku(char *);
void genConflictCell(char);
int compareChar();
void initConflict();
int tryAns(char *cell);
int check(char *);
int checkValid(char *);
char getPossibleValue(char, char [], char *);
int findAns(char *);

char nRow = 9, nCell = 81;
char nConflict = 20;
char conflict[81][20]; 
char trivialCell[81];



int main(int argc, char *argv[]) {
   short i, j, kcase = 1, nAns, state, input;
   char *sudoku;
   char line[10];
   short nTest;
   char firstCase=1, pos;
   
   FILE *fp;
   
	
   if(DEBUG){	  
		fp = fopen("in.txt","r");
   }
   else{ 	fp = stdin;   }
   initConflict();
   
   sudoku = (char *) malloc(81);
   fscanf(fp, "%hd", &nTest);
   while(nTest >= 1){
   	nTest--;
   	memset(trivialCell, TRIVIAL, 81);
   	pos = 0;	
   	
   	for(i=0; i<9; i++){
	   	fscanf(fp, "%s", line);
	   	for(j=0; j<9; j++){
	   		if(line[j] == '.'){
	   			sudoku[pos] = 0;
	   			
	   		}
	   		else{
	   			sudoku[pos] = line[j] - '0';
	   			trivialCell[pos] = NON_TRIVIAL;
	   		}
	   		pos++;
	   	}
   	}
   	
		   	
   	findAns(sudoku);
   	
   	if(firstCase){
   		firstCase = 0;
   	}
   	else{
   		printf("\n");
   	}
   	printSudoku(sudoku);
 
   }

   free(sudoku);
	return 0;
}

void printSudoku(char *sudoku){
	char i,j,pos;
	pos = 0;
	for(i=0; i<9; i++){
		for(j=0;j<9;j++){
			if(trivialCell[pos] == NON_TRIVIAL){
				printf("%hhd", sudoku[pos]);
				if(DEBUG){
					printf("*");
				}
			}
			else{
				
				if(DEBUG){
					printf("%hhd ",sudoku[pos]);
				}
				else{
					printf(".");
				}
			}
			pos++;
		}
		printf("\n");
	}
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
	start = rgrid*27 + cgrid*3;
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
	short state;
	char *carbonCopy;
	char firstUnknown = 0;
	int nAns;
	
	while(SUCCESS == tryAns(cell)){
	}
	state = check(cell);
	if(SUCCESS == state){
		if(DEBUG) {
			printf("Ya!\n");
		}
		return 1;
	}
	
	while((firstUnknown < 81) && (cell[firstUnknown] != 0)){
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
	memcpy(carbonCopy, cell, 81);
	for(i = 0; i < idx ; i++){	
		
		carbonCopy[firstUnknown] = pValue[i];
		
		if(DEBUG){
			printf("try to set %d to cell %d\n",pValue[i], firstUnknown);
		}
		nAns = findAns(carbonCopy);
		if(nAns == 1){
			memcpy(cell, carbonCopy, 81);
			free(carbonCopy);
			trivialCell[firstUnknown] = NON_TRIVIAL;
			return 1;
		}
		carbonCopy[firstUnknown] = 0;
	}
	free(carbonCopy);
	
	return 0;
}

char getPossibleValue(char target, char possibleValue[], char *cell){
	char i, j, check;
	char nCandidate = 0;
	char candidate;
	char fValue[10];
	
	if(cell[target] != 0) return 0;

	memset(fValue, 0 , 10);			
	
	for(j=0;j<nConflict;j++){
		check = conflict[target][j];
		fValue[cell[check]] = 1;
	}

	for (j = 1; j <= 9; j++){
		if( fValue[j] == 0){
			possibleValue[nCandidate++] = j;
		}
	}
	return nCandidate;
}

int tryAns(char *cell){
	char state = STUCK;
	char i, j,  check, target;
	char nUnknown = 0, unknownCell[81];

	for(i=0; i<81; i++){
		if(cell[i] == 0){
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