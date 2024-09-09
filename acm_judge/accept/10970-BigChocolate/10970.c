#include <stdio.h>

int main(){
	short x, y;
	int z;
	while(2 == scanf("%hd %hd",&x, &y)){
		z = x * y - 1;
		printf("%d\n",z);
	}
	return 0;
}