#include <stdio.h>
#include <string.h>
#define LEN 256

char duration[LEN];

void buildTable(){
	duration['W'] = 64;
	duration['H'] = 32;
	duration['Q'] = 16;
	duration['E'] = 8;
	duration['S'] = 4;
	duration['T'] = 2;
	duration['X'] = 1;
}

void solve(char line[LEN]){
	int nRight = 0;
	char *tok;
	char *ptr;
	int nDuration;
	tok = strtok(line, "/");
	while(tok != NULL){
		
		if(!isalpha(*tok)) break;
		
		nDuration = 0;
		ptr = tok;
		while(*ptr != '\0'){
			nDuration += duration[*ptr];
			ptr++;
		}
		if(nDuration == 64) nRight++;
		tok = strtok(NULL, "/");
	}
	printf("%d\n", nRight);
}

int main(){
	char line[LEN];
	buildTable();
	while(1 == scanf("%s", line)){
		if(line[0] == '*') break;
		solve(line);
	}
	
	return 0;

}