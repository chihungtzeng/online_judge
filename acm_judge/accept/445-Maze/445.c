#include <stdio.h>
#include <stdlib.h>
#define LEN 1000


int main(){
	
	short nChar, i;
	char line[LEN], *ch;
	FILE *fp;
	
	fp = stdin;
	nChar = 0;
	while(NULL != fgets(line, LEN, fp)){
		ch = line;
		while ( '\0' != *ch){
			nChar = 0;
			while(isdigit(*ch)){
				nChar += *ch - '0';
				ch++;
			}
			for(i=nChar - 1; i>=0; i--){
				printf("%c", (*ch == 'b')? ' ' : *ch);
			}
			if(*ch == '!') printf("\n");
			ch++;
		}
		printf("\n");
	}	
	return 0;
}