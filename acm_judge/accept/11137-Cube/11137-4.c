#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NVALUE 22
#define MAX 10001

long long table[NVALUE][MAX];
int currency[NVALUE];

void initCurrency(int *currency){
	int i;
	for(i=0; i<NVALUE; i++){
		currency[i] = i*i*i;
	}
}

long long findAns(int money, int allow){
	long long ans = 0;
	int i, r;
	if(money == 0){
		return 1;
	}
	else if(allow == 1){
		return 1;
	}
	if (allow == 2){
		return 1 + money/currency[2];
	}
	
	if(currency[allow] == 0){
		return 1;
	}
	
	if(table[allow][money] != 0){
		return table[allow][money];
	}
	
	r = money/currency[allow];
	
	for(i=0; i <= r; i++){
		ans += findAns(money - i*currency[allow], allow - 1);
	}
	table[allow][money] = ans;
	return ans;
}

int main(){
	int m, allow, i;
	long long ans;
	
	
	initCurrency(currency);
	
	while(1 == scanf("%d", &m)){
		allow = 0;
		while((currency[allow] <= m) && (allow < NVALUE)){
			allow++;
		}
		allow--;
		
		ans = findAns(m,  allow);
		
		printf("%lld\n",ans);
	}
	
	
	return 0;
}