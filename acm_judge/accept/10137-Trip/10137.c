#include <stdio.h>
#define MAX 1001

int main(){
	long long spend[MAX];
	long long dolar, cent;
	long long avg, shit, damn, ans;
	short n, i;
	
	while(1 == scanf("%hd", &n)){
		if(n == 0) break;
		
		avg = 0;
		for(i=n-1; i>=0; i--){
			scanf("%lld.%lld", &dolar, &cent);
			spend[i] = dolar*100 + cent;
			avg += spend[i];
		}
		avg = avg / n;
		shit = 0;
		damn = 0;
		for(i=n - 1; i>=0; i--){
			if(spend[i] < avg){
				shit += avg - spend[i];
			} 
			else{
				damn += spend[i] - avg;
			}
		}
		ans = (shit > damn)? shit: damn;
		printf("$%lld.%02lld\n",ans/100, ans % 100);
	}
		
	
	return 0;
}