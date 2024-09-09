#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned char u8;

struct BigInteger{
	/*The msb of BigInteger is ele[nEle - 1]*/
	u8 *ele;
	int nEle;
	int nEleMax; 
};

struct BigInteger *scaleBigInteger(struct BigInteger *b, size_t n){
	assert(NULL != b);
	b->nEleMax = n;
	b->ele = (u8 *) realloc(b->ele, b->nEleMax);
	assert(NULL != b->ele);
	return b;
}

struct BigInteger *newBigInteger(){
	struct BigInteger *b;
	b = (struct BigInteger *) malloc(sizeof(struct BigInteger));
	assert(NULL != b);
	b->ele = NULL;
	scaleBigInteger(b, 256); /*default range: 0 ~ 10^256 - 1*/
	memset(b->ele, 0, b->nEleMax);
	b->nEle = 1;
	return b; 
}

struct BigInteger *newBigIntegerByString(char s[]){
	struct BigInteger *b;
	size_t len, i, j;	
	b = newBigInteger();
	assert(NULL != b);
	assert(NULL != s);
	
	len = strlen(s);
	if(len > b->nEleMax){
		scaleBigInteger(b, len);
	} 
	for(i=0, j = len - 1; i < len; i++, j--){
		b->ele[i] = s[j] - '0'; 
	}
	b->nEle = len;
	return b;
}

char *printBigInteger(struct BigInteger *b, char output[], size_t oLen){
	int i,j;
	assert(NULL != output);
	assert(NULL != b);
	
	assert(oLen >= b->nEle);
	for(i=0, j = b->nEle-1; j >= 0; i++, j--){
		output[i] = b->ele[j] + '0';
	}
	output[b->nEle] = '\0';
	return output;
}

int main(){
	char *x="7612058254738945";
	long long y=9263591128439081;
	struct BigInteger *a, *b, *c;
	char s[1000];
	a = newBigIntegerByString(x);
	printBigInteger(a, s, 1000);
	puts(s);
	return 0;
}