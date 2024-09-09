#include <stdio.h>
#include <stdlib.h>
#define MAX 1000005


char add(char a[], char b[], size_t len){
	int i;
	char carry = 0;
	for(i=len - 1; i>=0; i--){
		a[i] = a[i] + b[i] + carry;
		carry = a[i] / 10;
		a[i] = a[i] % 10;
	}
	for(i=len - 1; i>=0; i--){
		a[i] += '0';
	}
	return carry;
}

int main(){
	int nTest;
	char *a, *b, first = 1;
	char s[2], t[2];
	size_t len;
	char carry;
	int i;
	a = (char *) malloc(sizeof(char)*MAX);
	b = (char *) malloc(sizeof(char)*MAX);
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%ld", &len);
		for(i=0; i < len ; i++){
			scanf("%s %s", s, t);
			a[i] = s[0] - '0';
			b[i] = t[0] - '0';
		}
		a[len] = '\0';
		b[len] = '\0';
		carry = add(a, b, len);
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		
		if(carry > 0) printf("%c",carry + '0');
		puts(a);
	}
	
	free(a);
	free(b);
	return 0;
}
