#include <stdio.h>

int n, t;

int nextCombination(short list[], short n, short t){
	short j = 1;
	while(list[j] + 1 == list[j+1]){
		list[j] = j - 1;
		j++;
	}
	if(j > t) return 0;
	list[j]++;
	return 1;
}

int main(){
	short i, j, c[100];
	n = 6;
	t = 3;
	for(j=1; j<=t; j++){
		c[j] = j - 1;
	}
	c[t+1] = n;
	c[t+2] = 0;
	do{
		for(i=1; i<=t; i++){
			printf("%hd ", c[i]);
		}
		printf("\n");
	} while(nextCombination(c, n, t));
}