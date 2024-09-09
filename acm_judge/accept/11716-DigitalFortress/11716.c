#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 65536
#define MAXR 256

int main(){
	char line[MAX];
	size_t len, n;
	int i, j, nTest;
	char matrix[MAXR][MAXR];
	
	
	fgets(line, MAX, stdin);
	nTest	= atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, MAX, stdin);
		len = strlen(line);
		if(line[len - 1] == '\n') {
			line[len-1] = '\0';
			len--;
		}
		n = sqrt(len);
		if(n*n != len){
			puts("INVALID");
			continue;
		}
		for(i=0; i<n; i++){
			memcpy(matrix[i], line + i*n, n); 
		}
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf("%c",matrix[j][i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}