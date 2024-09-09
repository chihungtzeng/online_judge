#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RIGHT 1
#define WRONG -1
#define MAX 1024
#define DEBUG 0

int check(char *s){
	char firstch, matchch;
	int i,j,count, len,result1, result2;
	char *s1, *s2;
	if(s == NULL){
		printf("null string\n");
		return WRONG;
	}

	if(strlen(s) == 0){
		return RIGHT;
	}
	firstch = s[0];
	if((firstch != '(' ) && (firstch != '[')){
		if(DEBUG){
			printf("the first char is illegal:%c the input string is \"%s\"\n", firstch, s);
		}
		return WRONG;
	} 
	matchch = (firstch == '(')? ')' : ']';
		
	
	len = strlen(s);
	i=1;
	count = 1;
	while((count != 0) && (i < len)){
		if(s[i] == firstch){
			count++;
		}
		else if(s[i] == matchch){
			count--;
		}
		i++;
	}
	if(DEBUG){
		printf("checking %s, count=%d, i=%d, len=%d\n",s,count, i,len);
	}
	if((i == len) && (count != 0)){
		return WRONG;
	}
	else if ((i == len) && (count == 0)){
		s1 = strndup(s+1, len -2);
		result1 = check(s1);
		free(s1);
		return result1;
	}
	else {
		s1 = strndup(s+1, i-2);
		s2 = strndup(s+i, len - i);
		result1 = check(s1);
		result2 = check(s2);
		free(s1);
		free(s2);
		if((result1 == WRONG) || (result2 == WRONG)){
			return WRONG;
		}
		else{
			return RIGHT;
		}
	}
}

int main(){
	int nTest;
	char line[MAX];
	char strip[MAX];
	FILE *fp;
	
	fp = stdin;
	fgets(line, MAX, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		int i, j, len;
		nTest--;
		fgets(line, MAX, fp);
		len = strlen(line);
		j=0;
		for(i=0; i<len; i++){
			if( (line[i] == '(')  || (line[i] == ')') || (line[i] == '[') || (line[i] == ']') ){
				strip[j++] = line[i];
			} 
		}
		strip[j] = '\0';
		if(DEBUG){
			printf("stripped input:%s\n",strip);
		}
		if(check(strip) == RIGHT){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}