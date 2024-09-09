#include <stdio.h>

#define END 12

void intToBinary(char output[], int n){
	int i = END;
	while(i >= 0){
		output[i--] = (n & 1) + '0';
		n = n >> 1;
		
	}
}

int main(){
	int nTest;
	char op[2];
	int a, b, ans;
	char binary[2][16];
	binary[0][END + 1] = 0;
	binary[1][END + 1] = 0;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%X %s %X", &a, op, &b);
		if(op[0] == '+'){
			ans = a + b;
		} else {
			ans = a - b;
		}
		intToBinary(binary[0], a);
		intToBinary(binary[1], b);
		
		printf("%13s %c %13s = %d\n", binary[0], op[0], binary[1], ans);
	}
	
	return 0;
}