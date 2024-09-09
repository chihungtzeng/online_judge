#include <stdio.h>

int findAns(long long nBottle){
	if(nBottle == 0) return 0;
	else return 1 + findAns(nBottle >> 1);
}

int main(){
	int k=1, nTest;
	long long nBottle;
	scanf("%d", &nTest);
	while(nTest > 0){
		--nTest;
		scanf("%lld", &nBottle);
		printf("Case %d: %d\n", k, findAns(nBottle));
		++k;
	}
	return 0;
}