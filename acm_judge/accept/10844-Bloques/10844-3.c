#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 900
#define MAXLEN 1800
#define BASE 1000000000000000000
#define DEBUG 0

char *output;
int outputLen;

struct BigDecimal{
	short length;
	unsigned long long value[100];
};



int addBigDecimal(struct BigDecimal *result, const struct BigDecimal *s, const struct BigDecimal *t){
	short loopLen, i;
	unsigned long long carry = 0;
	assert((result != NULL) && (s != NULL) && (t != NULL));
	loopLen = (s->length > t->length)? s->length: t->length;

	for(i=0; i<loopLen; i++){
		result->value[i] = carry + s->value[i] + t->value[i];
		carry = result->value[i] / BASE;
		result->value[i] = result->value[i] % BASE;
	}
	if(carry > 0){
		result->value[i] = carry;
		result->length = loopLen + 1;
	}
	else{
		result->length = loopLen;
	}
	return EXIT_SUCCESS;
}


int printBigDecimal(const struct BigDecimal *s){
	short i;
	assert(s != NULL);
	
	outputLen += sprintf(&output[outputLen], "%llu",s->value[s->length - 1]);
	for(i = s->length - 2; i >= 0; i--){
		outputLen += sprintf(&output[outputLen], "%018llu", s->value[i]);
	} 
	outputLen += sprintf(&output[outputLen], "\n");
	return EXIT_SUCCESS;
}

int main(){
	struct BigDecimal **bell;
	struct BigDecimal *ans, *src, *target, *tmp;
	short i, j, n;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;

	ans = (struct BigDecimal *) malloc(sizeof(struct BigDecimal)*MAX);	
	bell = (struct BigDecimal **) malloc(sizeof(struct BigDecimal *)*2);
	
		
	assert(bell != NULL);
	for(i=0; i<2; i++){
		bell[i] = (struct BigDecimal *) malloc(sizeof(struct BigDecimal)*MAX);
		assert(bell[i] != NULL);
	}
	bell[0][0].value[0] = 1;
	bell[0][0].length = 1;
	memcpy(&ans[0], &bell[0][0], sizeof(struct BigDecimal));
	src = bell[0];
	target = bell[1];
	for(i=1; i<MAX; i++){
		memcpy(&target[i], &ans[i-1], sizeof(struct BigDecimal));
		for(j = i-1; j>=0; j--){
			addBigDecimal(&target[j], &target[j+1], &src[j]);
		}
		memcpy(&ans[i], &target[0], sizeof(struct BigDecimal));
		tmp = src;
		src = target;
		target = tmp;
	}
	for(i=0; i<2; i++){
		free(bell[i]);
	}
	free(bell);
	
	output = (char *) malloc(1048576);
	outputLen = 0;
	while(1 == fscanf(fp, "%hd", &n)){
		if(n == 0) break;
		outputLen += sprintf(output + outputLen, "%hd, ",n);
		printBigDecimal(&ans[n-1]);
	}
	
	/*fwrite(output, sizeof(char), outputLen, stdout);*/
	write(1, output, outputLen);
	/*
	for(i=0; i<MAX;i++){
		printBigDecimal(&ans[i]);
	}
	*/
	free(output);
	free(ans);
	return 0;
}