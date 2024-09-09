#include <stdio.h>
#define MAX 20
#define NINF -1000000000000000000
char nNum, num[MAX];
long long product[MAX];

long long solve(){
	char start, end;
	char i;
	long long ans = NINF, tmp, down, up; 

	product[0] = num[0];
	for(i=1; i<nNum; i++){
		if(product[i-1] == 0){
			product[i] = num[i];
		} else {
			product[i] = num[i] * product[i-1];
		}
	}	
	#if 0
	for(i=0; i<nNum; i++){
		printf("%lld ", product[i]);
	}
	printf("\n");
	#endif
	
	
	for(start=0; start < nNum; start++){
		down = ((start == 0) || (product[start - 1] == 0))? 1 : product[start - 1];
		
		for(end = start; end < nNum; end++){
			
			tmp = product[end] / down;
			if(tmp > ans) ans = tmp;
		}
	}
	
	return (ans > 0)? ans : 0;
}

int main(){
	short k=1;
	char i;
	long long ans;
	while(1 == scanf("%hhd", &nNum)){
		for(i=0; i<nNum; i++){
			scanf("%hhd", num + i);
		}
		ans = solve(nNum, num);
		printf("Case #%hd: The maximum product is %lld.\n\n", k++, ans);
	}
	return 0;
}