#include <stdio.h>
#include <math.h>
#define C8 9.2938100461631059
#define C11 10.7300879388486585

int main(){
	short nTest;
	double r, s8, s11;
	double c8, c11;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf",&r);
		s8 = C8 * r;
		s11 = C11 * r;
		printf("%.10lf %.10lf\n",s8, s11);
	}
	/*
	c8 = 2.0 * (sqrt(3.0) + 1.0 + sqrt(11.0 / 3.0));
	c11 = 2.0 * (sqrt(3.0) + 2.0 + 4.0 / sqrt(6.0));
	printf("%.16lf %.16lf\n",c8,c11);
	*/
	return 0;
}