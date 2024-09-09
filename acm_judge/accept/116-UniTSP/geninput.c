#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(int argc,char *argv[]){
	int r,c;
	int i,j;
	r=10;
	c=100;
	printf("%d %d\n",r,c);
	srand(time(NULL));
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",rand()%100000);
		}
		printf("\n");
	}
}
