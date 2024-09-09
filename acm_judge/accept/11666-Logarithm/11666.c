#include <stdio.h>
#include <math.h>


int main(){
	int n, L;
	double x, logn;
	
	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		logn = log(n);
		L = (int) logn;
		if(logn - L > log(2)){
			L++;
		}
		x = logn - L;
		x = 1 - pow(M_E, x);
		
		printf("%d %.8lf\n",L,x);
	}
	return 0;
}
