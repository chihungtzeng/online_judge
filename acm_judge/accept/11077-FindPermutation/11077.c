#include <stdio.h>
#define MAX 22

unsigned long long ans[MAX][MAX];

void buildTable(){
	char i, j;
	ans[0][0] = 0;
	for(i=1; i<MAX; i++){
		ans[i][0] = 1;
		ans[i][i] = 0;
		ans[0][i] = 0;
	} 
	for(i=2; i<MAX; i++){
		for(j=1; j<i; j++){
			ans[i][j] = ans[i-1][j] + ans[i-1][j-1]*(i-1);
		}
	}
}

int main(){
	char i, j;
	buildTable();
	while(2 == scanf("%hhd %hhd", &i, &j)){
		if((0 == i) && (0 == j)){
			return 0;
		}
		else{
			printf("%llu\n", ans[i][j]);
		}
	}
	return 0;
}