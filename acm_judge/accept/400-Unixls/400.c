#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int compareString(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int main(){
	int n, nRow, nCol;
	int i, j, k, maxlen, len, index;
	char fn[MAX][61];
	char fnLen[MAX];
	while(1 == scanf("%d", &n)){
		maxlen = 0;
		for(i=0; i<n; i++){
			scanf("%s",fn[i]);

		}
		qsort(fn, n, 61, compareString);
		for(i=0; i<n; i++){
			fnLen[i] = strlen(fn[i]);
			if(fnLen[i] > maxlen){
				maxlen = fnLen[i];
			}
		}
		len = maxlen + 2;
		nCol = 62 /(maxlen + 2);
		/*nCol = (60 - maxlen)/(maxlen + 1) + 1;*/
		nRow = n/nCol;
		if(n % nCol >= 1) nRow++;
		
		for(i=1; i<=60; i++){
			printf("%c",'-');
		}
		printf("\n");
		
		for(i=0; i<nRow; i++){
			for(j=0; j<nCol; j++){		
				index = j*nRow + i;
				if(index < n){	
					printf("%s", fn[index]);
					for(k=fnLen[index]; k < len; k++){
						printf(" ");
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}