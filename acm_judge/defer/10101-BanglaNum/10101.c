#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 19

void reverse(char *s){
	int len,i;
	char ch;
	len = strlen(s);
	for(i=0;i<len/2;i++){
		ch = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] =ch; 
	}
}

int main(){
	char s[MAXCHAR];
	char salign[MAXCHAR];
	int sn;
	int offset;
	int i;
	FILE *fp;
	char kuti[MAXCHAR],lakh[MAXCHAR],hajar[MAXCHAR],shata[MAXCHAR];
	
	fp = stdin;
	sn = 1;
	while(NULL != (fgets(s,MAXCHAR,fp))){
		s[strlen(s)-1] = '\0';
		offset = MAXCHAR - strlen(s) - 1;
		for(i=0;i<=strlen(s);i++){
			salign[offset+i] = s[i];
		}
		for(i=0;i<offset;i++){
			salign[i] = '0';
		}
		printf("%s\n",salign);
	}
}