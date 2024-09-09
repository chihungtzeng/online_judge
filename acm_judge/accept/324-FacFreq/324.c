#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 1000000000

struct BigDecimal{
	long long num[100];
	short length;
};

char *bigDecimalToString(const struct BigDecimal *b){
	char *s, *t;
	int i;
	s = (char *) malloc(sizeof(char)*9*b->length);
	t = (char *) malloc(sizeof(char)*10);
	sprintf(s, "%lld", b->num[b->length - 1]);
	
	for(i = b->length-2; i >= 0; i--){
		sprintf(t, "%09lld", b->num[i]);
 		strcat(s, t);
	}
	free(t);
	return s;
}


int bigDecimalMultiply(struct BigDecimal *result, struct BigDecimal *x, struct BigDecimal *y){
	long long carry = 0, tmp;
	short xlen, ylen, maxlen, i, j;;
	xlen = x->length;
	ylen = y->length;
	memset(result, 0, sizeof(struct BigDecimal));
	for(i=0; i<ylen; i++){
		carry = 0;
		for(j=0; j<xlen; j++){
			result->num[i+j] = result->num[i+j] + x->num[j] * y->num[i] + carry;
			carry = result->num[i+j] / BASE;
			result->num[i+j] = result->num[i+j] % BASE;
		}
		if(carry > 0){
			result->num[i + xlen] = carry;
		}
	}
	
	if(carry == 0){
		result->length = xlen + ylen - 2;
	}
	else if (carry > 0){
		result->num[xlen + ylen - 1] = carry;
		result->length = xlen + ylen - 1;
	}
	return EXIT_SUCCESS;
}

int bigDecimalMultiplyByInt(struct BigDecimal *result, struct BigDecimal *x, int y){
	long long carry = 0, tmp;
	short xlen, ylen, maxlen, i, j;;
	xlen = x->length;
	
	memset(result, 0, sizeof(struct BigDecimal));
	
	carry = 0;
	for(j=0; j<xlen; j++){
		result->num[j] = result->num[j] + x->num[j] * y + carry;
		carry = result->num[j] / BASE;
		result->num[j] = result->num[j] % BASE;
	}
	if(carry == 0){
		result->length = xlen;
	}
	else if (carry > 0){
		result->num[xlen] = carry;
		result->length = xlen + 1;
	}
	return EXIT_SUCCESS;
}


int main(){
	int i, query, len;
	struct BigDecimal fac[367];
	char *outputString;
	int occr[10];
	fac[0].num[0] = 1;
	fac[0].length = 1;	

	for(i=1; i<367; i++){
		bigDecimalMultiplyByInt(fac + i, fac + i - 1, i);
	}
	
	while(1 == scanf("%d",&query)){
		if(0 == query) break;
		
		outputString = bigDecimalToString(fac + query);
		len = strlen(outputString);
		memset(occr, 0, sizeof(int)*10);
		for(i=0; i<len; i++){
			occr[outputString[i] - '0'] += 1;
		}
		printf("%d! --\n",query);
		for(i=0; i<5; i++){
			printf("   (%d)   %d", i, occr[i]);
		}
		printf("\n");
		for(i=5; i<10; i++){
			printf("   (%d)   %d", i, occr[i]);
		}
		printf("\n");
		free(outputString);	
	}
	return 0;
}

