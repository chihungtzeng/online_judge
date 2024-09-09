#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, r, k;
	for(n=0; n<1;n++){
		for(r=0; r<20; r++){
			for(k=1;k<20;k++){
				printf("%d %d %d\n",n,r,k);
			}
		}
	}
}
