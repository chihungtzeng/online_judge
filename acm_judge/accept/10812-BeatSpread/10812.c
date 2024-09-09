#include <stdio.h>

long max(long a, long b){
	if (a < b) return b;
	else return a;
}
long min(long a, long b){
	if (a < b) return a;
	else return b;
}

int main(){
	long a, b, sum, diff,x,y;
	int nTest;
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%ld %ld", &sum, &diff);
		
		if ((sum + diff) % 2 != 0){
			printf("impossible\n");
		}
		else{
			a = (sum + diff) >> 1;
			b = sum - a;
			x = max(a, b);
			y = min(a, b);
			if(y < 0){
				printf("impossible\n");
			}
			else{
				printf("%ld %ld\n",x, y);
			}
		}
		
	}
	return 0;
}