#include <stdio.h>
#define WHITE 1
#define BLACK 0

int nRow, nCol;
char color;

long long solve(){
	long long total, totalWhite;
	
	total = nRow * nCol + 49;
	total -= 7*nCol;
	total -= 7*nRow;
	 
	
	if(color == WHITE){
		totalWhite = (total >> 1) + (total % 2);
	}
	else{
		totalWhite = (total >> 1);
	}
	
	if(totalWhite < 0) return 0;
	else return totalWhite;
}

int main(){

	while(3 == scanf("%d %d %hhd", &nRow, &nCol, &color)){
		if(0 == nRow) return 0;
		
		printf("%lld\n", solve());
	}
	return 0;
}