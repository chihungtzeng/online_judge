#include <stdio.h>
#include <stdlib.h>

int compareLong(const void *a, const void *b){
	return *(long *)a - *(long *)b;
}

int main(){
	long side[3];
	short k = 1, nTest;	
	scanf("%hd", &nTest);
	while(k <= nTest){
		scanf("%ld %ld %ld",side, side+1, side+2);
		qsort(side, 3, sizeof(long),compareLong);
		if((side[0] <= 0) || (side[0] + side[1] <= side[2])){
			printf("Case %hd: Invalid\n",k++);
		}
		else if((side[0] == side[1]) && (side[1] == side[2])){
			printf("Case %hd: Equilateral\n",k++);
		}
		else if((side[0] == side[1]) || (side[1] == side[2])){
			printf("Case %hd: Isosceles\n",k++);
		}
		else {
			printf("Case %hd: Scalene\n",k++);
		}
	}
	return 0;
}