#include <stdio.h>
#include <math.h>
#define DEBUG 0

long long findAns(long long n){
	long long a, b;
	long long sq = 0;
	long long ans = 0;
	long long n2 = n << 1;
	sq = sqrt(n);
	for(a=1; a <= sq; a++){
		if( (n2 - 2 + a) % ( (a << 1) - 1) == 0){
			b = (n2 - 2 + a) / ( (a << 1) - 1);
			ans += (a == b)? 1 : 2;
			if(DEBUG) printf("(%lld %lld) ", a, b);
		}
	} 
	if(DEBUG) printf("\n");
	return ans;
}

int main(){
	long long n, ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	while(1 == fscanf(fp, "%lld", &n)){
		if(n == 0) break;
		ans = findAns(n);
		printf("%lld %lld\n", n, ans);
	}
	return 0;
}
