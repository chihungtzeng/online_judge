#include <stdio.h>
#define MAX 51

int main(){
	char num[MAX];
	short nTest, n, i, j, count;	
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd",&n);
		for(i=0; i<n; i++){
			scanf("%hhd", num + i);
		}
		count = 0;
		for(i=0; i<n; i++){
			for(j=i+1; j<n;j++){
				if(num[i] > num[j]) count++;
			}
		}
		printf("Optimal train swapping takes %hd swaps.\n",count);
	}
	return 0;
}