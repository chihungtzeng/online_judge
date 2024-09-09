#include <stdio.h>
#include <math.h>

int main(){
	short nTest;
	short L, D;
	double a, b;
	double pi = 2*acos(0);
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd %hd", &D, &L);
		a = L/2.0;
		b = sqrt((L - D)*(L + D))/2.0;
		printf("%.3lf\n",pi*a*b);
	}
	return 0;
}