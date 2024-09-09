#include <stdio.h>
#include <math.h>

double alpha(double beta){
	double t;
	t = cos(beta);
	return log(2 - t + sqrt(3 + t * (t - 4)));
}

double calc(int x, int y, double beta){
	double a = alpha(beta);
	double val;
	val = (1.0 - 1/exp(x*a)*cos(y*beta))/sinh(a);
	return value; 
}

int main(){
	int x, y;
	double ans;
	while(2 == scanf("%d %d", &x, &y)){
		ans = calc(x, y);
		
	}
}