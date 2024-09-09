#include <stdio.h>
#include <string.h>
#define MAX 100001
#define QSIZE 1001

char haystack[MAX];
char needle[QSIZE];

int isPrefix(){
	char *hc, *nc;
	hc = haystack;
	nc = needle;
	while(*nc != '\0'){
		if(*nc != *hc) return 0;
		nc++;
		hc++;
	}
	return 1;
}

int main(){
	
	short nTest, nQuery, i;
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s", haystack);
		scanf("%hd",&nQuery);
		for(i=nQuery; i>=1; i--){
			scanf("%s", needle);
			if(isPrefix()){
				printf("y\n");
			} 
			else{
				printf("n\n");
			}
		}
	}
	return 0;
}