#include <stdio.h>

int main(){
	short n, k=1;
	short ans;
	while(1){
		scanf("%hd",&n);
		if(0 == n){
			break;
		}
		ans = n >> 1;
		printf("Case %hd: %hd\n",k++, ans);
	}
	return 0;
}