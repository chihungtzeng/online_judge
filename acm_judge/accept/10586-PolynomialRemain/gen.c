#include <stdio.h>
#include <stdlib.h>
#define C 500
#define MAX 100
#define KASE 100

int main(){
	int n, k, i, kase;
	srand(time(NULL));
	for(kase=0; kase<KASE; kase++){
		n = rand() % MAX;
		k = rand() % MAX;
		printf("%d %d\n", n, k);
		for(i=0; i<=n; i++){
			printf("%d ", (rand() % C) - C);
		}
		printf("\n");
	}
	printf("-1 -1\n");
}