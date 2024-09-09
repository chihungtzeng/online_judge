#include <stdio.h>
#include <stdlib.h>
#define MAXN 10001

struct Num{
	int value;
	int remainder;
};

int compareNum(const void *a, const void *b){
	struct Num *x, *y;
	short xmod2, ymod2, xeven, yeven;
	x = (struct Num *)a;
	y = (struct Num *)b;
	if (x->remainder < y->remainder) return -1;
	if (x->remainder > y->remainder) return 1;
	
	xmod2 = x->value % 2;
	ymod2 = y->value % 2;
	xeven = (xmod2 == 0)? 1 : 0;
	yeven = (ymod2 == 0)? 1 : 0;
	if (xeven != yeven){
		if(xeven == 0) return -1;
		else return 1;  
	}
	if (xeven == 0){
		/*x, and y are odd, the larger one goes first*/
		if (x->value > y->value) return -1;
		else return 1;
	}
	/*x, and y are even, the smaller one goes first*/
	if (x->value > y->value) return 1;
	else return -1;
}

int main(){
	short n, m, i;
	struct Num input[MAXN];
	while(1){
		scanf("%hd %hd", &n, &m);
		if((n == 0) && (m == 0)){
			printf("0 0\n");
			break;
		}
		for(i=n-1; i>=0; i--){
			scanf("%d", &input[i].value);
			input[i].remainder = input[i].value % m;
		}
		qsort(input, n, sizeof(struct Num), compareNum);
		printf("%hd %hd\n",n, m);
		for(i=0; i<n; i++){
			printf("%d\n",input[i].value);
		}
	}
	return 0;
}