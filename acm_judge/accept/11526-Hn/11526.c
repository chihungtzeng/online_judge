#include <stdio.h>
#include <math.h>
int main(){
	int nTest;
	int sq;
	int n;
	int curRemainder;
	int left,right;
	long int sum;
	int i;
	
	scanf("%d",&nTest);
	while(nTest>=1){
		nTest--;
		scanf("%d",&n);
		if (n <= 0){
			printf("0\n");
			continue;
		}
		sum = 0;
		sq = (int) sqrt(n);		
		for(i = sq; i > 0; i--){
			sum += n/i;
		}

		/*decide the range [left, right] whose remainder, 
		when divided by b, is curRemainder */
		left = sq + 1;
		curRemainder = n / left;		
		while(curRemainder >= 1){
			right = n / curRemainder;
			sum += (right - left + 1)*curRemainder;
			left = right + 1;
			curRemainder = n / left;
		}
		
		printf("%ld\n",sum);
	}
	return 0;
}
