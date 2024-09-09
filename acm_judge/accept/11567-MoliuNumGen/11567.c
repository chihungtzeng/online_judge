#include <stdio.h>

short findAns(long long n){	
	short plus, minus;
	if(n == 0) return 0;
	else if (n==1) return 1;
	
	if(n % 2 == 0) return 1 + findAns(n >> 1);
	else {
		plus = findAns(n + 1);
		minus = findAns(n - 1);
		if(plus < minus) return 1 + plus;
		else return 1 + minus;
	}
}

int main(){
	long long n, k;
	short ans;
	while(1 == scanf("%lld", &n)){
		if(n==0){
			printf("0\n");
			continue;
		}
		ans = findAns(n);
		
		printf("%hd\n",ans);
	}
	return 0;
}