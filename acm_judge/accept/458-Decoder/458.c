#include <stdio.h>

int main(){
	char c;
	
	while(EOF != (c = getchar())){
		if((c != 10) && (c != 13)){
			printf("%c", c-7);
		}
		else{
			printf("%c",c);
		}
	}
	return 0;
}