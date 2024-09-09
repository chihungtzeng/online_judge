#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int m=2;
	int n,k;
	int i,j;
	
	srand(time(NULL));
	n = (rand()%80)+21;
	k = rand() % (n*n/2) ; 

	printf("%d\n",m);
	for(i=0;i<m;i++){
		printf("%d %d\n",n,k);
		for(j=0;j<k;j++){
			printf("%d %d\n",(rand()%n) + 1, (rand()%n) + 1);
		}
	}
}
