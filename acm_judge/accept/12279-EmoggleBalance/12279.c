#include <stdio.h>

int main(){
	int nPos, nZero;
	int input;
	int nNum;
	int i, k = 1;
	while(1 == scanf("%d", &nNum)){
		if(!nNum) break;
		nPos = 0;
		nZero = 0;
		for(i=0; i<nNum; i++){
			scanf("%d", &input);
			if(input > 0) nPos++;
			else nZero++;
		}
		printf("Case %d: %d\n", k++, nPos - nZero);
	}
	return 0;
}