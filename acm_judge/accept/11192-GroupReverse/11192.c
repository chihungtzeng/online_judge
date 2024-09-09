#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define DEBUG 0

short nGroup;

void reverse(char *s, short gSize){
	short i, j;
	for(i = gSize/2 - 1; i>=0; i--){
		j = gSize - 1 - i;
		s[i] = s[i] ^ s[j];
		s[j] = s[i] ^ s[j];
		s[i] = s[i] ^ s[j];
	}
}

char *groupReverse(char *input){
	short gSize, i;
	char *group;
	char *output;
	
	gSize = strlen(input)/nGroup;
	output = (char *) malloc(sizeof(char)*MAX);
	output[0] = '\0';
	for(i=0; i<nGroup; i++){
		group = strndup(input + i*gSize, gSize);
		if(DEBUG){
			printf("group:%s\n", group);
		}
		reverse(group, gSize);
		strcat(output, group);
		free(group);
	}
	
	return output;
}

int main(){
	char line[MAX];
	char *output;
	while(1 == scanf("%hd",&nGroup)){
		if(nGroup == 0){
			break;
		}
		else {
			scanf("%s", line);
			output = groupReverse(line);
			printf("%s\n",output);
			free(output);
		}
	}
	return 0;
}
