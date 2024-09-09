#include <stdio.h>

int main(){
	int max;
	int nNum, num, sum;
	int i;
	short done;
	done = 0;
	while(!done){
		scanf("%d",&nNum);
		if(nNum == 0){
			done = 1;
			continue;
		}
		max = 0;
		sum = 0;
		for(i=nNum; i>0; i--){
			scanf("%d", &num);
			if(num + sum < 0){
				sum = 0;
			}
			else{
				sum = sum + num;
				if ( (sum > max)){
					max = sum;
				}
			}
		}
		if(max == 0){
			printf("Losing streak.\n");
		}
		else{
			printf("The maximum winning streak is %d.\n", max);
		}
	}
	return 0;
}