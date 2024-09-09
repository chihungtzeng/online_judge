#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXCOL 102

int main(){
	short int field[MAXCOL][MAXCOL];
	char result[MAXCOL][MAXCOL];
	int nRow, nCol,row,col;
	char c;
	int i,j,done;
	int nField;
	FILE *fp;
	fp = stdin;

	done = 0;
	nField=1;
	while (!done){ 
		scanf("%d %d",&nRow,&nCol);
		if((0 == nRow) && (0 == nCol)){
			done = 1;
			break;
		}
		if(nField != 1){
			printf("\n");
		}
		i=0;
		memset(field,0,MAXCOL*MAXCOL);
		while(i < nRow*nCol){
			c = getc(fp);
			if(!isspace(c)){
				row = (i/ nCol) + 1;
				col = (i % nCol) + 1;
				field[row][col] = ('*' == c)? 1 : 0;
				i++;
			}
		} /*end of input*/
	
		for(i=1;i<=nRow;i++){
			for(j=1;j<=nCol;j++){
				if(field[i][j] == 1){
					result[i][j] = '*';
				}
				else{
					result[i][j] = '0'+field[i-1][j-1]+field[i-1][j]+field[i-1][j+1] +
						field[i][j-1]+field[i][j+1]+
						field[i+1][j-1]+field[i+1][j]+field[i+1][j+1];
				}
			}
		}
		/*output answer*/
		printf("Field #%d:\n",nField);
		nField++;
		for(i=1;i<=nRow;i++){
			for(j=1;j<=nCol;j++){
				printf("%c",result[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
