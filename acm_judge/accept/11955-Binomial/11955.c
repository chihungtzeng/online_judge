#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 51
#define LEN 10000
#define LINELEN 128

long long coef[MAX][MAX];
char nTest, k=1;
char power, var[3][LINELEN];

void buildCoef(){
	short i, j;
	for(i=0; i<MAX; i++){
		for(j=0; j<=i; j++){
			if((j==0) || (j == i)) coef[i][j] = 1;
			else{
				coef[i][j] = coef[i-1][j-1] + coef[i-1][j];
			}
		}
	}
}

void getOneTerm(char *output, char *var, char i){
	if(i == 0) output[0] = 0;
	else if (i == 1) sprintf(output, "%s", var);
	else sprintf(output, "%s^%hhd", var, i);
	/*printf("output=%s, var=%s, i=%hhd\n", output, var, i);*/
} 

void genTerm(char *term, char i){
	char *sterm[2];
	char j = power - i;
	char x;
	size_t len;
	for(x=0; x<2; x++){
		sterm[x] = (char *) malloc(sizeof(char)*LEN); 
	}
	getOneTerm(sterm[0], var[0], i);
	getOneTerm(sterm[1], var[1], j);
	len = sprintf(term, "%s", sterm[0]);
	if(j>0){
		if(sterm[0][0] != '\0'){
			len += sprintf(term + len, "*");
		}
		sprintf(term + len, "%s", sterm[1]);
	}
	for(x=0; x<2; x++){
		free(sterm[x]); 
	}
}

void solve(){
	char i;
	char term[LEN];
	printf("Case %hhd: ",k++);
	for(i=power; i>=0; i--){
		if(coef[power][i] > 1) printf("%lld*", coef[power][i]);
		
		genTerm(term, i);
		printf("%s", term);
		if(i != 0){
			printf("+");
		}
	}
	printf("\n");
}

int main(){
	char line[LINELEN], *tok;
	char i, j;
	FILE *fp = stdin;
	buildCoef();
	
	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	while(nTest > 0){
		nTest--;
		fgets(line, LINELEN, fp);
		i = 1;
		
			j = 0;
			while(line[i] != '+') var[0][j++] = line[i++];
			var[0][j] = '\0';
			j = 0;
			i++;
			while(line[i] != ')') var[1][j++] = line[i++];
			var[1][j] = '\0';
			j = 0;
			i+=2;
			while(isdigit(line[i])) var[2][j++] = line[i++];
			var[2][j] = '\0';
		/*printf("%s %s %s\n", var[0], var[1], var[2]);*/
		power= atoi(var[2]);
		solve();
		/*
		for(i=0; i<3; i++){
			free(var[i]);
		}*/
	}
	
	return 0;
}