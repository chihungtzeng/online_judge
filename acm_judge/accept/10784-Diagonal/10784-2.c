#include <stdio.h>
#include <math.h>


int main(){
	long long nEdge;
	double ans;
	short k=1;
	while(1 == scanf("%lld",&nEdge)){
		if(0 == nEdge){
			break;
		}
		ans = (3 + sqrt(9 + nEdge*8))/2;
		ans = ceil(ans);
		printf("Case %hd: %0.lf\n",k++, ans);
	}
	return 0;
}