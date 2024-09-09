#include <stdio.h>

int main(){
	long int n;
	
	while(1){
		scanf("%ld", &n);
		if(0 > n){
			break;
		}
		printf("%ld\n",(n*(n+1) >> 1) + 1);
	}
	return 0;
}