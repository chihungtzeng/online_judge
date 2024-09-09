#include <stdio.h>

int main(){
	long x1, y1, x2, y2;
	long rank1, rank2;
	short nTest, k = 1;
	scanf("%hd",&nTest);
	while(k <= nTest){
		
		scanf("%ld %ld %ld %ld",&x1, &y1, &x2, &y2);
		rank1 = ((x1 + y1)*(x1 + y1 + 1) >> 1) + x1;
		rank2 = ((x2 + y2)*(x2 + y2 + 1) >> 1) + x2;
		
		printf("Case %hd: %ld\n", k++, rank2 - rank1);
	}
	return 0;
}