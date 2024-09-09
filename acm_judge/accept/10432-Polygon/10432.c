#include <stdio.h>
#include <math.h>

int main(){
	double radius;
	const double PI2 = 2 * M_PI;
	short nSide;
	while(2 == scanf("%lf %hd", &radius, &nSide)){
		printf("%.3lf\n", radius * radius * sin(PI2/nSide) * nSide / 2);
	}
	return 0;
}