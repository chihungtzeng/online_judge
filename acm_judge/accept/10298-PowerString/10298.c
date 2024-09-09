#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000010
#define DEBUG 0

int findAns(char *s, int len){
	char *t1, *t2, *t3;
	int ans = 1;
	int result = 0;
	int tmp;

	if(len == 0) return 0;
	if(len == 1) return 1;
		
	
	if(len % 2 == 0){
		tmp = len >> 1;
		t1 = s;
		t2 = s + tmp;
		if(!memcmp(t1, t2, tmp)) {
			ans = 2*findAns(s, tmp);
		}
	}
	
	if(len % 3 == 0){
		tmp = len / 3;
		t1 = s;
		t2 = s + tmp;
		t3 = s + 2*tmp; 		
		
		if((!memcmp(t1, t2, tmp)) && (!memcmp(t2, t3, tmp))){
			result = 2*findAns(s, tmp) + 1;
		}
		if(result > ans){
			ans = result;
		}
	}
	return ans;
} 


int main(){
	char *s;
	int n, len;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	s = (char *) malloc(sizeof(char)*MAX);
	while(NULL != fgets(s, MAX, fp)){
		if((s[0] == '.')) break;
		
		len = strlen(s);
		s[len] = '\0';
		len--;
		printf("%d\n",findAns(s, len));
		
	}
	free(s);
	return 0;
}
