#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 901
#define MAXLEN 1800
#define BASE 1000000000000000000

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
	char output[MAXLEN];
	short i;
	assert(s != NULL);
	printf("%llu",s->value[s->length - 1]);
	for(i = s->length - 2; i >= 0; i--){
		printf("%018llu", s->value[i]);
	} 
	printf("\n");
	return EXIT_SUCCESS;
}

int main(){
	struct BigDecimal **bell;
	struct BigDecimal *ans, *src, *target;
	short i, j, n;

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
	
	for(i=1; i<MAX; i++){
		memcpy(&bell[1][i], &ans[i-1], sizeof(struct BigDecimal));
		for(j = i-1; j>=0; j--){
			addBigDecimal(&bell[1][j], &bell[1][j+1], &bell[0][j]);
		}
		memcpy(&ans[i], &bell[1][0], sizeof(struct BigDecimal));
		memcpy(bell[0], bell[1], sizeof(struct BigDecimal)*(i+1));
	}	
	
	while(1 == scanf("%hd", &n)){
		if(n == 0) break;
		
		printf("%hd, ",n);
		printBigDecimal(&ans[n-1]);
	}
	
	/*
	for(i=0; i<MAX;i++){
		printBigDecimal(&ans[i]);
	}
	*/
	for(i=0; i<2; i++){
		free(bell[i]);
	}
	free(bell);
	free(ans);
	return 0;
}