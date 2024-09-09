#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#define LINELEN 256

short freq[MAX];


int main(){
	int nTest;
	char line[LINELEN];
	FILE *fp;
	char *c;
	short max, i, index;
	fp = stdin;
	
	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		memset(freq, 0, sizeof(short)*MAX);
		fgets(line, LINELEN, fp);
		c = line;
		while(*c != '\0'){
			if(islower(*c) || isupper(*c)){
				
				*c = tolower(*c);
				index = *c - 'a';
				freq[index] += 1;
			}
			c++;
		}
		max = 0;
		for(i=0; i<26; i++){
			if(freq[i] > max){
				max = freq[i];
			}
		}
/*		printf("max=%d\n",max);*/
		for(i=0; i<26; i++){
			if(freq[i] == max){
				printf("%c", i+'a');
			}
		}
		printf("\n");
	}
	return 0;
}