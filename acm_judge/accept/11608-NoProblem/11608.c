#include <stdio.h>
#define MAX 12

int main(){
	short surplus;
	short probGen[MAX];
	short probRequire[MAX];
	short i, j, kCase = 1;
	
	
	while(1 == scanf("%hd", &surplus)){
		if(surplus < 0){
			break;
		}
		for(i=0; i<MAX; i++){
			scanf("%hd", &probGen[i]);
		}
		for(i=0; i<MAX; i++){
			scanf("%hd", &probRequire[i]);
		}
		
		printf("Case %hd:\n",kCase++);
		for(i=0; i<MAX; i++){
			if(surplus >= probRequire[i]){
				printf("No problem! :D\n");
				surplus = surplus - probRequire[i] + probGen[i];
			}
			else{
				printf("No problem. :(\n");
				surplus += probGen[i];
			}
		}
	}
	
}