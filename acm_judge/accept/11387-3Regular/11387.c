#include <stdio.h>

int main(){
	short n, m, i;
	
	while(1){
		scanf("%hd", &n);
		if(n == 0){
			break;
		}
		
		if((n % 2 == 1) || (n < 4)){
			printf("Impossible\n");
			continue;
		}
		
		m = (n >> 1)*3;
		printf("%hd\n",m);
		
		
		for(i=1; i < n; i++){
			printf("%d %d\n", i, i+1);
		}
		printf("%d 1\n", n);
		for(i=1; i<=n/2; i++){
			printf("%d %d\n", i, i+ (n >> 1));
		}
	}
	return 0;
}