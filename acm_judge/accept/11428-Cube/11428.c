#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long x, y, N;


int findAns(){
	long long xLowerBound, xUpperBound;
	long long xt, yt, tmp;
	
	xLowerBound = cbrt(x);
	while(xLowerBound*xLowerBound*xLowerBound <=N){
		xLowerBound++;
	}
	xUpperBound = 1 + (1 + sqrt(1 + ((N-1) << 2)/3))/2;
	/*printf("N=%lld => %lld < x < %lld\n",N, xLowerBound, xUpperBound);*/
	for(xt = xLowerBound; xt <= xUpperBound; xt++){
		tmp = xt*xt*xt - N;
		
		yt = cbrt((double)tmp) + 1e-8;
		
		if(yt*yt*yt == tmp){
			x = xt;
			y = yt;
			return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}

int main(){
	while(1 == scanf("%lld",&N)){
		if(0 == N) return 0;
		
		if(EXIT_SUCCESS == findAns()){
			printf("%lld %lld\n",x, y);
		}
		else{
			printf("No solution\n");
		}
	}
	return 0;
}