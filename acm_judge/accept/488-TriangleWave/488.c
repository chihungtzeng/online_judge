/*AC*/
#include <stdio.h>

int main(){
	short height, amplitude, first, flag;
	int nTest, freq;
	int i,j;

	
	scanf("%d", &nTest);
	first = 1;
	while(nTest >= 1){
		if(!first){
			printf("\n");
		}
		else {
			first = 0;
		}
		
		scanf("%hd %d", &amplitude, &freq);
		flag = 1;
		for(i=0; i<freq; i++){
			if(!flag){ 
				printf("\n");
			}
			else{
				flag = 0;
			}
			
			for(height = 1; height<=amplitude; height++){
				for(j=1; j<=height;j++){
					printf("%d",height);
				}
				printf("\n");
			}
			for(height = amplitude - 1; height > 0; height--){
				for(j=1; j<=height;j++){
					printf("%d",height);
				}
				printf("\n");
			}
		}
		nTest--;
	}	
	
	return 0;
}