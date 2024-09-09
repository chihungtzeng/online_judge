#include <stdio.h>
#include <math.h>

long int gcd(long int a, long int b){
	if( b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
	long int a, b, c, d, c_, d_;
	long int m;
	double error, interval, frac;
	long int g, max, i, diff, inv;
	short done;
	

	while(3 == scanf("%ld %ld %lf", &a, &b, &error)){
		done = 0;
		inv = (long int) 1 /error;
		/*printf("a=%ld, b=%ld, inv=%ld\n",a, b, inv);*/
		g = gcd(a,b);
		a = a/g;
		b = b/g;
		for(m=2;(!done) ; m++){
			c = a*m + 1;
			d = b*m;
			g = gcd(c, d);
			c = c/g;
			d = d/g;
			
			if( c*b*inv - a*d*inv <= d*b ){
				done = 1;
			}
		}
		
		done = 0;
		d_ = 1;
		
		/*printf("c=%ld d=%ld\n",c, d);*/
		while (!done){
			c_ = (d_ * b + a * d_ * inv) / (inv * b);
			if ( ((c_ > 0) && (b *c_ > d_ * a)) || (d_ >= d)){
				done = 1;
			}
			d_ += 1;
		}
		if ((c_ > 0) && (d_ < d)){
			d = d_ - 1;
			c = c_;
		}
		

		printf("%ld %ld\n",c, d);
	}
	return 0;
}