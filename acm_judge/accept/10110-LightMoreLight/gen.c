#include <stdlib.h>
#include <stdio.h>
#define MAX 800000

int main(){
	int i;
	unsigned int x;

	srand(time(NULL));
	for(i=0;i<MAX;i++){
		x = rand();
		printf("%d\n",x);
	}
	printf("0\n");
}
