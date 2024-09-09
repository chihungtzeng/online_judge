#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 205
int main(){
	int nTest, k = 1;	
	char input[MAX];
	int i, len, runLength;
	char *c, alphabet;
		
	
	scanf("%d", &nTest);
	while(k <= nTest){
		scanf("%s", input);
		runLength = 0;
		len = strlen(input);
		printf("Case %d: ", k);
		for(i=0; i<len; i++){
			if (isalpha(input[i])){
				while(runLength > 0){
					printf("%c", alphabet);
					runLength--;
				}
				alphabet = input[i];
			}
			else{
				runLength = runLength*10 + input[i] - '0';
			}
		}
		while(runLength > 0){
			printf("%c", alphabet);
			runLength--;
		}
		printf("\n");
		k++;
	}
	
	return 0;
}