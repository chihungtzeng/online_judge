#include<stdio.h>
#include<math.h>
#define EPSILON 1e-323

int main(){
	short nTest;
	long double a, b, S, prob;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%Lf %Lf %Lf", &a, &b, &S);
		if(S <= EPSILON){
			prob = 1.0;
		}
		else{
			prob = 1 - ((S/a)/b)*(1 + logl(a) + logl(b) - logl(S));
		}
		prob = prob * 100.0;
		printf("%.6Lf%%\n",prob);
	}
	return 0;
}
