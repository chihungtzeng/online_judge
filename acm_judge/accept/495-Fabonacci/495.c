#include <stdio.h>
#include <stdlib.h>
#define MAX 5001

int main(){
	long int *fab;
	int i,n;
	
	fab = (long int *) malloc(sizeof(long int)*MAX);
	fab[0] = 0;
	fab[1] = 1;
	for(i=2;i<=MAX;i++){
		fab[i] = fab[i-1] + fab[i-2];
	}
	while (1 == scanf("%d",&n)){
		printf("The Fibonacci number for %d is %ld\n",n,fab[n]);
	}

	return 0;
}