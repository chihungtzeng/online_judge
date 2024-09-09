#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
}

int main(){
	long long side[3];
	char nTest;
	
	scanf("%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%lld %lld %lld", side, side + 1, side + 2);
		qsort(side, 3, sizeof(long long), compareInt);
		if(side[0] <= 0){
			puts("Wrong!!");
		}
		else if (side[0] + side[1] <= side[2]){
			puts("Wrong!!");
		}
		else{
			puts("OK");
		}
	}	
	return 0;
}