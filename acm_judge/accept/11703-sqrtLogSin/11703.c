#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 1000000
#define N 1000001

int x[N];

int getX(int n){
	int ans;
	double d;
	if(x[n] != -1) return x[n];
	
	d = sqrt(n);
	d = n - d;
	ans = getX((int) floor(d));
	
	d = log(n);
	ans += getX((int) floor(d));

	d = sin(n);
	d = d*d*n;
	ans += getX((int) floor(d));
	x[n] = ans % MAX;
	return x[n];
}

int main(){
	int n;
	memset(x, 0xff, sizeof(int)*N);
	x[0] = 1;

	while(1 == scanf("%d",&n)){
		if(n == -1) break;
		printf("%d\n", getX(n));
	}	
	
	return 0;
}