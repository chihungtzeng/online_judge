#include <stdio.h>
/* 316^2 < 100000 < 317^2 */
#define MAX 318

int main(){
	int square[MAX];
	int i,j;
	int left,right;
	int count,done;
	
	for(i=0;i<MAX;i++){
		square[i] = i*i;
	}
	
	done = 0;
	while(!done){
		scanf("%d %d",&left,&right);
		if ((0 == left)&&(0==right)){
			done = 1;
			continue;
		}
		count = 0;
		for(i=0;i<MAX;i++){
			if ((square[i]>=left) && (square[i]<=right)){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}