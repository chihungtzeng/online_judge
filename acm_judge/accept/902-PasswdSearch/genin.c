#include <stdio.h>
#include <stdlib.h>

int main(){
	int k=10000;
	int i,j;
	srand(time(NULL));

	for(i=1;i<=100;i++){
		printf("%d ",(i%10)+1);
		for(j=0;j<k;j++){
			printf("%c",'p'+(rand()%5));
		}
		printf("\n");
	}
}
