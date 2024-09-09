#include <stdio.h>
#include <math.h>
#define NSUM 1500
#define NCOEF 10001

int sum[NSUM];
int coef[NCOEF], nCoef;
int d,k;

int findN(int target){
	int left, right, middle;	
	left = 1;
	right = NSUM - 1;
	
	while(left <= right){
		middle = (left + right) >> 1;
		if(sum[middle] == target){
			return middle;
		}
		else if (sum[middle] < target){
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int i, j, nTest;
	int idx;
	unsigned long result;
	
	sum[0] = 0;
	for(i=1; i<NSUM;i++){
		sum[i] = sum[i-1] + i; 
	}
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d",&nCoef);
		for(i=0;i<=nCoef;i++){
			scanf("%d",&coef[i]);
		}
		scanf("%d %d",&d, &k);
		idx = findN((k-1)/d) + 1;
		result = 0;
		for(i=0; i<=nCoef; i++){
			if(coef[i] != 0){
				result += coef[i]*pow(idx, i);
			}
		}
		printf("%lu\n",result);
	}
}