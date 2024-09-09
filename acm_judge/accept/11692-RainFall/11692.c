#include <stdio.h>
#include <math.h>

int main(){
	short nTest;
	double L, T1, T2, K, H;
	double a, b, c;
	double r;
	double max, min;
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf %lf %lf %lf %lf", &L, &K, &T1, &T2, &H);
		if(H < L){
			printf("%.6lf %.6lf\n", H, H);
			continue;
		}
		
		a = T1;
		b = -(H + (T1 + T2)*K);
		c = L*K;
		r = (-b + sqrt(b*b - 4*a*c))/(2*a);
		max = r*T1;
		if(H == L){
			printf("%.6lf %.6lf\n",H, max);
			continue;
		} 
		printf("%.6lf %.6lf\n",max, max);
	}
	return 0;
}