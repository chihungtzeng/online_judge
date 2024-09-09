#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	short nTest;
	char first = 1;
	long long n, ans;
	long long s1, s2, s3, sum, d1, d2, d3;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lld",&sum);
		if(sum == 0){
			if(first){
			first = 0;
			}
			else{
				puts("");
			}
			puts("3");
			continue;
		}
	
		sum = llabs(sum);
		n = ceil((-1 + sqrt(1 + (sum << 3)))/2) + 1e-12;
		s1 = n*(n+1)/2;
		d1 = s1 - sum;
		d2 = d1 + n + 1;
		d3 = d2 + n + 2;
		if(d1 % 2 == 0){
			ans = n;
		} 
		else if (d2 % 2 == 0) {
			ans = n + 1;
		}
		else {
			ans = n + 2;
		}
		
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		printf("%lld\n",ans);
	}
	return 0;
}