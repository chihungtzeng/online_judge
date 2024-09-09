#include <stdio.h>
#include <stdlib.h>

#define MAX 1005
#define SUCCESS 1
#define FAIL -1

int num[MAX];

int nNum;

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int mbsearch(int sum){
	short left, right, middle;
	left = 0;
	right = nNum - 1;
	
	while((left <= right)){
		middle = (left + right) >> 1;
		if(num[middle] == sum){
			return middle;
		}
		else if (num[middle] < sum){
			left = middle + 1;
		}
		else{
			right = middle - 1;
		}
	}


		return -1;

}

int main(){
	int i, j, k, sum;

	short match;
	
	while(1){
		scanf("%d",&nNum);
		if(nNum == 0){
			break;
		}
		for(i=0; i<nNum; i++){
			scanf("%d",&num[i]);
		}
		qsort(num, nNum, sizeof(int), compareInt);
		match = 0;
		for(i=nNum - 1; (i>=2) && (!match); i--){
			
			for(j=i-1; (j >= 1)&& (!match); j--){
				
				for(k=j-1; (k >= 0)&& (!match); k--){
					int idx;
					sum = num[i] + num[j] + num[k];
					idx = mbsearch(sum);
					if ((idx > 0) && (idx !=i) && (idx != j) && (idx != k)){
						match = 1;
					}
				
				}
				
			}
			
		}
		if(match){
			printf("%d\n",sum);
		}
		else{
			printf("no solution\n");
		}
	}	
	return 0;
}