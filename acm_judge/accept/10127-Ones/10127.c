#include <stdio.h>

int main(){
	int count;
	int n, mod;

	while(1 == scanf("%d",&n)){
		
		if(n == 0){
			puts("0");
			continue;				
		}
		if(n == 1){
			puts("1");
			continue;
		}
		count = 1;
		mod = 1;
		while(mod != 0){
			count++;
			mod = ( (mod << 3) + (mod << 1) + 1) % n;
		}
		printf("%d\n",count);
	}	
	return 0;
}