#include <stdio.h>

int main(){
	long long nBall, p, m, ans;
	short k = 1;
	while(1 == scanf("%lld", &nBall)){
		if(0 == nBall) break;
		p = nBall / 6;
		m = nBall % 6;
		ans = ((p-1)*p) >> 1; /*ans = 1+ 2+...+(p-1)*/
		ans = (ans << 2) + (ans << 1) + 1;
		if(m){
			ans += (m-1)*p + p - 1;
		}
		printf("Case %hd: %lld\n", k++, ans);
	}
	return 0;
}