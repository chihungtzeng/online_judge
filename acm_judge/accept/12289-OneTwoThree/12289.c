#include <stdio.h>
#include <string.h>
#define LEN 8


int decide(char token[]){
	char ONE[] = "one";
	int nWrong = 0, i;
	/*check if token is "one"*/
	for(i=0; i<3; i++){
		if(token[i] != ONE[i]){
			nWrong++;
		}
	}
	if(nWrong <= 1) return 1;
	else return 2;
}

int main(){
	int nTest;
	char token[LEN];	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%s", token);
		if(strlen(token) > 3) printf("%d\n", 3);
		else printf("%d\n", decide(token));
	}
	return 0;
}