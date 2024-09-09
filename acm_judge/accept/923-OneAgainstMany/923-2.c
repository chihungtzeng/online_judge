#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXOINIT 2501
#define MAXN 51
#define DEBUG 0

int Oinit, R, nSubject;
int percent[MAXN];

int findAns(){
	int **table;
	short row, col, i, j, nLoser, nOpponent, nPreRowElement;
	short subject, nRow;
	int money, max, result;
	
	nRow = (nSubject * 4 < Oinit)? nSubject*4 : Oinit;

	table = (int **) malloc(sizeof(int *)*nRow);

	for(i=0; i<nRow; i++){
		table[i] = (int *) malloc(sizeof(int)*Oinit);
		memset(table[i], 0, sizeof(int)*Oinit);
	}
	
	for(col = 0; col < Oinit; col++){
		nLoser = Oinit - col;
		table[0][col] = R * nLoser/Oinit;
	}
		
	
	for(row = 1; row < nRow; row++){
		subject = row % nSubject;
		nPreRowElement = Oinit - row + 1;
		/*
			for each round "row", 
		*/
		for(col = Oinit - row - 1; col >= 0; col--){
			max = 0;
			for(i = col + 1; i<nPreRowElement; i++){
				nLoser = i - col;
				money = table[row-1][i];
				money = money - money*percent[subject]/100;
				result = money + (R * nLoser / i);
				if(result > max){
					max = result;
				}
			}
			
			table[row][col] = max;
		}
	}
	
	/*DEBUG*/
	if(DEBUG){
		printf("**********\n");
		for(row = 0; row < nRow; row++){
			for(col=0; col < Oinit - row; col++){
				printf("%d ",table[row][col]);
			}
			printf("\n");
		}
		printf("**********\n");
	}
	
	max = table[0][0];
	for(row = 1; row < nRow; row++){
		if(table[row][0] > max){
			max = table[row][0];
		}
	}	
	
	for(i=0; i<nRow; i++){
		free(table[i]);
	}	
	free(table);
	
	return max;
}


int main(){
	short nGame;
	short i;
	int ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	
	fscanf(fp,"%hd", &nGame);
	while(nGame >= 1){
		nGame--;
		fscanf(fp,"%d %d %d", &Oinit, &R, &nSubject);
		
		
		for(i=0; i< nSubject; i++){
			fscanf(fp,"%d", &percent[i]);
		}
		
		
		ans = findAns();
		printf("%d\n",ans);
	}
	return 0;
}
