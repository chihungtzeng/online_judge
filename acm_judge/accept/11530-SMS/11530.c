#include <stdio.h>
#define MAX 101

short count[27];

void initCount(){
	short i;
	for(i=0; i<15; i++){
		count[i] = (i % 3) + 1;
	}
	for(i=15; i <19; i++){
		count[i] = i - 14;
	} 
	for(i=19; i<22; i++){
		count[i] = i - 18;
	}
	for(i=22; i<26; i++){
		count[i] = i - 21;
	}
	count[26] = 1;
}

int findAns(char *line){
	char *c;
	int map, ans=0;
	c = line;
	while((*c != '\0') && (*c != '\n')){
		if(*c == ' ') map = 26;
		else map = *c - 'a';
	
		ans += count[map];
		c++;
	}
	return ans;
}

int main(){
	short nTest, k=1;
	char line[MAX];
	gets(line);
	nTest = atoi(line); 
	initCount();
	while(k <= nTest){
		gets(line);
		printf("Case #%d: %d\n",k, findAns(line));
		k++;
	}
	return 0;
}