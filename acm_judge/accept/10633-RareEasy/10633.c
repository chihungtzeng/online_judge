#include <stdio.h>

int main(){
	long n_m, x, y;
	long ans[10], nAns;
	
	
	while(1 == scanf("%ld",&n_m)){
		if(0 == n_m) break;
		
		nAns = 0;
		for(y=9; y>=0; y--){
			x = (n_m - y) / 9;
			if( (x << 3) + x + y == n_m){
				ans[nAns++] = (x << 3) + (x << 1) + y;
			}
		}
		printf("%ld", ans[0]);
		for(y=1; y < nAns; y++){
			printf(" %ld",ans[y]);
		}
		printf("\n");
	}
	return 0;
}