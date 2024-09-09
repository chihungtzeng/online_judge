#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 4096
#define DEBUG 0
#define READWORD 1
#define READSPACE 0

void pigLatin(char word[], size_t len){
	char firstch;
	size_t i;
	firstch = tolower(word[0]);
	if(!((firstch == 'a') || (firstch == 'e') || 
		(firstch == 'i') || (firstch == 'o')|| (firstch == 'u'))){
		for(i=1; i<len; i++){
			printf("%c", word[i]);
		}
		printf("%c", word[0]);
		printf("ay");
	}
	else{
		for(i=0; i<len; i++){
			printf("%c",word[i]);
		}
		printf("ay");
	}
}

int main(){
	char word[LEN];
	char state = READSPACE;
	char ch;
	size_t len = 0;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	while(EOF != (ch = fgetc(fp))){
		if((state == READWORD) && (isalpha(ch))){
			word[len++] = ch;
		}
		else if ((state == READWORD) && (!isalpha(ch))) {
			pigLatin(word, len);
			printf("%c", ch);
			state = READSPACE;
		}
		else if ((state == READSPACE) && (isalpha(ch))){			
			word[0] = ch;
			len = 1;
			state = READWORD;
		}
		else{
			printf("%c", ch);
		}
	}
	
	return 0;
}