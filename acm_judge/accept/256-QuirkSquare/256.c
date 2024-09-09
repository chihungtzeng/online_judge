#include <stdio.h>
#define MAX 2000

int quirk[4][MAX];
int nQuirk[4] = {0, 0, 0, 0};

void buildQuirkTable(){
	int sq = 0, i = 0, j;
	int divisor[4] = {10, 100, 1000, 10000};
	int lsb, msb;	
	while(sq < 1000000000){
		for(j=0; j<4; j++){
			lsb = sq % divisor[j];
			msb = sq / divisor[j];
			if((lsb + msb == i) && (i < divisor[j])){
				quirk[j][nQuirk[j]++] = sq;
			} 
		}
		i++;
		sq = i*i;
	}
}

int main(){
	int n, i, x;
	buildQuirkTable();
	while(1 == scanf("%d", &n)){
		x = (n - 2) >> 1;
		for(i=0; i<nQuirk[x]; i++){
			printf("%0*d\n", n, quirk[x][i]);
		}
	}
	return 0;
}