#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 32
#define DEBUG 0

typedef unsigned long long u64;

u64 fac[LEN];

void deleteChar(char set[], char target){
	int i = 0;
	for(i=0; set[i] != '\0'; i++){
		if(set[i] == target){
			set[i] = '\0';
			return ;
		}
	}
}


void solve(char output[LEN], char input[], u64 order){
	int i, j, pos;
	int len = strlen(input);
	int counter, k;
	char src;
	
	for(i=0, j=len-1; i<	len; i++, j--){
		pos = order / fac[j];
		order = order % fac[j];
		
		
		for(k=0, counter = 0; (k< len) && (counter < pos); k++){
			if(output[k] == 0) counter++;
		}
		while(output[k] != '\0') k++;
		output[k] = input[i];
	}
}

int main(){
	char input[LEN];
	char output[LEN];
	int i, k=1;
	u64 order;
	FILE *fp;
	
	
	int nTest;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	fscanf(fp, "%d", &nTest);
	
	fac[0] = 1;
	for(i=1; i<22; i++){
		fac[i] = fac[i-1] * i;
	}
	
	while(nTest--){
		fscanf(fp, "%s %llu", input, &order);
		memset(output, 0, LEN);
		solve(output, input, order - 1);
		printf("Case %d: %s\n", k++, output);
	}
	return 0;
}