#include <stdio.h>
#include <math.h>
#define EPSILON 1e-12

int main(){
	short nTest;
	double a, b, S, prob, area, totalArea, tmp;
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%lf %lf %lf", &a, &b, &S);
		
		
		totalArea = a*b;
		if(totalArea > S){
			tmp = (S <= 0)? 0 : logl(a) + logl(b) - logl(S) + 1.0; 
			prob = 1.0 - (S*tmp)/totalArea;
		} else {
			prob = 0;
		}
			
		
		#if 0
		printf("totalArea=%.20lf, tmp=%.20lf\n",totalArea, tmp);
		#endif
		
		prob = prob * 100.0;
		
		printf("%.6lf%%\n",prob);
	}
	return 0;
}

