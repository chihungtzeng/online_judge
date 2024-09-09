#include <stdio.h>
#include <math.h>

int main(){
	int height, nWorker;
	int nonWorker, stackHeight, tmp;
	int N, k, h, nPlusOne;
	char done;
	double rightSide;
	while(2 == scanf("%d %d", &height, &nWorker)){
		if((0 == height) && (0 == nWorker)){
			break;
		}
		if(height == 1){
			printf("0 1\n");
			continue;
		}
		if(nWorker == 1){
			nonWorker = -1;
			stackHeight = 0;
			while(height >= 1){
				stackHeight += height;
				nonWorker++;
				height = height >> 1;
			}
			printf("%d %d\n",nonWorker, stackHeight);
			continue;
		}
		
		rightSide = log(height)/log(nWorker);
		N = 2;
		while(fabs( log(N+1)/log(N) - rightSide) > 1e-12){
			N++;
		} 
		
		nonWorker = 0;
		nPlusOne = N + 1;
		height = 1;
		tmp = nWorker;
		stackHeight = 0;
		while(tmp > 0){
			stackHeight += tmp*height;
			height = height*nPlusOne;
			
			tmp = tmp /N;
			nonWorker += tmp ;
		}
		
		
		printf("%d %d\n", nonWorker, stackHeight);
	}
	return 0;
}