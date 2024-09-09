#include <stdio.h>
#include <string.h>
#define NVALUE 22
#define MAX 10001

int currency[NVALUE];


void initCurrency(){
	int i;
	for(i=0; i<NVALUE; i++){
		currency[i] = i*i*i;
	}
}

long findAns(int money, int allow){
	long ans = 0;
	int i, r;
	if(allow == 1){
		return 1;
	}
	else if (allow == 2){
		return 1 + money/currency[2];
	}
	r = money/currency[allow];
	for(i=0; i <= r; i++){
		ans += findAns(money - i*currency[allow], allow - 1);
	}
	return ans;
}

int main(){
	int m, allow;
	long ans;	
	initCurrency();
	while(1 == scanf("%d", &m)){
		allow = 0;
		while((currency[allow] < m) && (allow < NVALUE)){
			allow++;
		}
		allow--;
		ans = findAns(m, allow);
		printf("%ld\n",ans);
	}
	
	
}