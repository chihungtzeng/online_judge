#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define UNDECIDE 0
#define INC 1
#define DEC 2

char solve(char beard[]){
	char nEqual = 0, nInc = 0, nDec = 0;
	char i, pre;
	for(i=1; i<MAX; i++){
		pre = beard[i-1];
		if(beard[i] == pre) ++nEqual;
		else if (beard[i] > pre) ++nInc;
		else ++nDec;
	} 
	if((nInc != 0) && (nDec != 0)) return UNDECIDE;
	else return INC;
}

int main(){
	char beard[MAX];
	char nTest, i;
	char state; 
	puts("Lumberjacks:");
	scanf("%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		for(i=0; i<MAX; i++){
			scanf("%hhd", beard + i);
		}
		state = solve(beard);
		if(state != UNDECIDE){
			puts("Ordered");
		}
		else{
			puts("Unordered");
		}
	}
	return 0;
}