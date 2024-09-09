#include <stdio.h>

long gcd(long a, long b, long *x, long *y){
	long x_ = 1;
	long y_ = 0;
	long c, d;
	long q, r, t;	
	
	*x = 0; *y =1;
	c = a; d = b;
	while(1){
		q = c / d; 
		r = c % d;
		if (r == 0) break;
		c = d; d = r;
		t = x_; 
		x_ = *x; 
		*x = t - q * (*x);
		t = y_;
		y_ = *y;
		*y = t - q* (*y); 
	}
	return d;
}

int main(){
	long x, y, d, a, b;
	while(2 == scanf("%ld %ld", &a, &b)){
		if( b == 0){
			d = a;
			x = 1;
			y = 0;
		}
		else if (a == 0){
			d = b;
			x = 0;
			y = 1;
		}
		else {
			d = gcd(a, b, &x, &y);
		}

		printf("%ld %ld %ld\n",x, y, d);
	}	
	return 0;
}