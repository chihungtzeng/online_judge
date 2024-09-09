#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

long long *C;
long long nC;

int compareUInt(const void *a, const void *b){
	long long x, y;
	x =*(long long *)a;
	y =*(long long *)b;
	if(x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int mybsearch(long long target){
	int left, right, middle;
	left = 0;
	right = nC - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(C[middle] == target) return middle;
		else if (C[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
}

int main(){
	long long input;
	long long bound;
	long long *newC, *generator;
	int i,j, nGen, nNew, ans;
	char done;	
	bound = 2147483648;

	C = (long long *) malloc(sizeof(long long)*MAX);
	newC = (long long *) malloc(sizeof(long long)*MAX);
	generator = (long long *) malloc(sizeof(long long)*MAX);

	generator[0] = 1;
	C[0] = 1;
	nC = 1;
	done = 0;
	nGen= 1;
	while(!done){
		nNew = 0;
		for(i=0; i<nGen; i++){
			newC[nNew++] = generator[i] << 1;
			newC[nNew++] = (generator[i] << 1) + generator[i]; 
		}
		qsort(newC, nNew, sizeof(long long), compareUInt);
		j = 0;
		for(i=1; i<nNew; i++){
			if(newC[i] != newC[j]){
				j++;
				newC[j] = newC[i];
			}
		} 
		nGen = j + 1;
		/*
		for(i=0; i<nGen; i++){
			printf("%lld ", newC[i]);
		}
		printf("\n");
		*/
		
		memcpy(generator, newC, sizeof(long long)*nGen);
		for(i=0; i<nGen; i++){
			C[nC++] = newC[i];
		}
		if(newC[0] > bound){
			done = 1;
		}
	}
	free(newC);
	free(generator);
	qsort(C, nC, sizeof(long long), compareUInt);
	
	nGen = 0;
	printf("long long int C[] = {\n");
	
	for(i=0; i<nC; i++){
		if(C[i] <= 2147483648){
			printf(",%lld", C[i]);
			nGen++;
		}
		if(i % 20 == 0){
			printf("\n");
		}
	}
	printf("};\n");
	printf("int nC = %d\n",nGen);
	
	/*
	while(1){
		scanf("%lld",&input);
		if(0 == input){
			break;
		}
		if(input < 0){
			printf("1\n");
		}
		else{
			ans = mybsearch(input);
			if(C[ans] == input){
				printf("%lld\n", C[ans]);
			}
			else{
				printf("%lld\n",C[ans+1]);
			}
		}
	}
	*/
	free(C);
	return 0;
}
