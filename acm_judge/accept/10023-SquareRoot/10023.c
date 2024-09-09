#include <stdio.h>
#include <math.h>

int main(){
	int cases,i;
	long double n,res;
	char first = 1;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%Lf",&n);
		res=sqrtl(n);
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		printf("%llu\n",(unsigned long long int)res);
	}
	return 0;
} 