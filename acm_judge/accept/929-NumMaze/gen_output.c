#include <stdio.h>
#include <stdlib.h>
#define MAX 999
int main(){
	int i,j;
	printf("1\n");
	printf("%d\n",MAX);
	printf("%d\n",MAX);
	srand(100);
	for(i=0;i<=MAX;i++){
		for(j=0;j<=MAX;j++){
			printf("%d ",rand()%10);
		}
		printf("\n");
	}
}