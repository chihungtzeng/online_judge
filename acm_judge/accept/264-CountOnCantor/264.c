#include <stdio.h>
#define MAX 5000

int main(){
	int sn[MAX];
	int i,j;
	int input, diag;
	int left,right,middle, match;
	int up,down,dist,total;
	
	sn[0] = 0;
	for(i=1;i<MAX;i++){
		sn[i] = sn[i-1] + i;
	}

	while( 1 == scanf("%d",&input)){
		
		left = 0;
		right = MAX - 1;
		match = 0;
		while((left <= right) && (!match)){
			middle = (left + right) >> 1;
			if(sn[middle] == input){
				match = 1;
			}
			else if (sn[middle] < input){
				left = middle + 1;
			}
			else{
				right = middle - 1;
			}
		}
		diag = (match)? middle : ((left + right) >> 1) + 1;		
		dist = input - sn[diag - 1];
		total = diag + 1;
		if(diag & 1){
			up = diag - dist + 1;
			down = total - up;
		}
		else {
			down = diag - dist + 1;
			up = total  - down;
		}
		printf("TERM %d IS %d/%d\n", input, up,down);
	}
	return 0;
}
