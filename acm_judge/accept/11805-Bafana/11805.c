#include <stdio.h>

int main(){
	short k = 1, N, K, P, nTest;
	short ans;
	scanf("%hd",&nTest);
	while(k <= nTest){
		scanf("%hd %hd %hd", &N, &K, &P);
		ans = ((K - 1 + P) % N) + 1;
		printf("Case %hd: %hd\n",k++, ans);
	}
	return 0;
}