#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 70

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int isPossible(short nOriginalStick){
	char 
	if(nOriginalStick == 1) return EXIT_SUCCESS;
	
}

int main(){
	short nStick;
	short stick[MAX];
	short sum;

		
	while(1 == scanf("%hd", &nStick)){
		char done = 0;
		short i, target;
		if(nStick == 0) return 0;
		sum = 0;
		
		
		for(i=0; i<nStick; i++){
			scanf("%hd",stick+i);
			sum += stick[i];
		}
		qsort(stick, nStick, sizeof(short),compareShort);
		
		for(i=stick[nStick - 1]; !done; i++){
			if(sum % i == 0){
				target = sum / i;
				if(isPossible(target) == EXIT_SUCCESS){
					done = 1;
					printf("%hd\n",target);
				}		
			}			
		} 
	}
	return 0;
}