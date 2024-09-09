#include <stdio.h>
#include <math.h>
#define EPSILON 1e-12

int main(){
	short nTest;
	double r, s8, s11;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf",&r);
		s8 = 2.0 * (sqrt(3.0) + 1.0 + sqrt(11.0 / 3.0)) * r;
		s11 = 2.0 * (sqrt(3.0) + 2.0 + 4.0 / sqrt(6.0)) * r;
		printf("%.10lf %.10lf\n",s8, s11);
	}
	return 0;
}