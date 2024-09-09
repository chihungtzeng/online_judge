#include <stdio.h>
#include <stdlib.h>

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int main(){
	short pay[3];
	char nTest, k=1;
	scanf("%hhd",&nTest);
	while(k <= nTest){
		scanf("%hd %hd %hd", pay, pay+1, pay+2);
		qsort(pay, 3, sizeof(short), compareShort);
		printf("Case %hhd: %hd\n",k++, pay[1]);
	}
	return 0;
}
