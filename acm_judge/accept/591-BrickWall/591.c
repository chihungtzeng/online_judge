#include <stdio.h>
#include <stdlib.h>

int main(){
	short n, h[101], i, avg, nMove;
	short k=1;
	while(1 == scanf("%hd", &n)){
		if(0 == n) break;
		
		avg = 0;
		nMove = 0;
		for(i=n-1; i>=0; i--){
			scanf("%hd", h+i);
			avg += h[i];
		}
		avg = avg / n;
		for(i=n-1; i>=0; i--){
			nMove += abs(avg - h[i]);
		}
		nMove = nMove >> 1;
		printf("Set #%hd\n",k++);
		printf("The minimum number of moves is %hd.\n\n",nMove);
	}
	return 0;
}