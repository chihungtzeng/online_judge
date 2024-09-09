#include <stdio.h>
#define MAX 16

int main(){
	int k, n, i;
	int ans[MAX];
	ans[1] = 3;
	ans[2] = 11;
	for(i=3; i<=15; i++){
		ans[i] = (ans[i - 1] << 2) - ans[i-2];
	}
	while(1 == scanf("%d",&n)){
		if(n == -1) break;
		
		if(n == 0) puts("1");
		else if(n & 1) puts("0");
		else printf("%d\n",ans[n >> 1]);
	}
	return 0;
}