#include <stdio.h>
#include <stdlib.h>
#define BASE 1000000000
#define BASELEN 9
#define MAX 4000

struct BigDecimal{
	long long num[100];
	short length;
};

int BigDecimalAdd(struct BigDecimal *result, struct BigDecimal *x, struct BigDecimal *y){
	short xlen, ylen, i, maxlen;
	long long carry = 0;
	xlen = x->length;
	ylen = y->length;
	if(xlen > ylen) maxlen = xlen;
	else maxlen = ylen;
	
	for(i=0; i<maxlen; i++){
		result->num[i] = x->num[i] + y->num[i] + carry;
		carry = result->num[i] /  BASE;
		result->num[i] = result->num[i] % BASE;
	}
	if(carry > 0){
		result->length = maxlen + 1;
		result->num[maxlen] = carry;
	}
	else{
		result->length = maxlen;
	}
	return EXIT_SUCCESS;
}

int BigDecimalPrint(struct BigDecimal *x){
	short len, i;
	len = x->length;
	printf("%lld", x->num[len - 1]);
	for(i=len-2; i>=0; i--){
		printf("%09lld",x->num[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int main(){
	int i;
	struct BigDecimal fib[MAX];
	fib[0].num[0] = 1;
	fib[0].length = 1;
	fib[1].num[0] = 1;
	fib[1].length = 1;
	
	
	for(i=2; i<MAX; i++){
		BigDecimalAdd(&fib[i], &fib[i-1], &fib[i-2]);		
	}
	
	while(1 == scanf("%d", &i)){
		if(0 == i){
			break;
		}
		BigDecimalPrint(&fib[2*i - 1]);
	}
	return 0;
}