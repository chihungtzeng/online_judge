#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 65536
#define WORD 1
#define DELIM 0

int main(){
	char line[MAX];
	char *tok, *ch;
	int count, i;	
	char newWord, state;
	
	while(NULL != fgets(line,MAX,stdin)){
		count = 0;
		ch = line;
		state = DELIM;
		
		
		
		while(*ch != '\0'){
			if(isalpha(*ch) && (state == DELIM)){
				state = WORD;
				count++;
			}
			else if (!isalpha(*ch) && (state == WORD)){
				state = DELIM;
			}
			ch++;
		}
		
		printf("%d\n", count);
		
	}
	return 0;
}
