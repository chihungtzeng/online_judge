#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

struct Digit{
	int count[10];
};

struct Digit *ans;

void buildTable(){
	int n, i, tmp;
	for(n=1; n<MAX; n++){
		tmp = n;
		while(tmp > 0){
			ans[n].count[tmp % 10] += 1;
			tmp = tmp / 10;
		}
		for(i=0; i<10; i++){
			tmp = n - 1;
			ans[n].count[i] += ans[tmp].count[i];
		}
	}
}

int main(){
	int nTest, n, i;	
	ans = (struct Digit *) malloc(sizeof(struct Digit)*MAX);
	for(i=0; i<10; i++){
		ans[0].count[i] = 0;
	}
	buildTable();
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &n);
		printf("%d", ans[n].count[0]);
		for(i=1; i<10; i++){
			printf(" %d", ans[n].count[i]);
		}
		printf("\n");
	}
	free(ans);
	return 0;
}