#include <stdio.h>

int main(){
	short nTest;
	int n;
	scanf("%hd",&nTest);
	
	while(nTest >= 1){
		nTest--;
		scanf("%d", &n);
		n = 315*n + 36962;
		if(n < 0){
			n = ~n + 1;
		}
		printf("%d\n", (n/10) % 10);
	}
	
	return 0;
}