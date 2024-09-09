#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 1000001
#define DEBUG 0

struct SmallInt{
	double digit;
	int p; /*digit*10^-p*/
};

char *SmallIntToString(struct SmallInt *s){
	char *output;
	long long x, y, r; /*x.yyy 10^-p*/
	assert(s != NULL);
	output = (char *) malloc(sizeof(char)*32);
	
	sprintf(output, "%.3lfe-%d", s->digit, s->p);
	return output;
}

int main(){
	int i, j, nTest, n;
	struct SmallInt *sInt;
	char *output;
	sInt = (struct SmallInt *) malloc(sizeof(struct SmallInt)*MAX);
	sInt[0].digit = 1;
	sInt[0].p = 0;
	for(i = 1; i<MAX; i++){
		sInt[i].digit = sInt[i-1].digit / 2.0;
		sInt[i].p = sInt[i-1].p;
		while(sInt[i].digit < 1){
			sInt[i].digit = (sInt[i].digit * 10) ;
			sInt[i].p += 1;	
		}
		
	}
	
	if(!DEBUG){
		
		while(1 == scanf("%d", &n)){
			
						
				output = SmallIntToString(&sInt[n]);
				printf("2^-%d = %s\n",n, output);
				free(output);
			
			

		}
	}
	free(sInt);
	return 0;	  
}