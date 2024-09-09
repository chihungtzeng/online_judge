#include <stdio.h>
#include <math.h>


int main(){
	char type;
	int k=1;
	double u, v, t, s, a,x;
	while(1 == scanf("%hhd", &type)){
		if(type == 0) return 0;
		if(type == 1){
			scanf("%lf %lf %lf", &u, &v, &t);
			a = (v - u)/t;
			s = (v*v - u*u)/(2*a);
			printf("Case %d: %.3lf %.3lf\n",k++, s, a);
		}
		else if (type == 2){
			scanf("%lf %lf %lf", &u, &v, &a);
			t = (v - u)/a;
			s = (v*v - u*u)/(2*a);
			printf("Case %d: %.3lf %.3lf\n",k++, s, t);
		}
		else if (type == 3){
			scanf("%lf %lf %lf", &u, &a, &s);
			v = sqrt(u*u + 2*a*s);
			t = (v -u)/a; 
			printf("Case %d: %.3lf %.3lf\n",k++, v, t);
		}
		else {
			scanf("%lf %lf %lf", &v, &a, &s);
			u = sqrt(v*v - 2*a*s);
			t = (v - u)/a;
			 
			
			printf("Case %d: %.3lf %.3lf\n",k++, u, t);
		}
	}
	return 0;
}