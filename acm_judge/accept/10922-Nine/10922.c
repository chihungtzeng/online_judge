#include <stdio.h>
#define MAX 1005


short findRdepth(short dsum){
	short newDSum = 0;
	if(dsum == 9){
		return 1;
	}
	while(dsum > 0){
		newDSum += dsum % 10;
		dsum = dsum / 10;
	}
	return 1 + findRdepth(newDSum);
}

int main(){
	char input[MAX];
	char *c;
	short dsum;
	while(1){
		scanf("%s", input);
		if((input[0] == '0') && (input[1] == '\0')){
			break;
		} 
		c = input;
		dsum = 0;
		while(*c != '\0'){
			dsum += *c - '0';
			c++;
		}
		if(dsum % 9 != 0){
			printf("%s is not a multiple of 9.\n", input);
		}
		else {
			printf("%s is a multiple of 9 and has 9-degree %hd.\n", input, findRdepth(dsum));
		}
	}
	return 0;
}