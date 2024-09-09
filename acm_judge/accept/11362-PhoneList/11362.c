#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 11
#define MAX 10001
#define PREFIX 1

char phoneNum[MAX][LEN];
short nPhoneNum;

int compareString(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int isPrefix(){
	short i;
	char *pre, *cur;
	for(i=1; i<nPhoneNum; i++){
		pre = phoneNum[i-1];
		cur = phoneNum[i];
		if(strncmp(pre, cur, strlen(pre)) == 0) return PREFIX;  
	}
	return ~PREFIX;
}

int main(){
	char nTest;
	short i;
	scanf("%hhd", &nTest);
	while(nTest){
		nTest--;
		scanf("%hd", &nPhoneNum);
		for(i=0; i<nPhoneNum; i++){
			scanf("%s", phoneNum[i]);
		}
		qsort(phoneNum, nPhoneNum, LEN, compareString);
		if(PREFIX == isPrefix()){
			puts("NO");
		} else {
			puts("YES");
		}
	}
	return 0;
}