#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 512
#define POSITIVE 1
#define NEGATIVE (-1)
#define VARIABLE 0
#define CONSTANT 1
#define DEBUG 0

int solve(char equation[LEN]){
	int C = 0;
	int a = 0;
	int coef, amount, tokenType;
	char *pos;
	char *tok;
	int ans;
	char neweq[LEN];
	/*refine the equation into a*x + C = 0*/

	/*move all the items into left-hand side*/
	tok = equation;
	while(*tok != '=') tok++;	
	
	*tok = '\0';
	
	strcpy(neweq, equation);
	pos = tok + 1;
	while(*pos != '\0'){
		if(*pos == '+') *pos = '-';
		else if (*pos == '-') *pos = '+';
		else if (*pos == '\n') *pos = '\0';
		
		pos++;
	}
	*tok='-';
	strcat(neweq, tok);	
	
	/**/
	pos = neweq;
	coef = POSITIVE;
	tokenType = CONSTANT;
	amount = 0;	
	while(*pos != '\0'){	
		if((*pos == '+') && (tokenType == CONSTANT)){
			C = C + coef * amount;
			amount = 0;
			coef = POSITIVE;
			tokenType = CONSTANT;
		} else if ((*pos == '+') && (tokenType == VARIABLE)){
			a = a + coef * amount;
			amount = 0;
			coef = POSITIVE;
			tokenType = CONSTANT;
		} else if ( (*pos == '-') && (tokenType == CONSTANT)){
			C = C + coef * amount;
			amount = 0;
			coef = NEGATIVE;
			tokenType = CONSTANT;
		} else if ( (*pos == '-') && (tokenType == VARIABLE)){
			a = a + coef * amount;
			amount = 0;
			coef = NEGATIVE;
			tokenType = CONSTANT;
		} else if (isdigit(*pos)){
			amount = (amount * 10) + *pos - '0';
		} else if (*pos == 'x'){
			tokenType = VARIABLE;
			if(amount == 0) amount = 1;
		}
			
		pos++;
	} 
	if(amount != 0){
		if(tokenType == CONSTANT){
			C = C + coef * amount;
		} else {
			a = a + coef * amount;
		}
	}
	#if 0
	printf("eq=%s a=%d C=%d\n", neweq, a, C);
	#endif

	if((a == 0) && (C != 0)){
		printf("IMPOSSIBLE\n");
	}
	else if( (a == 0) && (C == 0)){
		printf("IDENTITY\n");
	}	
	else {
		ans = -C / a;
		if(a*C > 0){
			ans--;
		}
		printf("%d\n", ans);
	}
	return EXIT_SUCCESS;
}


int main(){
	char line[LEN];
	int nTest;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	fgets(line, LEN, fp);
	nTest = atoi(line);
	
	while(nTest--){
		fgets(line, LEN, fp);
		solve(line);
	}	
	
	return 0;
}