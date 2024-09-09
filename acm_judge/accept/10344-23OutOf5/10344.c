#include <stdio.h>
#include <stdlib.h>
#define PLUS 0
#define SUBSTRACT 1
#define MULTIPLY 2
#define MAX_COUNT 81
#define MAX_OPERATION MAX_COUNT
#define DEBUG 0
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)

long long add(long long a, long long b){
	return a + b;
}

long long substract(long long a, long long b){
	return a - b;
}

long long multiply(long long a, long long b){
	return a*b;
}

typedef long long (*opt)(long long, long long);

opt operation[3] = {add, substract, multiply};
char op[MAX_COUNT][4];
char allPermutation[120][5];

int convertToOperation(int n){
	int i;
	int tmp = n;
	for(i=0; i<4; i++){
		op[n][i] = tmp % 3;
		tmp = (tmp - op[n][i]) / 3;
	}
} 

int nextPermutation(char input[]){
	int j, ell;

	j = 3;
	while((j >= 0) && (input[j] >= input[j+1])){
		j--;
	}	
	if(j < 0) return 0;
	
	ell = 4;
	while ((ell >= 0) && (input[j] >= input[ell])){
		ell--;
	}
	if(ell < 0) return 0;
	
	SWAP(input[j], input[ell]);
	j++;
	ell = 4;
	while(j < ell){
		SWAP(input[j], input[ell]);
		j++;
		ell--;
	}
	#if DEBUG
	for(j=0; j<5; j++){
		printf("%d ", input[j]);
	}
	printf("\n");
	#endif
	return 1;
}

void buildTable(){
	int i, j;
	for(i=0; i<MAX_COUNT; i++){
		convertToOperation(i);
		#if 0
		for(j=0; j<4; j++){
			printf("%hhd ", op[i][j]);
		}
		printf("\n");
		#endif
	}
	for(i=0; i<5; i++){
		allPermutation[0][i] = i;
	}
	for(i=1; i<120; i++){
		for(j=0; j<5; j++){
			allPermutation[i][j] = allPermutation[i-1][j];
		}
		nextPermutation(allPermutation[i]);
	}
}

long long calc(long long input[5], int curOp, int curPermutation){
	int i;
	long long result = operation[op[curOp][0]](
		input[allPermutation[curPermutation][0]], 
		input[allPermutation[curPermutation][1]]);
	for(i=1; i<4; i++){
		result = operation[op[curOp][i]](result, input[allPermutation[curPermutation][i+1]]);
	}

	return result;
}

int solve(long long input[5]){
	long long result;
	int curOp, curPermutation;
	for(curOp = 0; curOp < MAX_OPERATION; curOp++){
		for(curPermutation = 0; curPermutation < 120; curPermutation++){
			result = calc(input, curOp, curPermutation);
			if(23 == result) return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}

int main(){
	long long input[5], check;
	int i;
	FILE *fp;
	fp = (DEBUG)? fopen("in6.txt", "r") : stdin;
	buildTable();
	
	while(5 == fscanf(fp, "%lld %lld %lld %lld %lld", input, input + 1, input + 2, input + 3, input + 4)){
		for(check = 0, i=0; i<5; i++){
			check |= input[i]; 
		}
		if(check == 0) break;		
		
		if(EXIT_SUCCESS == solve(input)){
			printf("Possible\n");
		}else{
			printf("Impossible\n");
		}
	}
	
	return 0;
}

		