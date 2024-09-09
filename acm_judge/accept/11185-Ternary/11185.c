#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char *ternary(int n){
	char *output;
	char idx = 0, remainder, i, j;
	output = (char *) malloc(sizeof(char)*MAX);
	while(n > 0){
		remainder = n % 3;
		output[idx++] = remainder + '0';
		n = n/3;
	}
	if(idx == 0){
		output[idx++] = '0';
	}
	output[idx] = '\0';
	for(i=0; i<idx/2; i++){
		j = idx - 1 -i;
		output[i] = output[i] ^ output[j];
		output[j] = output[i] ^ output[j];
		output[i] = output[i] ^ output[j];
	}
	return output;
}

int main(){
	int n;
	char *output;
	
	while(1){
		scanf("%d", &n);
		if(n < 0){
			break;
		}
		output = ternary(n);
		printf("%s\n", output);
		free(output);
	}
	return 0;
}