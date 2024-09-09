#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define BASE 1000000 /*the number of digits is 5*/
#define MAX 9001
#define DEBUG 0

struct SmallInt{
	long long digit;
	int p; /*digit*10^-p*/
};

char *SmallIntToString(struct SmallInt *s){
	char *output;
	long long x, y, r; /*x.yyy 10^-p*/
	assert(s != NULL);
	output = (char *) malloc(sizeof(char)*16);
	r = s->digit  % 1000000000;
	x = (s->digit / 1000000000); /*x = ?.???*/
	
	if(r >=500000000) x++; 
	y = x % 1000;
	x = x / 1000;
	sprintf(output, "%lld.%03lldE-%d", x, y, s->p);
	return output;
}

int main(){
	short i, j, nTest, n;
	struct SmallInt sInt[MAX];
	char *output;
	sInt[1].digit = 5000000000000;
	sInt[1].p = 1;
	for(i = 2; i<MAX; i++){
		sInt[i].digit = sInt[i-1].digit / 2;
		sInt[i].p = sInt[i-1].p;
		if(sInt[i].digit < 1000000000000){
			sInt[i].digit = (sInt[i].digit * 10) ;
			sInt[i].p += 1;	
		}
		if(DEBUG){
			output = SmallIntToString(&sInt[i]);
			printf("2^-%hd: %s\n",i, output);
			free(output);
		}
	}
	
	if(!DEBUG){
		scanf("%hd",&nTest);
		while(nTest >= 1){
			nTest--;
			scanf("%hd", &n);
			output = SmallIntToString(&sInt[n]);
			printf("2^-%hd = %s\n",n, output);
			free(output);
		}
	}
	return 0;	  
}