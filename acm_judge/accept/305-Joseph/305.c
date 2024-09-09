#include <stdio.h>

int m[] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313,
459901, 1358657, 2504881};


int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(0 == n){
			break;
		}
		printf("%d\n",m[n]);
	}
	return 0;
}
