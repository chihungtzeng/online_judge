#include <stdio.h>
#include <math.h>

int main(){
	short n;
	while(1 == scanf("%hd",&n)){
		if(0 == n) break;
		
		printf("%d\n", (int)log2(n));
	}
	return 0;
}