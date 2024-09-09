#include <stdio.h>
#include <stdlib.h>
#define NUM 15

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	
	int kNum[] = {561, 1105, 1729, 2465, 2821, 6601, 8911,10585, 15841, 29341, 41041,
46657, 52633, 62745, 63973};
	int *match;
	int input;
	
	while(1){
		scanf("%d",&input);
		if(0 == input){
			break;
		}
		match = bsearch(&input, kNum, NUM, sizeof(int), compareInt);
		if(match){
			printf("The number %d is a Carmichael number.\n", input);
		}
		else {
			printf("%d is normal.\n",input);
		}
	}
	
	return 0;
}
