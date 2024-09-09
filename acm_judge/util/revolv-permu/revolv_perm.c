#include <stdio.h>
#define MAX 10

int n, t;

int nextCombination(short c[], short n, short t, short *remove, short *add){
/*TAOCP Section 7.2.1.3*/
	short j;
	if((t % 2 == 1) && (c[1] + 1 < c[2])){
		*remove = c[1];
		c[1]++;
		*add = c[1];
		return 1;
	}
	else if ((t % 2 == 1) && (c[1] + 1 >= c[2])){
		j = 2;
		if(c[j] >= j){
			*remove = c[j];
			c[j] = c[j-1];
			c[j-1] = j - 2;
			*add = c[j-1];
			return 1;
		}
		else{
			j++;
		}
	}
	else if ((t % 2 == 0) && (c[1] > 0)){
		*remove = c[1];
		c[1]--;
		*add = c[1];
		return 1;
	}
	else if ((t % 2 == 0) && (c[1] <= 0)){
		j = 2;
	}
	
	while(j <= t){
		if(c[j] + 1 < c[j+1]){
			*remove = c[j-1];
			c[j-1] = c[j];
			c[j]++;
			*add = c[j];
			return 1;
		}
		j++;
	}
	return 0;
}

int main(){
	short c[MAX], i, add, remove;
	t = 3;
	n = 6;
	for(i=1; i<=t; i++){
		c[i] = i - 1;
	} 
	c[t+1] = n;
	add = -1;
	remove = -1;
	do {
		if(add >= 0){
			printf("remove %hd add %hd\n",remove, add);
		}
		for(i=1; i<=t; i++){
			printf("%hd ", c[i]);
		}
		printf("\n");
	}while(nextCombination(c, n, t, &remove, &add));
}