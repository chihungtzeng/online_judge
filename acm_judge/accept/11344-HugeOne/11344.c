#include <stdio.h>
#define MAX 1005

char input[MAX];
short divisor[12];
short nDivisor;


short dividable(short d){
	short r, i, len;
	char *c;
	c = input;
	r = 0;
	while(isdigit(*c)){
		r = (r*10 + (*c - '0')) % d; 
		c++;
	}
	if(r == 0) return 1;
	else return 0;
}

short isWonderful(){
	short i;
	short result = 1;
	char done = 0;
	
	for(i=0; (i<nDivisor) && (!done); i++){
		if(dividable(divisor[i]) == 0){
			done = 1;
			result = 0;
		}
	}
	return result;
}

int main(){
	short nTest;
	short i;
	
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s", input);
		scanf("%hd",&nDivisor);
		for(i=0; i<nDivisor; i++){
			scanf("%hd", &divisor[i]);
		}

		if(isWonderful()){
			printf("%s - Wonderful.\n", input);
		}
		else {
			printf("%s - Simple.\n", input);
		}
	}
	return 0;
}