#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>
#define LEN 2048
#define HYPHEN 1
#define REGULAR 0

int compareString(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int chomp(char *output, char *s){
	/*remove heading and trailing '.', ':', etc*/
	int head = 0, tail = 0;
	int ret = REGULAR;
	tail = strlen(s);
	while((tail > 0) && (!isalpha(s[tail - 1]))){
		if(s[tail - 1] == '-') {
			ret = HYPHEN;
			s[tail - 1] = '\0';
			break;
 		} else {
			s[tail - 1] = '\0';
			tail--;
		}
	}
	while( (head < tail) && (!isalpha(s[head]))){
		head++;
	}
	sprintf(output, "%s", s + head);
	
	return ret;
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
	if((way == leaf) || (way == postorder)){
		char *s;
		s = *(char **)rootp;
		puts(s);
	}
}

int main(){
	char line[LEN], *tok, output[LEN];
	char line[500][LEN];
	char isSOL; /*start of line*/
	void *root = NULL;
	char *buf;
	FILE *fp = stdin;

	while(NULL != fgets(line, LEN, fp)){
		tok = strtok(line, " \t");
		isSOL = 1;
		while(tok != NULL){
			if(isSOL && isHYPHEN){
				strcat(buf, tok);
			} else{
				is
			}
		}
	}	
	tdestroy(root, free);
	return 0;
}
