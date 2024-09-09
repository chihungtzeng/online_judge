#include <stdio.h>
#include <math.h>
#define MAX 10001

char ans[MAX];

char min(char a, char b){
	if (a < b) return a;
	else return b;
}

void nSquare(){
	int i, n, sq;
	char result;
	ans[0] = 0;
	ans[1] = 1;
	
	for(n=2; n<MAX; n++){
		sq = sqrt(n);
		if(sq * sq == n){
			ans[n] = 1;
		}
		else{
			result = 20;
			for(i=1; i <= sq; i++){
				result = min(result, ans[n - i*i]);
			}
			ans[n] = 1 + result;
		}
	}
}

int main(){
	int n;
	int nTest;
	nSquare();
	printf("char ans[] = {");
	for(n=0; n<MAX; n++){
		printf("%hhd,", ans[n]);
		if(n % 20 == 0){
			printf("\n");
		}
	}
	printf("};\n");
	/*
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d",&n);
		printf("%hhd\n",ans[n]);
	}
	*/
	return 0;
}