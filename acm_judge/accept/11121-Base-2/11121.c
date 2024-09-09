#include <stdio.h>
#define LEN 64
#define PLUS 1
#define MINUS 0

void base_2(char output[], int n){	
	int len = 0, i, j;
	int b;
	int flag = PLUS;
	if(n == 0){
		output[0] = '0';
		output[1] = '\0';
		return ;
	}
	
	while(n != 0){
		b = abs(n) % 2;		
		output[len++] = b + '0';
		if(flag == PLUS){
			n = (n - b)/2;
		} else{
			n = (n + b)/2;
		}
		flag = 1 - flag;
	}
	output[len] = '\0';
	for(i=0, j = len - 1; i < j; i++, j--){
		output[i] = output[i] ^ output[j];
		output[j] = output[i] ^ output[j];
		output[i] = output[i] ^ output[j];
	}
	return ;
}

int main(){
	int n, nTest, k = 1;
	scanf("%d", &nTest);
	char output[LEN];
	while(nTest--){
		scanf("%d", &n);
		base_2(output, n);
		printf("Case #%d: %s\n", k++, output);
	}
	return 0;
}