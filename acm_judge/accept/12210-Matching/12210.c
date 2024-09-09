#include <stdio.h>
#define MAX 10001

int main(){
	int age;
	int nMan, nWoman, k=1;
	int i;
	int youngest;
	int nRemain;
	while(2 == scanf("%d %d", &nMan, &nWoman)){
		if( (nMan == 0) && (nWoman == 0)) {
			break;
		}
		youngest = 1000000000;
		for(i=0; i<nMan; i++){
			scanf("%d", &age);
			if(age < youngest){
				youngest = age;
			}
		}
		for(i=0; i<nWoman; i++){
			scanf("%d", &age);
		}
		if(nMan - nWoman > 0){
			nRemain = nMan - nWoman;
		} else {
			nRemain = 0;
		}
		
		printf("Case %d: %d", k++, nRemain);
		if(nRemain > 0){
			printf(" %d\n", youngest);
		} else {
			printf("\n");
		}
	}
	return 0;
}
