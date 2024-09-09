#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81

char map[10] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};

void decodeLine(char line[]){
	char *tok;
	char first = 1;
	char *p;
	tok = strtok(line, " ");
	while(tok != NULL){
		p = tok;
		if(first) first = 0;
		else printf(" ");
		
		while(*p != '\0'){
			if(isdigit(*p)){
				printf("%c", map[*p - '0']);
			}
			else{
				printf("%c", *p);
			}
			p++;
		}
		tok = strtok(NULL, " ");
	}
}

int main(){
	char nTest;
	char reading;
	char line[LEN];
	FILE *fp = stdin;
	
	fgets(line, LEN, fp); 
	
	while(NULL != fgets(line, LEN, fp)){
		decodeLine(line);
	}
	return 0;
}