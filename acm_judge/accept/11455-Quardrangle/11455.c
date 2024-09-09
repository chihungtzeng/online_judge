#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}


int main(){
	int side[4];
	short nTest;
	char sequal, lequal; 
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d %d %d", side, side + 1, side+2, side+3);
		qsort(side, 4, sizeof(int),compareInt);
		sequal = (side[0] == side[1])? 1 : 0;
		lequal = (side[2] == side[3])? 1 : 0;
		if( (side[1] == side[2]) && lequal && sequal){
			puts("square");
		}
		else if(lequal && sequal){
			puts("rectangle");
		}
		else if(side[0] + side[1] + side[2] > side[3]){
			puts("quadrangle");
		}
		else{
			puts("banana");
		}
	}
	
	return 0;
}