#include <stdio.h>
#define DEBUG 0


int main(){
	int nInput;
	int count[10];
	int i,j,k;
	long int input;

	scanf("%d",&nInput);
	
	for(i=0;i<nInput;i++){
		scanf("%ld",&input);
		if((input == 0) || (input == 1)){
			printf("%ld\n",input);
			continue;
		}
		for(j=2;j<=9;j++){
			count[j] = 0;
		}
		for(j=9;j>=2;j--){
			while((input % j) == 0){
				count[j]++;
				input = input / j;
			}
		}
		
		if(DEBUG){
			for(j=2;j<=9;j++){
				printf("%d ",count[j]);
			}
			printf("\n");
		}
		
		if(input != 1){
			printf("-1\n");
		}

		else{
			for(j=2;j<=9;j++){
				for(k=0;k<count[j];k++){
					printf("%d",j);
				}
			}
			printf("\n");
		}
	}

	return 0;
}