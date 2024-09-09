#include <stdio.h>
#include <string.h>
#define MAX 110
#define DEBUG 0


int main(){
	int nCity1, nCity2;
	char city1[MAX], city2[MAX];
	short done = 0;
	short kcase = 1;
	short i,j;
	int table[MAX][MAX];

	city1[0] = 'X';
	city2[0]='X';

	for(i=0; i<MAX; i++){
		table[i][0] = 0;
		table[0][i] = 0;
	}
	
	while(1){
		fgets(&city1[1], MAX, stdin);		
		if ((city1[1] == '#')){
			break;
		}
		fgets(&city2[1], MAX, stdin);
		nCity1 = strlen(&city1[1]) - 1;
		nCity2 = strlen(&city2[1]) - 1;
		for(i=1; i <= nCity1; i++){
			for(j=1; j <= nCity2; j++){
				if( city1[i] == city2[j] ){
					table[i][j] = table[i-1][j-1] + 1;
				}
				else{
					table[i][j] = (table[i][j-1] > table[i-1][j])?
						table[i][j-1] : table[i-1][j];
				}		 
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", kcase, table[nCity1][nCity2]);
		kcase++;		
	}
	return 0;
}