#include <stdio.h>

int main(){
	int nTest,kthTest;
	int nHigh, nLow, nJump, prePos, curPos;
	
	scanf("%d",&nTest);
	kthTest = 1;
	while(kthTest <= nTest){
		scanf("%d",&nJump);
		scanf("%d",&prePos);
		nHigh = 0;
		nLow = 0;
		nJump--; /*the first position does not count*/
		while(nJump >= 1){
			nJump--;
			scanf("%d",&curPos);
			nHigh += (prePos < curPos)? 1 : 0;
			nLow += (prePos > curPos)? 1: 0;
			prePos = curPos;
		}
		printf("Case %d: %d %d\n",kthTest, nHigh, nLow);
		kthTest++;
	}
	return 0;
}