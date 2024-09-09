#include <stdio.h>

int main(){
	short min, max, input;
	short nTest, nShop;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		min = 30000;
		max = 0;
		scanf("%hd", &nShop);
		while(nShop >= 1){
			nShop--;
			scanf("%hd",&input);
			if(input < min){
				min = input;
			}
			if(input > max){
				max = input;
			}
		}
		printf("%d\n", (max - min)*2);
	} 
	return 0;
}