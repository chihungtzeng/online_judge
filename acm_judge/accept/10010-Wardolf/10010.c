#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX 64
#define DEBUG 0


char matrix[MAX][MAX];
char m, n;
short bound;
char target[MAX];
short len;

int found(char r, char c, char roffset, char coffset){
	char i = 0;
	char rpos, cpos;
	rpos = r;
	cpos = c;

	if((roffset == 0) && (coffset ==0)) return EXIT_FAILURE;
	if((roffset == -1) && (r + 1 < len)) return EXIT_FAILURE;
	if((roffset == 1) && (m - r + 1 < len)) return EXIT_FAILURE;
	if((coffset == -1) && (c + 1 < len)) return EXIT_FAILURE;
	if((coffset == 1) && (n - c + 1 < len)) return EXIT_FAILURE;
	
	
	while(i < len){
		if(matrix[rpos][cpos] != target[i]) return EXIT_FAILURE;
		
		rpos += roffset;
		cpos += coffset;
		i++;
	}
	return EXIT_SUCCESS;
}

void findAns(){
	short i, j; 
	short len;
	char r, c;
	
	
	for(r=1; (r <= m) ; r++){
		for(c=1; c<=n; c++){
			for(i=-1; (i<=1) ; i++){
				for(j=-1; (j<=1) ; j++){
					if(found(r, c, i, j) == EXIT_SUCCESS){
						printf("%hhd %hhd\n",r, c);
						
						return;
					}
				}
			}
		}
	}

}

int main(){
	char i, j, first=1;
	short nTarget, nTest;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	fscanf(fp, "%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		fscanf(fp, "%hhd %hhd",&m, &n);
		for(i=1; i<=m; i++){
			fscanf(fp, "%s", &matrix[i][1]);
		}

		for(i=1; i<=m ;i++){	
			for(j=1; j<=n; j++){
				matrix[i][j] = tolower(matrix[i][j]);
			}
			/*puts(&matrix[i][1]);*/
		}		
		bound = m + n;		
		
		fscanf(fp, "%hd", &nTarget);
		for(i=0; i<nTarget; i++){
			fscanf(fp, "%s", target);
			len = strlen(target);
			for(j=0; j<len; j++){
				target[j] = tolower(target[j]);
			}
			/*printf("%s\n",target);*/
			findAns();
		}
		
		
	}
	return 0;
}