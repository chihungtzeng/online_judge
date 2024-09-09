#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define T 6


char pool[MAX];
char nChar;
char idx[10];
char output[2000][20];

int compareChar(const void *a, const void *b){
	return *(char *)b - *(char *)a;
}

void solve(){
	char i, j, t;

	short nOutput = 0, len;
	qsort(pool, nChar, sizeof(char), compareChar);
	for(j=1; j <= T; j++){
		idx[j] = j - 1;
	}
	idx[T + 1] = nChar;
	idx[T + 2] = 0;

	while(1){	
		/*VISIT*/
		len = sprintf(output[nOutput], "%hhd", pool[idx[T]]);
		for(i = T - 1; i >= 1; i--){
			len += sprintf(output[nOutput] + len, " %hhd", pool[idx[i]]);
		}
		/*len += sprintf(output[nOutput] + len, "\n");*/
		nOutput++;		
		
		j = 1;
		while(idx[j] + 1 == idx[j+1]){
			idx[j] = j - 1;
			j++;
		}
		if(j > T) break;
		idx[j] = idx[j] + 1;
	}
	for(len = nOutput - 1; len>=0; len--){
		puts(output[len]);
	}
}

int main(){
	char i;
	FILE *fp = stdin;
	char first = 1;
	while(1 == fscanf(fp, "%hhd", &nChar)){
		if(nChar == 0) return 0;
		for(i=0; i<nChar; i++){
			fscanf(fp, "%hhd", pool+ i);
		}
		
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		solve();
	}
	return 0;
}