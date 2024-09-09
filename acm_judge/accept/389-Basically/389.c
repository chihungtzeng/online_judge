#include <stdio.h>
#include <string.h>

char map[128];

int findAns(char output[], char input[], char base, char newBase){
	int e=1, decimal=0;
	char len, i, nOutput=0;
	len = strlen(input);
	for(i=len-1; i>=0; i--){
		decimal += map[input[i]] * e;
		e = e*base;
	}
	/*printf("decimal = %d\n", decimal);*/
	i=0;
	while(decimal > 0){
		output[i] = (decimal % newBase);
		output[i] = (output[i] < 10)? output[i] + '0' : output[i] - 10 + 'A';
		i++;
		decimal = decimal / newBase;
	}
	if(i > 7) return -1;
	else if(i == 0){
		strcpy(output, "0");
		return 1;
	}
	else return i;
}

int main(){
	char output[16];
	char input[16];
	char base, newBase;
	char i, nOutput;
	for(i='0'; i<='9'; i++){
		map[i] = i - '0';
	}
	for(i='A'; i<='F'; i++){
		map[i] = i - 'A' + 10;
	}
	while(3 == scanf("%s %hhd %hhd",input, &base, &newBase)){
		nOutput = findAns(output, input, base, newBase);
		if(nOutput <= 0){
			puts("  ERROR");
		}
		else{
			for(i= 6 - nOutput; i>=0; i--){
				printf(" ");
			}
			for(i=nOutput-1; i>=0; i--){
				printf("%c",output[i]);
			}
			printf("\n");
		}
	}
	return 0;
}