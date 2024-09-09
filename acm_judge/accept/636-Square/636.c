#include <stdio.h>
#include <stdlib.h>
#define MAX 31623

int square[MAX];
int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int findAns(int input){
	char digit[16];
	short nDigit = 0, i, j;
	int tmp = input, target, p;
	int minBase = 0;
	int *match;
	while(tmp > 0){
		digit[nDigit++] = tmp % 10;
		tmp = tmp / 10;
	}
	for(i=0; i<nDigit; i++){
		if(digit[i] > minBase) minBase = digit[i];
	}
	
	for(i = minBase + 1; i<100; i++){
		target = digit[0];
		p = i;
		for(j=1; j<nDigit; j++){
			target += digit[j]*p;
			p = p*i;
		}
		match = (int *) bsearch(&target, square, MAX, sizeof(int), compareInt);
		if(match) return i;
	}
	return -1;
}

int main(){
	int i;	
	int input;

	for(i=0; i<MAX; i++){
		square[i] = i*i;
	}
	
	while(1 == scanf("%d", &input)){
		if(input == 0) return 0;
		
		if(input == 1){
			puts("2");
			continue;
		}
		printf("%d\n", findAns(input));
	}
	
	return 0;
}