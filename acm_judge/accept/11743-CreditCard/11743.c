#include <stdio.h>
#include <string.h>
#define MAX 20
#define VALID 0
#define NUM_DIGIT 16

char map[MAX];
char creditNum[17];


char digitSum(char n){
	char result = 0;
	while(n > 0){
		result += n % 10;
		n = n / 10;
	}
	return result;
}

void buildTable(){
	char i;
	for(i=0; i<MAX; i++){
		map[i] = digitSum(i);
	}
}

int check(){
	char i;
	int sum = 0;
	for(i=0; i<NUM_DIGIT; i++){
		creditNum[i] -= '0'; 
	}
	for(i=0; i<NUM_DIGIT; i += 2){
		sum += map[creditNum[i] * 2];
	}
	for(i=1; i<NUM_DIGIT; i += 2){
		sum += creditNum[i];
	}
	#if 0
	printf("sum=%d\n", sum);
	#endif
	if(sum % 10 == 0) return VALID;
	else return !VALID;
}

int main(){
	int i, nTest;
	buildTable();
	scanf("%d", &nTest);
	while(nTest--){
		for(i=0; i<4; i++){
			scanf("%s", creditNum + 4*i);
		}
		if(check() == VALID){
			puts("Valid");
		} else{
			puts("Invalid");
		}
	}
	return 0;
}