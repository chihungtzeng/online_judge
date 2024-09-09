#include <stdio.h>
#include <math.h>

inline double areaByPerimeter(double a, double b, double c){
	double hp; /*half of the perimeter*/
	hp = (a + b + c)/2;
	return sqrt(hp * (hp-a) * (hp - b) * (hp - c));
}

int main(){
	int nTest;
	double r1, r2, r3;
	double area;
	double a, b, c; /*The perimeter of the triangle ABC*/
	double A, B, C; /* 0 <= A, B, C <= 2*pi*/
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf %lf %lf", &r1, &r2, &r3);
		a = r2 + r3;
		b = r1 + r3;
		c = r1 + r2;
		A = acos((c*c + b*b - a*a)/(2*b*c));
		B = acos((a*a + c*c - b*b)/(2*a*c));
		C = acos((a*a + b*b - c*c)/(2*a*b));
		area = areaByPerimeter(a, b, c);
		area = area - M_PI*r1*r1*(A/(2*M_PI));
		area = area - M_PI*r2*r2*(B/(2*M_PI));
		area = area - M_PI*r3*r3*(C/(2*M_PI));
		printf("%.6lf\n", area);
	}
}