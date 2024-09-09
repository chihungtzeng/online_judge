#include <stdio.h>
#include <string.h>
#define MAX 100001
#define QSIZE 1001

char haystack[MAX];
char needle[QSIZE];

int isPrefix(){
	int len, i;
	len = strlen(needle);
	for(i=0; i<len; i++){
		if(haystack[i] != needle[i]) return 0;
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
		for(i=0; i<nQuery; i++){
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