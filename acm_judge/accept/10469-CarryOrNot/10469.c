#include <stdio.h>

int main(){
	unsigned int x, y;
	while(2 == scanf("%u %u", &x, &y)){
		x = x ^ y;
		printf("%u\n",x);
	}
	return 0;
}