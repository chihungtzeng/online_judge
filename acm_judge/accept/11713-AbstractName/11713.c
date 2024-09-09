#include <stdio.h>
#include <string.h>
#define MAX 21
#define YES 1
#define NO 0

char name[2][MAX];

int isVowel(char c){
	if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') )
		return YES;
	else return NO;
}

int isMutate(){
	short n0, n1, i;
	n0 = strlen(name[0]);
	n1 = strlen(name[1]);
	if(n0 != n1) return NO;
	/*if(strcmp(name[0], name[1]) == 0) return NO;*/
	
	for(i=0; i<n0; i++){
		if(isVowel(name[0][i]) && (!isVowel(name[1][i]))) return NO;
		if( (!isVowel(name[0][i])) && (isVowel(name[1][i]))) return NO;
		if( (!isVowel(name[0][i])) && (!isVowel(name[1][i])) && (name[0][i] != name[1][i])) return NO;
	}
	return YES;
}

int main(){
	short nTest;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s %s", name[0], name[1]);
		if(isMutate() == YES){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;	
}