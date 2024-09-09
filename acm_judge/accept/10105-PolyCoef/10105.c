#include <stdio.h>
#define MAX 14


int main(){
	long int fac[MAX];
	long int coef;
	int i;
	int n, k, cur;
	fac[0] = 1;
	for(i=1; i < MAX; i++){
		fac[i] = fac[i-1] * i;
	} 
	while(2 == scanf("%d %d",&n, &k)){
		coef = fac[n];
		for(i=k; i>= 1; i--){
			scanf("%d",&cur);
			if(cur > 1){
				coef = coef / fac[cur];
			}
		}
		printf("%ld\n",coef);
	}
	
	return 0;
}