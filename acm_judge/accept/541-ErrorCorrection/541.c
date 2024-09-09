#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
	short matrix[MAX][MAX];
	short m, i, j, parity;
	char rowParity[MAX], colParity[MAX];
	short nOddParityForRow, nOddParityForCol;
	short row, col;
	while(1 == scanf("%hd", &m)){
		if(m == 0) break;
		
		nOddParityForRow = 0;
		nOddParityForCol = 0;
		row = -1;
		col = -1;
		for(i=0; i<m; i++){
			parity = 0;
			for(j=0; j<m; j++){
				scanf("%hd", &matrix[i][j]);
				parity += matrix[i][j];
			}
			rowParity[i] = parity & 1;
			if(rowParity[i] == 1){
				nOddParityForRow += 1;
				row = i;
			}
		}
		for(i=0; i<m; i++){
			parity = 0;
			for(j=0; j<m; j++){
				parity += matrix[j][i];
			}
			colParity[i] = parity & 1;
			if(colParity[i] == 1){
				nOddParityForCol += 1;
				col = i;
			}
		}
		
		if((nOddParityForRow == 0)	&& (nOddParityForCol == 0)){
			printf("OK\n");
		}
		else if ((nOddParityForRow == 1)	&& (nOddParityForCol == 1)){
			printf("Change bit (%hd,%hd)\n", row+1, col+1);
		}
		else {
			printf("Corrupt\n");
		}
	}
	return 0;
}
