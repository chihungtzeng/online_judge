#include <stdio.h>
#include <math.h>

enum {
	XA, YA, XB, YB
};

int main(){
	int n, pos[4];
	double theta;
	double radius, area;
	while(5 == scanf("%d %d %d %d %d", pos + XA, pos + YA, pos + XB, pos + YB, &n)){
		if((n == 0) && (pos[XA] == 0) && (pos[YA] == 0) && (pos[XB] == 0) && (pos[YB] == 0)){
			break;
		}
		theta = (M_PI*2.0)/n;
		radius = hypot(pos[XA] - pos[XB], pos[YA] - pos[YB])/2.0;
		area = n * radius * radius * sin(theta) / 2.0;
		printf("%.6lf\n", area);
	}
	return 0;
}