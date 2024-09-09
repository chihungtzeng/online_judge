#include <stdio.h>
#include <string.h>
#define MAX 3000
#define DEBUG 0




int main(){
	int i;
	int input[MAX];
	int jdiff[MAX];
	int nNum,pre;
	int diff;
	short ifJolly;

	while(1 == scanf("%d",&nNum)){
		memset(jdiff, 0, sizeof(int)*MAX);
		for(i=nNum -1; i>=0;i--){
			scanf("%d",&input[i]);
		}
#if DEBUG
	for(i=0;i<nNum;i++){
		printf("%d ", input[i]);
	}
	printf("\n");
#endif
		ifJolly = 1;
		for(i=nNum-2;(i>=0) && (ifJolly);i--){
			diff = input[i] - input[i+1];
			diff = (diff + (diff >> 31)) ^ (diff >> 31);
#if DEBUG
				printf("%d ",diff);
#endif
			if( (diff >= nNum) && (diff <= 0)){
				ifJolly = 0;
			}
			jdiff[diff] = 1;
		}
#if DEBUG
			printf("\n");
#endif

		if (!ifJolly){
			printf("Not jolly\n");
		}
		else{
			for(i=nNum-1;(i>=1)&&(ifJolly);i--){
				if(jdiff[i] == 0){
					ifJolly =0;
				}
			}
			if(ifJolly){
				printf("Jolly\n");
			}
			else{
				printf("Not jolly\n");
			}
		}
	}

	return 0;
}