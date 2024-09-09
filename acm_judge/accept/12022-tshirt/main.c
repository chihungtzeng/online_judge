#include <stdio.h>
#define MAX 12
long long ans[MAX];
long long bcoef[MAX][MAX];

void buildTable(){
	char i, j;
	bcoef[0][0] = 1;
	bcoef[1][0] = 1;
	bcoef[1][1] = 1;
	for(i=2; i<MAX; i++){
		bcoef[i][0] = 1;
		bcoef[i][i] = 1;
		for(j=i-1;j>=1; j--){
			bcoef[i][j] = bcoef[i-1][j] + bcoef[i-1][j-1];
		} 
	} 
	#if 0
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			printf("%lld ", bcoef[i][j]);
		}
		printf("\n");
	}
	#endif
}

int main(){
	int i, j, nTest;
	ans[1] = 1;
	ans[0] = 1;
	ans[2] = 3;
	buildTable();
	for(i=3; i<MAX; i++){
		ans[i] = 0;
		for(j=1; j <= i; j++){
			ans[i] += ans[i - j]*bcoef[i][j];
		}
	}
	#if 1
	printf("{");
	for(i=0; i<MAX;i++){
		printf("\"%lld\",", ans[i]);
	}
	printf("};\n");
	#endif
	/*
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &i);
		printf("%lld\n", ans[i]);
	}
	*/
	return 0;
}