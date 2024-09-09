#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16
#define ADDITION 1
#define MINUS 2

int main(){
	char line[MAX];
	char op,*pos;
	short a, b, c, nCorrect = 0;
	
	while(NULL != fgets(line, MAX, stdin)){
		pos = strrchr(line, '=');
		*pos = '\0';
		pos++;
		if (*pos == '?'){
			continue;
		}
		else {
			c = atoi(pos);
		}
		op = ADDITION;
		pos = strrchr(line, '+');
		if(pos == NULL){
			op = MINUS;
			pos = strrchr(line, '-');
		}
		*pos = '\0';
		pos++;
		a = atoi(line);
		b = atoi(pos);
		if((op == ADDITION) && (a + b == c)){
			nCorrect += 1;
		}
		else if ((op == MINUS) && (a - b == c)){
			nCorrect += 1;
		}
	}
	printf("%hd\n",nCorrect);
	return 0;
}