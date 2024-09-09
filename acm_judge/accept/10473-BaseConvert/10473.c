#include <stdio.h>
#define LEN 16

int main(){
	unsigned int input;
	char line[LEN];
	while(1 == scanf("%s", line)){
		if(line[0] == '-'){
			return 0;
		}
		if(line[1] == 'x'){
			sscanf(line + 2, "%x", &input);
			printf("%d\n",  input);
		} else {
			input = atoi(line);
			printf("0x%X\n", input);
		}
	}
	return 0;
}