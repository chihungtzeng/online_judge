#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 12

long long sum[N][N];
long long ele[N][N];
long long ans[N];
int n;


void solve(){
	char i, j, x, left, right;
	long long preAns;
	/*find 2D prefix sum*/
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			sum[i][j] = ele[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	#if 0
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%lld ", sum[i][j]);
		}
		printf("\n");
	}
	#endif	
	
	if(n & 1){
		x = (n >> 1) + (n & 1);
		ans[x] = ele[x][x];
		preAns = ans[x];
		right = x + 1;
		left = right - 2;
	} else{
		right = (n >> 1) + 1;
		left = right - 1;
		preAns = 0;
	}
	x = n >> 1;
	
	
		
	while(right <= n){
		ans[x] = sum[right][right] - sum[right][left-1] - sum[left-1][right] + sum[left-1][left-1] - preAns;
		preAns += ans[x];
		left--;
		right++;
		x--;
	}
}

int main(){
	short k = 1;	
	char i, j, nAns;
	
	for(i=0; i<N; i++){
		sum[i][0] = 0;
		sum[0][i] = 0;
	}
	
	while(1 == scanf("%d", &n)){
		if(0 == n) break;
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				scanf("%lld", &ele[i][j]);
			}
		}
		solve();
		nAns = (n >> 1) + (n & 1);
		printf("Case %hd:", k++);
		for(i=1; i<=nAns; i++){
			printf(" %lld", ans[i]);
		}		
		printf("\n");
	}
	return 0;
}