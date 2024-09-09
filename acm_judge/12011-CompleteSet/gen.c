#include <stdio.h>
#include <stdlib.h>
#define NCASE 5
#define NNUM 100
#define MOD 262144

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int i, r, count, k;
	int num[NNUM], nNum;
	srand(time(NULL));
	printf("%d\n",NCASE);
	for(k=0; k<NCASE; k++){
		nNum = rand() % 100;
		for(i = nNum - 1; i>=0; i--){
			num[i] = rand() % MOD;
		}
		qsort(num, nNum, sizeof(int), compareInt);
		count = 1;
		for(i=1; i<nNum; i++){
			if(num[i] != num[i-1]) count++;
		}
		printf("%d\n%d", count, num[0]);
		for(i=1;i <nNum ; i++){
			if(num[i] != num[i-1]){
				printf(" %d", num[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}