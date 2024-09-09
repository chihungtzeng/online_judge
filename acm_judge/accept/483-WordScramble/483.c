#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

int myisspace(char c){
	if ((' ' == c) || ('\t' == c) || ('\n' == c)){
		return 1;
	}
	return 0;
}


int main(int argc, char *argv[]){
	char c,tmp;
	int len,i;
	char *s;
	

	s = (char *) malloc(sizeof(char)*MAX);
	len = 0;
	while (EOF != (c=getchar())){
		if (myisspace(c)){
			
			for(i=0;i<len/2;i++){
				tmp = s[i];
				s[i] = s[len -i -1];
				s[len -i - 1] =tmp;
			}			
			s[len] = '\0';
			printf("%s",s);
			printf("%c",c);
			len = 0;
			s[0] = '\0';
		}
		else {
			s[len] = c;
			len++;
		}
	}

	return 0;
}