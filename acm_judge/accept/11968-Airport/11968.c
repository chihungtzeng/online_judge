#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1001

long long otherItem[MAX], cakeItem[MAX], drinkItem[MAX];
long long sum;
double avg;
short nTest, kase=1, nItem, nDrink, nCake;
long long drink, cake;

long long choose(double avg, long long item[], short nItem){
	short i;
	long long ans;
	double diff, newDiff;
	ans = item[0];
	
	diff = fabs(ans - avg);
	
	for(i=1; i<nItem; i++){
		newDiff = fabs(item[i] - avg);
		if(newDiff < diff){
			diff = newDiff;
			ans = item[i];
		}
		else if ((newDiff == diff) && (item[i] < ans)){
			ans = item[i];
		}
	}
	return ans;
}


int main(){
	short i, nOther;
	scanf("%hd", &nTest);
	while(nTest > 0){
		nTest--;
		sum = 0;
		scanf("%hd %hd %hd", &nItem, &nCake, &nDrink);
		nOther = nItem - nCake - nDrink;
		for(i=0; i<nCake; i++){
			scanf("%lld", cakeItem + i);
			sum += cakeItem[i];
		}
		for(i=0; i<nDrink; i++){
			scanf("%lld", drinkItem + i);
			sum += drinkItem[i];
		}
		for(i=0; i<nOther; i++){
			scanf("%lld", otherItem + i);
			sum += otherItem[i];
		}
		avg = (sum + 0.0) / nItem;
		cake = choose(avg, cakeItem, nCake);
		drink = choose(avg, drinkItem, nDrink);
		
		
		printf("Case #%hd: %lld %lld\n", kase++, cake, drink);		
	}
	return 0;
}