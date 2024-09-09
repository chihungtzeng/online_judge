#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

int compareChar(const void *a, const void *b){
	char x , y, c, d;
	x = *(char *)a;
	y = *(char *)b;
	c = tolower(x);
	d = tolower(y);
	if(c != d) return c - d;
	
	
	if(x == y) return 0;
	else if (isupper(x) && islower(y)) return -1; /*x is upper case, y is lower case*/
	else return 1;
	
}

int nextPermutation(char *input){
	int len, j, k, ell;
	
	len = strlen(input);
	j = len - 2;
	while ((input[j] >= input[j+1]) && (j >= 0)){
				j--;
	}
	if (j < 0) return EXIT_FAILURE;
	
	ell = len - 1;
	while(input[j] >= input[ell]){
		ell--;
	}
	input[j] = input[j] ^ input[ell];
	input[ell] = input[j] ^ input[ell];
	input[j] = input[j] ^ input[ell];
	k = j+1;
	ell = len - 1;
	while(k < ell){
		input[k] = input[k] ^ input[ell];
		input[ell] = input[k] ^ input[ell];
		input[k] = input[k] ^ input[ell];
		k++;
		ell--;
	}
	return EXIT_SUCCESS;
}

int main(){
	
	char input[MAX];
	
	while(1 == scanf("%s", input)){
		if (input[0] == '#') break;
		if(nextPermutation(input) == EXIT_SUCCESS){
			printf("%s\n",input);
		}
		else{
			printf("No Successor\n");
		}
	}
	return 0;
}