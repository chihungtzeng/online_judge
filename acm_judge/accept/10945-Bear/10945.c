#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int pruneChar(char *s, int len){
	int i, idx;
	idx = 0;
	for(i=0; i<len; i++){
		if(isalpha(s[i])){
			s[idx++] = tolower(s[i]);
		}
	}
	s[idx] = '\0';
	return idx;
}

int isPalindrome(char *s, int len){
	int i;
	for(i=0; i< (len >> 1); i++){
		if(s[i] != s[len - 1 - i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char line[MAX];
	char done;
	int len;
	FILE *fp;
	
	fp = stdin;
	done = 0;
	while(!done){
		fgets(line, MAX, fp);
		len = strlen(line);
		while(isspace(line[len - 1])){
			line[len - 1] = '\0';
			len--;
		}
		if(!strcmp(line, "DONE")){
			done = 1;
			continue;
		}
		len = pruneChar(line, len);
		if(isPalindrome(line, len)){
			printf("You won't be eaten!\n");
		}
		else{
			printf("Uh oh..\n");
		}
	}	
	
	return 0;
}
