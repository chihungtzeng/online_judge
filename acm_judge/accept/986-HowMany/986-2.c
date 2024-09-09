
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20


short n, r, k;
long nPath[MAXN][MAXN][MAXN];
long allPossiblePath[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};

long int getValue(short n, short r, short k){
	if(nPath[n][r][k] == -1){
		printf("Attempt to get an uninitialized value nPath[%hu %hu %hu]\n",n,r,k);
		return 0;
	}
	return nPath[n][r][k];
}

void fillNPath(short n, short r, short k){
	short i,j;
	long result = 0;
	if ((n == 0) && (r == 0)) {
		nPath[0][0][k] = 1;
		return ;
	}
	else if ((n == 0) && (r > 0)) {
		nPath[0][r][k] = 0;
		return ;
	}
	else if ( (n == k) && (r == 0)){
		nPath[n][0][k] = allPossiblePath[n] - 1;
	}
	else if( (n == k) && (r == 1)){
		nPath[n][r][n] = 1;
		return ;
	}
	else if( (n == k) && (r > 1)){
		nPath[n][r][n] = 0;
		return ;
	}
	else if ( (n < k) && (r > 0)){
		nPath[n][r][k] = 0;
		return ;
	}
	else if ((n < k)&&(r==0)){
		nPath[n][r][k] = allPossiblePath[n];
	}
/*Now n>k is the only possible cases*/
	else if( r > 0){
		for(i=1;i<n;i++){
			if(i != k){
				result += getValue(n-i, r, k); 
			}
			else {
				result += getValue(n-i, r - 1, k);
			}
		}
		nPath[n][r][k] = result;
	}
	else if (r == 0){
		for(i=1;i < n;i++){
			result += getValue(n, i, k);
		}
		result = allPossiblePath[n] - result;
		nPath[n][r][k] = result;
	}
	else {
		printf("r cannot be %d\n",r);
	}
}

int main(){
	
	memset(nPath, 0xff, sizeof(long)*MAXN*MAXN*MAXN);

	for(r=0; r<MAXN;r++){
		for(k=0;k<MAXN;k++){
			fillNPath(0,r,k);
		}
	}

	for(n=1; n<MAXN; n++){
		for(r=1; r<MAXN;r++){
			for(k=0;k<MAXN;k++){
				fillNPath(n,r,k);
			}
		}
		for(k=0;k<MAXN;k++){
			fillNPath(n,0,k);
		}
	}
	
	printf("n=1:\n");
	for(r=0; r<6; r++){
		for(k=0;k<6;k++){
			printf("(1 %d %d): %ld ",r,k,nPath[1][r][k]);
		}
		printf("\n");
	}
	printf("%ld\n",nPath[19][5][5]);
	/*
	while(3 == scanf("%hu %hu %hu",&n, &r, &k)){

		
	}
	*/
	return 0;
}
