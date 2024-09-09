#include <stdio.h>
#define MAX 77


int main(){
	unsigned int nInd[MAX];
	short i;
	nInd[1] = 1;
	nInd[2] = 2;
	nInd[3] = 2;
	for(i=4; i<MAX; i++){
		nInd[i] = nInd[i-2] + nInd[i-3];
	}
	while(1 == scanf("%hd", &i)){
		printf("%u\n",nInd[i]);
	}
	return 0;
}
