#include <stdio.h>
#include <math.h>

int main(){
	int nTest, k=1;
	double x, a, b, c;
	double AB, CD, AD, BC;
	double AE, BF;
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf %lf %lf %lf", &AB, &CD, &AD, &BC);
		a = AB + CD;
		b = 2*(AB - CD);
		c = -a;
		x = (-b + sqrt(b*b - 4*a*c)) / (2*a);
		AE = AD * x/(x+1);
		BF = BC * x/(x+1);
		/*printf("x=%lf\n",x);*/
		printf("Land #%d: %.6lf %.6lf\n", k++, AE, BF);
	}
	return 0;
}