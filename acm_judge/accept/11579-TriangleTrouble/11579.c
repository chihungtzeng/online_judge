#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10010

double side[MAX];
int nSide;

int compareDouble(const void *a, const void *b){
	double x, y;
	x = *(double *)a;
	y = *(double *)b;
	if(x < y) return 1;
	else if (x > y) return -1;
	else return 0;
}

int main(){
	int nTest;
	int i;
	double ans, bestAns;
	char hasAns;
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d", &nSide);
		for(i=0; i <nSide ; i++){
			scanf("%lf",&side[i]);
		}
		qsort(side, nSide, sizeof(double), compareDouble);
		bestAns = 0;
		for(i=0; (i < nSide - 2); i++){
			if(side[i+1] + side[i+2] > side[i]){
				double a, b, c, s;
				a = side[i];
				b = side[i+1];
				c = side[i+2];
				s = (a + b + c) / 2;
				ans = sqrt(s)*sqrt(s-a)*sqrt(s-b)*sqrt(s-c);
				if(ans > bestAns){
					bestAns = ans;
				}
			}			
		}
		
		printf("%.2lf\n",bestAns);
		
	}
	return 0;
}