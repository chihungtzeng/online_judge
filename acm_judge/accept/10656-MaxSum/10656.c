#include <stdio.h>
#define MAX 1024

int main(){
	int nNum, count;
	int i;
	short num;
	short ans[MAX];
	
	while(1 == scanf("%d",&nNum)){
		if(0 == nNum) break;
		
		count = 0;
		for(i=0; i<nNum; i++){
			scanf("%hd", &num);
			if(num > 0){
				ans[count++] = num;
			}
		}
		if(count == 0){
			printf("0\n");
		}
		else{
			printf("%hd",ans[0]);
			for(i=1; i<count; i++){
				printf(" %hd",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}