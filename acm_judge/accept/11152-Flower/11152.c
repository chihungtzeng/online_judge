#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c;
	double tArea;
	double r, R;
	double s;
	double sunflower, rose, violet;
	
	while(3 == scanf("%lf %lf %lf", &a, &b, &c)){
		s = (a + b + c)/2;
		tArea = sqrt(s*(s-a)*(s-b)*(s-c));
		r = tArea / s ;
		R = a*b*c/(4*tArea);
		sunflower = M_PI * R * R - tArea;
		rose = M_PI * r * r;
		violet = tArea - rose;
		printf("%.4lf %.4lf %.4lf\n",sunflower, violet, rose);
	}
	return 0;
}