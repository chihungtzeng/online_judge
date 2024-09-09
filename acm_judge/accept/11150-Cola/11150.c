#include <stdio.h>

int main(){
	short n, ans;
	while(1 == scanf("%hd",&n)){
		ans = n;
		while(n >= 3){
			ans += n/3;
			n = n/3 + (n % 3); 
		}
		if(n == 2) ans++;
		printf("%hd\n",ans);
	}
	return 0;
}