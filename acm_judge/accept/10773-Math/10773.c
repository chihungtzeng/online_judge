#include <stdio.h>
#include <math.h>

int main(){
	double d, v, u, sintheta, t;
	short nTest, k=1;
	scanf("%hd", &nTest);
	while(k <= nTest){
		scanf("%lf %lf %lf",&d, &v, &u);
		if((v >= u) || (v == 0) || (u == 0)){
			printf("Case %hd: can't determine\n",k++);
		}
		else{
			sintheta = sqrt(1 - (v/u)*(v/u));
			t = (d/u)*(1/sintheta - 1);
			printf("Case %hd: %.3lf\n",k++,t);
		}
	}
	return 0;
}