#include <stdio.h>

int main(){
	int k = 1;
	int n, m;
	
	while(2 == scanf("%d %d", &n, &m)){
		if((0 == n) && (0 == m)) break;
		printf("Case %d: %lld\n", k++, ((long long)n*m*(n-1)*(m-1)) >> 2);
	}
	return 0;
}