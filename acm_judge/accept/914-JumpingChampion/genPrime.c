#include <stdio.h>
#include <stdlib.h>
#define MAX 30000

int *primelist;
int nPrime;

void initPrimeList(){
	int i,j;
	short isPrime;
	primelist[0] = 2;	
	nPrime = 1;
	for(i=3; i<MAX; i++){
		isPrime = 1;
		for(j=0; (j<nPrime) && (isPrime == 1);j++){
			if(i % primelist[j] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primelist[nPrime++] = i;
		}
	}
}

int main(){
	
	int i;	
	
	primelist = (int *) malloc(sizeof(int)*MAX);
	initPrimeList();
	printf("int primelist[] = {");
	for(i=0; i<nPrime; i++){
		printf("%d, ", primelist[i]);
		if(i%10 == 0){
			printf("\n");
		}
	}
	printf("}\n");
	printf("nPrim = %d\n",nPrime);
	
	free(primelist);
	return 0;
}

