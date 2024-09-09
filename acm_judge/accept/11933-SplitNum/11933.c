#include <stdio.h>

int main(){
	int input;
	int output[2];
	int mask, idx, i;
	while(1 == scanf("%d", &input)){
		if(input == 0) return 0;
		output[0] = 0;
		output[1] = 0;
		idx = 0;
		for(i=0; i<=30; i++){
			mask = 1 << i;
			if(input & mask){
				output[idx] |= mask;
				idx = 1 - idx;
			}
		}
		printf("%d %d\n",output[0], output[1]);
	}
	return 0;
}