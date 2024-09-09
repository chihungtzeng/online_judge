#include <stdio.h>
#include <string.h>
#define MAX 101

int main(){
	short occr[MAX];
	short nCell, n, nTest, i, num, k = 1;
	char bStable;
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &n);
		nCell = n * n;
		bStable = 1;
		memset(occr, 0, sizeof(occr[0])*MAX);
		for(i=0; i<nCell; i++){
			scanf("%hd", &num);
			++occr[num];
		}		
		for(i=0; (i<MAX) && bStable; i++){
			if(occr[i] > n){
				bStable = 0;
			}
		}
		printf("Case %hd: %s\n", k++, (bStable)? "yes" : "no");
	}
		
	
	return 0;
}