#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define MAXLEN 2000

int compareString(const void *s, const void *t){
	char *x,*y, *yx, *xy ;
	short result, xlen, ylen;
	x = (char *)s;
	y = (char *)t;

	xlen = strlen(x);
	ylen = strlen(y);
	xy = (char *) malloc(xlen + ylen + 1);
	strcpy(xy, x);
	strcat(xy, y);
	yx = (char *) malloc(xlen + ylen + 1);
	strcpy(yx, y);
	strcat(yx, x);
	result = strcmp(yx, xy);
	free(xy);
	free(yx);
	return result;
}

int main(){
	char input[MAX][MAXLEN];
	short nNum, i;
	
	while(1){
		scanf("%hd",&nNum);
		if(nNum == 0){
			break;
		}
		for(i = nNum - 1; i>=0; i--){
			scanf("%s", input[i]);
		}
		qsort(input, nNum, MAXLEN, compareString);
		for(i=0; i<nNum; i++){
			printf("%s",input[i]);
		}
		printf("\n");
	}
	return 0;
}