#include <stdio.h>
#include <string.h>
#define LEN 101

short n, d, r;
short morning[LEN], night[LEN];

int compareShortInc(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int compareShortDec(const void *a, const void *b){
	return -compareShortInc(a, b);
}


int main(){
	short i;
	int nPay, tmp;
	while(3 == scanf("%hd %hd %hd", &n, &d, &r)){
		if(n == 0) break;
		for(i=0; i<n; i++){
			scanf("%hd", morning + i);
		}
		for(i=0; i<n; i++){
			scanf("%hd", night + i);
		}
		qsort(morning, n, sizeof(short), compareShortInc);
		qsort(night, n, sizeof(short), compareShortDec);
		for(i=0, nPay = 0; i<n; i++){
			tmp = morning[i] + night[i] - d;
			if(tmp > 0) nPay += tmp;
		}
		printf("%d\n", nPay * r);
	}
	
	return 0;
}