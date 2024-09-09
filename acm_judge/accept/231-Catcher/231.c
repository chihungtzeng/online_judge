#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

short findAns(short nMissile, short height[]){
	short intercept[nMissile];
	
	short max = 0, i, j;
	for(i=0; i<nMissile; i++){
		intercept[i] = 1;
	}
	for(i=1; i<nMissile; i++){
		for(j=0; j<i; j++){
			if( (height[j] >= height[i]) && (intercept[i] < intercept[j] + 1)){
				intercept[i] = intercept[j] + 1;
			}
		}
	}
	for(i=0; i<nMissile; i++){
		/*printf("%hd(%hd) ", height[i], intercept[i]);*/
		if(intercept[i] > max) max = intercept[i];
	}
	return max;
}

int main(){
	char first=1;
	short k=1, input;
	short height[MAX];
	short nMissile = 0, nIntercept;
	short i;	
	
	while(1 == scanf("%hd", &input)){
		if( (input == -1) && (nMissile == 0)){
			return 0;
		}
		if( (input == -1) && (nMissile > 0)){
			
			nIntercept = findAns(nMissile, height);
			if(first){
				first = 0;
			}
			else{
				printf("\n");
			}
			printf("Test #%hd:\n",k++);
			printf("  maximum possible interceptions: %hd\n", nIntercept);
			nMissile = 0;
		}
		else{
			height[nMissile++] = input;
		}
	}
	return 0;
}