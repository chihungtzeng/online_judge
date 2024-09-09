#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-12

short p, q, r, s, t, u;

double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

void solve(){
	double ans, preAns = -1;
	double left = 0, right = 1.0;
	double fans, fleft, fright;
	
	fleft = f(left);
	fright = f(right);
	if(fleft * fright > 0){
		puts("No solution");
		return ;
	}
	ans = (left + right) / 2.0;
	while(fabs(ans - preAns) > EPSILON){
		fans = f(ans);
		if(fans * fleft <= 0){
			right = ans;
		}
		else{
			left = ans;
		}
		preAns = ans;
		ans = (left + right)/2.0;
	}
	printf("%.4lf\n",ans);
}

int main(){
	while(6 == scanf("%hd %hd %hd %hd %hd %hd", &p, &q, &r, &s, &t, &u)){
		solve();
	}
	return 0;
}