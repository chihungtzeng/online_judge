#include <stdio.h>
#define MAXN 20

int main(){
	int nPath[2*MAXN][2*MAXN];
	int i,j,k;
	
	for(i=0; i<2*MAXN;i++){
		for(j=0; j<2*MAXN; j++){
			nPath[i][j] = 0;
		}
	}
	for(i=0;i<MAXN; i++){
		nPath[i][i] = 1;
	}	
	
	for(i=1; i < MAXN;i++){
		k = 2*i;
		for(j=0;j<MAXN-i; j++){
			if(j == 0) {
				nPath[k][j] = nPath[k-1][1];
			}
			else{
				nPath[k+j][j] = nPath[k+j-1][j+1] + nPath[k+j-1][j-1];
			}
		}
	} 
	for(i=0;i<MAXN;i++){
		printf("%d, ",nPath[2*i][0]);
	}
	printf("\n");
}