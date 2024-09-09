#include <stdio.h>
#include <string.h>
#define LEN 32

long getAns(char line[]){
	long ans=0, coef = 2;
	short i;
	
	
	for(i = strlen(line) - 1; i>=0; i--){
		ans += (line[i] - '0')* (coef - 1);
		coef = coef << 1;
	}
	return ans;
}

int main(){
	char line[LEN];
	
	while(1 == scanf("%s",line)){
		if(line[0] == '0') return 0;
		
		printf("%ld\n", getAns(line));
	}
	return 0;
}