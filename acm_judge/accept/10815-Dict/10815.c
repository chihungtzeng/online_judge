#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 200
#define READWORD 1
#define READDELIM 2

int compareString(const void *a, const void *b){
	char *s, *t;
	s = (char *)a;
	t = (char *)b;
	return strcmp(s, t);
}

void twalkAction(const void *nodep, const VISIT whichWay, const int depth){
	char *s;
	if((whichWay == leaf) || (whichWay == postorder)){
		s = *(char **) nodep;
		printf("%s\n",s);
	}
} 

int main(){
	void *root;
	char input[MAX], *s;
	char c, state = READDELIM;
	short count = 0;
	
	root = NULL;
	while(EOF != (c = getchar())){
		if((state == READDELIM) && isalpha(c)){
			input[0] = tolower(c);
			count = 1;
			state = READWORD;
		}
		else if ((state == READWORD) && isalpha(c)){
			input[count++] = tolower(c);
		} 
		else if ((state == READWORD) && !isalpha(c)){
			input[count] = '\0';
			s = strdup(input);
			tsearch(s, &root, compareString);
			count = 0;
			state = READDELIM;
		}
	}
	twalk(root, twalkAction);
	tdestroy(root, free);
	return 0;
}