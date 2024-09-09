#include <stdio.h>
#include <string.h>
#define MAX 101
#define RESIDUE 1000000

int table[MAX][MAX];

void fillTable(){
	short n, m, i;
	memset(table, 0, sizeof(int)*MAX*MAX);
	for(n = 0; n<MAX; n++){
		table[0][n] = 0;
		table[1][n] = 1;
	}
	for(m = 2; m<MAX; m++){
		for(n=0; n<MAX; n++){
			for(i=0; i <= n; i++){
				table[m][n] += table[m-1][n-i];
			}
			table[m][n] = table[m][n] % RESIDUE;
		}
	}
}

int main(){
	short n, m;
	fillTable();
	while(1){
	 	scanf("%hd %hd", &n, &m);
		if( (n ==0) && (m == 0)){
			break;
		}
		printf("%d\n", table[m][n]);
	}
	
	return 0;
}