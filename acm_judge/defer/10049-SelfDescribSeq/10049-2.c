#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 200




int main(){
	long double phi, coef, result;	
	int n,i;
	int ans;	

	phi = (sqrtl(5) + 1) / 2;
	coef = powl(phi, 2-phi);

	
	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		result = (2 - phi)*log10l(phi) + (phi - 1)*log10l(n);
		ans = nearbyintl(pow(10, result));

		printf("%d\n",ans);
	}	

	return 0;
}