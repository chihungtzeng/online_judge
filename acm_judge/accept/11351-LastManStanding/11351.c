#include <stdio.h>

int joseph(int n, int k){
	int tmp;
	if(n == 1) return 0;
	
	tmp = joseph(n - 1, k) + k;
	if(tmp < n) return tmp;
	else return tmp % n; 
}

int main(){
	int n, k, nTest, ans, kase=1;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d", &n, &k);
		ans = joseph(n, k);
		printf("Case %d: %d\n", kase++, ans + 1);
	}
	return 0;
}