#include <stdio.h>

int joseph(int n){
	if (n == 1) return 1;
	if (!(n & 1)) return (joseph(n >> 1) << 1) - 1;
	else return (joseph(n >> 1) << 1) + 1;
}

int main(){
	int input, ans;
	
	while(1){
		scanf("%d",&input);
		if(input == 0){
			break;
		}
		ans = joseph(input) - 1;
		if (ans == 0){
			ans = input;
		}
		printf("%d\n",ans);
	}
	return 0;
}