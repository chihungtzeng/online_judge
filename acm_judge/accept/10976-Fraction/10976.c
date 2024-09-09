#include <stdio.h>
#define MAX 10001

struct point {
	int x, y;
};

struct point ansSet[MAX << 1];
int nAns;

int main(){
	int k;
	int x, y, numerator, denominator;
	
	while(EOF != scanf("%d", &k)){
		nAns = 0;
		for(y = k+1; y <= (k << 1); y++){
			numerator = k * y;
			denominator = y - k;
			if( numerator % denominator == 0){
				ansSet[nAns].x = numerator / denominator;
				ansSet[nAns].y = y;
				nAns++;
			}
		}
		printf("%d\n", nAns);
		for(x = 0; x < nAns; x++){
			printf("1/%d = 1/%d + 1/%d\n", k, ansSet[x].x, ansSet[x].y);
		}
	}
	return 0;
}