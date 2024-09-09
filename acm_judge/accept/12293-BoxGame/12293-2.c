#include <stdio.h>


int main(){
	int n;
	while(1 == scanf("%d", &n)){
		if(n == 0) break;
		
		if( (n & (n + 1)) == 0){
			puts("Bob");
		} else {
			puts("Alice");
		}
	}
	return 0;
}