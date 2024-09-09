#include <stdio.h>
#include <math.h>
/*
Let m1,m2,m3 be the length of the medians 
and let ms = (m1+m2+m3)/2.
The area of the traingle is 
(4/3) * sqrt(sm (sm-s1)(sm-s2)(sm-s3)  ) 
*/

int main(){
	double m1,m2,m3,ms;
	double area;
	while(3 == scanf("%lf %lf %lf",&m1,&m2,&m3)){
		ms = (m1+m2+m3)/2;
		if ((ms<=m1)||(ms<=m2)||(ms<=m3)){
			printf("-1.000\n");
		}
		else{
			area = (4.0/3.0) * sqrt(ms*(ms-m1)*(ms-m2)*(ms-m3));
			printf("%.3lf\n",area);
		}
	}
	return 0;
}