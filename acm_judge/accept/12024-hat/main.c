#include <stdio.h>
#define MAX 13
long long ans[MAX];
long long fac[MAX];

void buildTable(){
	char i, j, k;
	long long coef;

	fac[0] = 1;
	for(i=1; i<MAX; i++){
		fac[i] = fac[i-1]*i;
	}	
	
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 1;
	
	
	for(i=3; i<MAX; i++){
		ans[i] = 0;
		coef = i - 1;
		j = i - 1;
		while(j >= 0){
			ans[i] += coef*ans[j-1];
			
			j -= 1;
			coef = coef * j;
		}
	}
	printf("{");
	for(i=0; i<MAX; i++){
		printf("\"%lld\",", fac[i]);
	}
	printf("}\n");
	printf("{");
	for(i=0; i<MAX; i++){
		printf("\"%lld\",", ans[i]);
	}
	printf("}\n");
}

int main(){
	short nTest, i;
	buildTable();
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &i);
		printf("%lld/%lld\n", ans[i], fac[i]);
	}
	
	return 0;
}
