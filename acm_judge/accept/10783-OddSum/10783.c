#include <stdio.h>

int main(){
	int nTest, kcase;
	int sum, a, b, left, right;
	int n;
	
	
	scanf("%d",&nTest);
	kcase = 1;
	while	(kcase <= nTest){
		scanf("%d %d",&left, &right);
		if( left > right){
			left = left ^ right;
			right = left ^ right;
			left = left ^ right;
		}
		left = left | 1;
		if (!(right & 1)){
			right = right - 1;
		}
		n = ((right - left) >> 1) + 1;
		sum = (n * (left + right)) >> 1;
		printf("Case %d: %d\n",kcase,sum);
		kcase++;
	}
	
	return 0;
}