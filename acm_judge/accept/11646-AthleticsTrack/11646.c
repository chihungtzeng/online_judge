#include <stdio.h>
#include <math.h>

int main(){
	double r, theta, L, W, x; /*L = a*x, W = b*x*/
	short a, b, aplusb;
	short k = 1;	
	char sep[2];

	while(3 == scanf("%hd %s %hd", &a, sep, &b)){
		r = hypot(a, b)/2.0;
		theta = acos(1 - b*b/(2*r*r));
		x = 400.0/(theta*hypot(a, b) + a + a);
		L = a*x;
		W = b*x;
		
		printf("Case %hd: %.10lf %.10lf\n",k++, L, W);
	}	
	
	return 0;
}