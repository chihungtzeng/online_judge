#include <stdio.h>
#define MAX 1001

int main(){
	int nTest;
	short nNum, i, day;
	short num[MAX];
	
	int sum;
	
	
	scanf("%d", &nTest);
	while(nTest--){
		sum = 0;
		scanf("%hd", &nNum);
		for(i=0; i<nNum; i++){
			scanf("%hd", num + i);
		}
		for(day = 1; day < nNum; day++){
			for(i=day - 1; i >= 0; i--){
				if(num[i] <= num[day]) sum++;
			} 
		}
		printf("%d\n", sum);
	}
	return 0;
}