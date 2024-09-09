#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

void solve(char line[LEN]){
	char *tok;
	char firstChar;
	
	tok=strtok(line, " \n");
	firstChar = tolower(tok[0]);
	while(NULL != (tok = strtok(NULL, " \n"))){
		if(tolower(tok[0]) != firstChar){
			printf("N\n");
			return ;
		}
	}
	printf("Y\n");
}

int main(){
	char line[LEN];
	FILE *fp = stdin;
	
	while(NULL != fgets(line, LEN, fp)){
		if(line[0] == '*') break;
		else solve(line);
	}	
	
	return 0;	
}