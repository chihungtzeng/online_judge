#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STAMP_TYPE_NUM 10001
#define MAX_PEOPLE 64

short stamp[MAX_PEOPLE][MAX_PEOPLE];
short stampType[STAMP_TYPE_NUM];
short nUnique;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

void removeRedudant(short *a){
	short nEle = 1, i;
	qsort(a + 1, a[0], sizeof(short), compareShort);
	for(i=2; i <= a[0]; i++){
		if(a[i] != a[i-1]){
			
			a[++nEle] = a[i];
		}
	}
	a[0] = nEle;
}

int main(){
	short curType, t, nPart;
	char nTest, i, j, k=1, nPeople;
	
	scanf("%hhd", &nTest);
	while(nTest--){
		scanf("%hhd", &nPeople);
		memset(stampType, 0, sizeof(stampType[0])*STAMP_TYPE_NUM);
		nUnique = 0;
		for(i=0; i<nPeople; i++){
			scanf("%hd", &stamp[i][0]);
			for(j=1; j <= stamp[i][0]; j++){
				scanf("%hd", &stamp[i][j]);

			}
			removeRedudant(stamp[i]);

			for(j=1; j<=stamp[i][0]; j++){
				stampType[stamp[i][j]]++;
			}
		}
		for(t=0; t<STAMP_TYPE_NUM; t++){
			if(stampType[t] == 1) nUnique++;
		}
		printf("Case %hhd:", k++);
		for(i=0; i<nPeople; i++){
			nPart = 0;
			for(j=1; j<=stamp[i][0]; j++){
				curType = stamp[i][j];
				if(1 == stampType[curType]){
					nPart++;
				}	
			}
			printf(" %.6lf%%", (100.0 * nPart) / nUnique);
		}
		printf("\n");
		#if 0
		for(i=0; i<nPeople; i++){
			for(j=1; j<=stamp[i][0]; j++){
				printf("%hd ", stamp[i][j]);
			}
			printf("\n");
		}
		for(t=0; t<STAMP_TYPE_NUM; t++){
			if(stampType[t] != 0){
				printf("stampType[%hd] = %hd\n", t, stampType[t]);
			}
		}
		#endif
	}
	
	return 0;
}
