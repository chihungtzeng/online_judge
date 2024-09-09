#include <stdio.h>

int main(){
	char nTest, nNum, i;
	int area, nAnimal, money;
	long long ans;
	scanf("%hhd", &nTest);
	while(nTest){
		nTest--;
		ans = 0;
		scanf("%hhd", &nNum);
		for(i=0; i<nNum; i++){
			scanf("%d %d %d", &area, &nAnimal, &money);
			ans += area*money;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}