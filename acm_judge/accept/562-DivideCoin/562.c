#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define DEBUG 0

short coin[MAX];
short nCoin;
int total;
int bound;

int compareShort(const void *a,const void *b){
	return *(short *)a - *(short *)b;
}

int solve(){
	int i, j;
	char possible[50001];
	memset(possible, 0, 50001);
	possible[0] = 1;
	for(i=0; i<nCoin; i++){
		for(j=bound + 1; j>=0; j--){
			if(possible[j]){
				possible[j + coin[i]] = 1;
			}
		}
	}
	for(i = bound + (total % 2); i>=0; i--){
		if(possible[i]){
			return (abs(total - 2*i));
		}
	}
	return total;
}

int main(){
	short nTest;
	short i;
	int ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	fscanf(fp, "%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp,"%hd",&nCoin);
		total = 0;
		for(i=0; i<nCoin; i++){
			fscanf(fp,"%hd", coin + i);
			total += coin[i];
		}
		bound = total >> 1;
/*		qsort(coin, nCoin, sizeof(short), compareShort);*/
		ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}