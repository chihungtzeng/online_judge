#include <stdio.h>
#include <string.h>
#define LEN 102

char period[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
char periodPattern[][4] = {
	{0},
	{1},
	{6, 2, 4, 8},
	{1, 3, 9, 7},
	{6, 4},
	{5},
	{6},
	{1, 7, 9, 3},
	{6, 8, 4, 2},
	{1, 9}
};

char smooth_mod(char input[], char p){
	char len = strlen(input);
	char i = 0;
	char result = 0;
	for(i=0; i<len; i++){
		input[i] -= '0';
	}
	for(i=0; i<len; i++){
		result = result * 10 + input[i];
		result = result % p;
	}
	return result;
}



int main(){
	int nTest;
	char base[LEN], expn[LEN];
	char bb, ell;
	while(2 == scanf("%s %s", base, expn)){
		if( (base[0] == '0') && (expn[0] == '0')){
			return 0;
		}		
		bb = base[strlen(base) - 1] - '0';
		if(period[bb] == 1){
			printf("%hhd\n", bb);
			continue;
		}
		if(expn[0] == '0'){
			puts("1");
			continue;
		}
		
		ell = smooth_mod(expn, period[bb]);
		/*printf("bb=%hhd, ell=%hhd\n", bb, ell);*/
		printf("%hhd\n", periodPattern[bb][ell]);
	}
	return 0;
}